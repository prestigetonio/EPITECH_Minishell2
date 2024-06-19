/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell2-tony.fournales
** File description:
** clean.c
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "all.h"
#include "my_printf.h"

void clean_cd(Env_t *env_s)
{
    free(env_s->oldpwd);
    free(env_s->pwd);
}
