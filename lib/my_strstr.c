/*
** EPITECH PROJECT, 2024
** B-PSU-200-TLS-2-1-minishell2-tony.fournales
** File description:
** my_strstr
*/

#include <stdbool.h>
#include "all.h"

bool my_strstr(const char *buf, char c)
{
    while (*buf != '\0') {
        if (*buf == c) {
            return true;
        }
        buf++;
    }
    return false;
}
