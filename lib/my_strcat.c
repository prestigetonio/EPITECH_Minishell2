/*
** EPITECH PROJECT, 2023
** my_strcat.c
** File description:
** emacs
*/

#include "all.h"

char *my_strcat(char *dest, const char *src)
{
    int i = my_strlen(dest);
    int j = 0;

    while (src[j] != '\0') {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
    return dest;
}
