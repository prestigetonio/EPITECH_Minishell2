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

static void update_env(Env_t *env_s)
{
    char *pwd = NULL;
    char *oldpwd = NULL;
    char *cwd = NULL;

    cwd = getcwd(cwd, 0);
    pwd = malloc(sizeof(char) * (my_strlen(cwd) + 5));
    pwd = my_strcpy(pwd, "PWD=");
    pwd = my_strcat(pwd, cwd);
    oldpwd = malloc(sizeof(char) * (my_strlen(env_s->oldpwd) + 8));
    oldpwd = my_strcpy(oldpwd, "OLDPWD=");
    oldpwd = my_strcat(oldpwd, env_s->oldpwd);
    for (int i = 0; env_s->newenv[i] != NULL; i++) {
        if (my_strncmp(env_s->newenv[i], "PWD=", 4) == 0) {
            free(env_s->newenv[i]);
            env_s->newenv[i] = my_strdup(pwd);
        }
        if (my_strncmp(env_s->newenv[i], "OLDPWD=", 7) == 0) {
            free(env_s->newenv[i]);
            env_s->newenv[i] = my_strdup(oldpwd);
        }
    }
}

static void update_pwd(Env_t *env_s, char *arg)
{
    char cwd[1024];
    char newcwd[1024];

    if (getcwd(cwd, sizeof(cwd)) == NULL) {
        return;
    }
    if (chdir(arg) != 0) {
        my_printf("%s: Not a directory.\n", arg);
        return;
    }
    free(env_s->oldpwd);
    env_s->oldpwd = my_strdup(cwd);
    env_s->pwd = my_strdup(arg);
    update_env(env_s);
}

int cd_command(Env_t *env_s, char *tab, char **arg)
{
    if (arg[1] == NULL || my_strcmp(arg[1], "~") == 0) {
        arg[1] = env_s->home;
    }
    if (env_s->oldpwd != NULL && my_strcmp(arg[1], "-") == 0) {
        arg[1] = env_s->oldpwd;
    }
    update_pwd(env_s, arg[1]);
    return 0;
}
