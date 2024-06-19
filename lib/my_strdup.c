/*
** EPITECH PROJECT, 2023
** B-PSU-100-TLS-1-1-myls-tony.fournales
** File description:
** my_strdup.c
*/

#include "all.h"
#include <stdlib.h>

char *my_strdup(const char *str)
{
    int len;
    char *dup;

    len = my_strlen(str) + 1;
    dup = malloc(sizeof(char) * len);
    if (dup == NULL)
        return (NULL);
    dup = my_strcpy(dup, str);
    dup[len - 1] = '\0';
    return (dup);
}
