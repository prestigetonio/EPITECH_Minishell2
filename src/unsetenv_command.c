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

static void free_oldenv(char **oldenv)
{
    for (int i = 0; oldenv[i] != NULL; i++) {
        free(oldenv[i]);
    }
    free(oldenv);
}

static char **add_var(char **oldenv, char *var)
{
    char **new_env = NULL;
    int i = 0;
    int len = 0;

    for (len = 0; oldenv[len] != NULL; len++);
    new_env = malloc(sizeof(char *) * (len + 2));
    for (i = 0; oldenv[i] != NULL; i++) {
        new_env[i] = my_strdup(oldenv[i]);
    }
    new_env[i] = my_strdup(var);
    new_env[i + 1] = NULL;
    free_oldenv(oldenv);
    return new_env;
}

int unsetenv_command(Env_t *env_s, char *tab, char **arg)
{
    char **new_env = NULL;
    int len = 0;
    int i = 0;

    if (arg[1] == NULL)
        return 0;
    for (len = 0; env_s->newenv[len] != NULL; len++);
    new_env = malloc(sizeof(char *) * 1);
    new_env[0] = NULL;
    for (i = 0; env_s->newenv[i] != NULL; i++) {
        if (my_strncmp(env_s->newenv[i], arg[1], my_strlen(arg[1])) != 0) {
            new_env = add_var(new_env, env_s->newenv[i]);
        }
    }
    free_oldenv(env_s->newenv);
    env_s->newenv = new_env;
    return 0;
}
