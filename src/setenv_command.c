/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell2-tony.fournales
** File description:
** cd_command.c
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "all.h"
#include "my_printf.h"

char *repalce_var(char **arg)
{
    char *new_v = NULL;

    new_v = malloc(sizeof(char) * (my_strlen(arg[1]) + my_strlen(arg[2]) + 2));
    my_strcpy(new_v, arg[1]);
    my_strcat(new_v, "=");
    my_strcat(new_v, arg[2]);
    return new_v;
}

void free_oldenv(Env_t *env_s)
{
    for (int i = 0; env_s->newenv[i] != NULL; i++) {
        free(env_s->newenv[i]);
    }
    free(env_s->newenv);
}

void add_var(Env_t *env_s, char **arg)
{
    char **new_env = NULL;
    int i = 0;
    int len = 0;

    for (len = 0; env_s->newenv[len] != NULL; len++);
    new_env = malloc(sizeof(char *) * (len + 2));
    for (i = 0; env_s->newenv[i] != NULL; i++) {
        new_env[i] = my_strdup(env_s->newenv[i]);
    }
    new_env[i] = repalce_var(arg);
    new_env[i + 1] = NULL;
    free_oldenv(env_s);
    env_s->newenv = new_env;
    return;
}

int check_alphanum(char **arg)
{
    if (arg[1][0] >= '0' && arg[1][0] <= '9') {
        my_printf("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    for (int i = 0; arg[1][i] != '\0'; i++) {
        if (arg[1][i] < 48 || (arg[1][i] > 57 && arg[1][i] < 65) ||
        (arg[1][i] > 90 && arg[1][i] < 97) || arg[1][i] > 122) {
            my_printf("setenv: Variable name must contain ");
            my_printf("alphanumeric characters.\n");
            return 1;
        }
    }
    return 0;
}

int setenv_command(Env_t *env_s, char *tab, char **arg)
{
    int placed = 0;

    if (arg[1] == NULL) {
        env_command(env_s, tab, arg);
        return 0;
    }
    if (check_alphanum(arg) == 1)
        return 0;
    if (arg[2] == NULL)
        arg[2] = " ";
    for (int i = 0; env_s->newenv[i] != NULL; i++) {
        if (my_strncmp(env_s->newenv[i], arg[1], my_strlen(arg[1])) == 0) {
            free(env_s->newenv[i]);
            env_s->newenv[i] = repalce_var(arg);
            placed = 1;
        }
    }
    if (placed == 0)
        add_var(env_s, arg);
    return 0;
}
