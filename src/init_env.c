/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-tony.fournales
** File description:
** init_env.c
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include "all.h"
#include "my_printf.h"

void init_pwd(Env_t *env_s)
{
    char cwd[1024];

    if (getcwd(cwd, sizeof(char) * 1024) != NULL) {
        env_s->pwd = my_strdup(cwd);
        env_s->oldpwd = my_strdup(cwd);
    } else {
        perror("Failed to get current working directory");
        exit(EXIT_FAILURE);
    }
}

void init_home(Env_t *env_s)
{
    for (int i = 0; env_s->newenv[i] != NULL; i++) {
        if (my_strncmp(env_s->newenv[i], "HOME=", 5) == 0) {
            env_s->home = malloc(sizeof(char) * \
            (my_strlen(env_s->newenv[i]) - 4));
            my_strcpy(env_s->home, (env_s->newenv[i] + 5));
        }
    }
    return;
}

void init_struct(Env_t *env_s, char **env)
{
    int size = 0;
    int i = 0;

    for (; env[size] != NULL; size++);
    env_s->newenv = malloc(sizeof(char *) * (size + 1));
    for (; env[i] != NULL; i++) {
        env_s->newenv[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1));
        my_strcpy(env_s->newenv[i], env[i]);
    }
    env_s->newenv[i] = NULL;
    return;
}

static void init_path2(Env_t *env_s)
{
    for (int i = 0; env_s->newenv[i] != NULL; i++) {
        if (my_strncmp(env_s->newenv[i], "PWD=", 4) == 0) {
            env_s->pwd = malloc(sizeof(char) * \
            (my_strlen(env_s->newenv[i]) - 3));
            my_strcpy(env_s->pwd, (env_s->newenv[i] + 4));
        }
        if (my_strncmp(env_s->newenv[i], "OLDPWD=", 7) == 0) {
            env_s->oldpwd = malloc(sizeof(char) * \
            (my_strlen(env_s->newenv[i]) - 6));
            my_strcpy(env_s->oldpwd, (env_s->newenv[i] + 7));
        }
        if (my_strncmp(env_s->newenv[i], "HOME=", 5) == 0) {
            env_s->home = malloc(sizeof(char) * \
            (my_strlen(env_s->newenv[i]) - 4));
            my_strcpy(env_s->home, (env_s->newenv[i] + 5));
        }
    }
}

void init_path(Env_t *env_s)
{
    for (int i = 0; env_s->newenv[i] != NULL; i++) {
        if (my_strncmp(env_s->newenv[i], "PATH=", 5) == 0) {
            env_s->path = malloc(sizeof(char) * \
            (my_strlen(env_s->newenv[i]) - 4));
            my_strcpy(env_s->path, (env_s->newenv[i] + 5));
        }
    }
    init_path2(env_s);
    return;
}

void check_tty(int tty)
{
    if (tty == 1)
        my_printf("%s", "$> ");
}
