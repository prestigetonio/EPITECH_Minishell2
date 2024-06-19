/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-tony.fournales
** File description:
** exit_minishell.c
*/

#include <stdlib.h>
#include "all.h"
#include "my_printf.h"

int leave_terminal(char **arg, char *buf, Env_t *env_s)
{
    my_printf("%s\n", "exit");
    for (int i = 0; env_s->newenv[i] != NULL; i++)
        free(env_s->newenv[i]);
    free(env_s->newenv);
    free(env_s->path);
    exit(EXIT_SUCCESS);
    return 0;
}
