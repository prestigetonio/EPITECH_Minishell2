/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** string
*/

#include "all.h"

int my_putstr(char const *str)
{
    int cpt = 0;

    while (str[cpt] != '\0') {
        my_putchar(str[cpt]);
        cpt++;
    }
    return 0;
}
