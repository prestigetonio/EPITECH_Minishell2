/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-tony.fournales
** File description:
** minishell.c
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>
#include <string.h>
#include "all.h"
#include "my_printf.h"

static machin_t my_functions[5] = {
    {"env", &env_command},
    {"unsetenv", &unsetenv_command},
    {"cd", &cd_command},
    {"setenv", &setenv_command},
    {"exit", &leave_terminal},
};

char *buffer_all(void)
{
    size_t size = 2048;
    char *buf = malloc(sizeof(char) * size);
    int tty = 0;

    tty = isatty(0);
    if (buf == NULL) {
        perror("ERROR MALLOC");
        return 84;
    }
    if (tty == 1)
        my_printf("%s", "$> ");
    return buf;
}

char *cut_path(Env_t *env_s, char *buf)
{
    int i;
    char *str;
    char **tab = my_str_to_word_array2(env_s->path);

    for (i = 0; tab[i] != NULL; i++) {
        str = malloc(sizeof(char) * \
        (my_strlen(tab[i]) + (my_strlen(buf)) + 2));
        str = my_strcpy(str, tab[i]);
        str = my_strcat(str, "/");
        str = my_strcat(str, buf);
        if (access(str, X_OK) == 0) {
            return str;
        }
        free(str);
    }
    return "";
}

static int execute_commands(char **arg, char **tab, Env_t *env_s)
{
    char *test = cut_path(env_s, tab[0]);

    if (my_strcmp(test, "") != 0) {
        execve(test, tab, env_s->newenv);
    } else {
        return -1;
    }
    return 0;
}

int check_commands(char **arg, char **tab, Env_t *env_s)
{
    for (int i = 0; i < 4; i++) {
        if (my_strcmp(tab[0], my_functions[i].function_name) == 0) {
            return my_functions[i].function_pointer(env_s, tab[0], tab);
        }
    }
    return 1;
}

static void execute_error(char **arg, char **tab, Env_t *env_s)
{
    if (execute_commands(arg, tab, env_s) == -1) {
        my_printf("%s: Command not found.\n", tab[0]);
        exit(EXIT_FAILURE);
    }
}

static void command_exec(char **arg, char **tab, char *buf, Env_t *env_s)
{
    pid_t p = fork();
    int return_value = 0;

    if (p == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (p == 0) {
        execute_error(arg, tab, env_s);
    } else {
        waitpid(p, &return_value, 0);
    }
}

void choice_command(Env_t *env_s, char **arg, char *buf, char **env)
{
    char **tab = NULL;

    if (buf[0] == '\n') {
        return;
    }
    if (buf[1] == '\n') {
        return;
    }
    tab = strtok_check(env_s, arg, buf, env);
    if (check_commands(arg, tab, env_s) != 0) {
        command_exec(arg, tab, buf, env_s);
    }
}

static int prefix_command(Env_t *env_s, char **arg, char **env)
{
    char *buf = NULL;
    size_t size = 2048;
    int tty = 0;

    buf = buffer_all();
    if (buf == NULL)
        return 84;
    while (getline(&buf, &size, stdin) > 0) {
        tty = isatty(0);
        buf = spaces_before(buf);
        if (buf[0] == '\n') {
            check_tty(tty);
            continue;
        }
        check_separator(env_s, arg, buf, env);
        check_tty(tty);
    }
    return 0;
}

void minishell(char **arg, char **env)
{
    Env_t *env_s = malloc(sizeof(Env_t));

    init_struct(env_s, env);
    init_path(env_s);
    init_home(env_s);
    init_pwd(env_s);
    prefix_command(env_s, arg, env);
    free(env_s);
}
