/*
** EPITECH PROJECT, 2024
** B-PSU-200-TLS-2-1-minishell2-tony.fournales
** File description:
** separator
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

void check_separator(Env_t *env_s, char **arg, char *buf, char **env)
{
    char **tab = NULL;

    if (my_strstr(buf, ';')) {
        tab = strtok_separteur(buf);
        for (int i = 0; tab[i] != NULL; i++) {
            choice_command(env_s, arg, tab[i], env);
        }
    } else {
        choice_command(env_s, arg, buf, env);
    }
}
