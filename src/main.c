/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-tony.fournales
** File description:
** main.c
*/

#include <stdio.h>
#include <stddef.h>
#include "all.h"
#include "my_printf.h"

int main(int argc, char **argv, char **env)
{
    if (argc != 1) {
        my_printf("%s\n", "Usage : ./mysh");
        return 84;
    } else {
        minishell(argv, env);
    }
    return 84;
}
