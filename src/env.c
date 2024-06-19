/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell2-tony.fournales
** File description:
** env.c
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "all.h"
#include "my_printf.h"

int env_command(Env_t *env_s, char *tab, char **arg)
{
    for (int y = 0; env_s->newenv[y] != NULL; y++) {
        my_printf("%s\n", env_s->newenv[y]);
    }
    return 0;
}
