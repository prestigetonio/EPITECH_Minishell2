/*
** EPITECH PROJECT, 2023
** print
** File description:
** print
*/

#include "all.h"
#include <unistd.h>

int my_putchar(char l)
{
    write(1, &l, 1);
    return 0;
}
