/*
** EPITECH PROJECT, 2023
** B-PSU-100-TLS-1-1-myls-tony.fournales
** File description:
** my_strcpy.c
*/

#include "all.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
