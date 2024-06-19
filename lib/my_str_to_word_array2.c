/*
** EPITECH PROJECT, 2024
** B-PSU-200-TLS-2-1-bsminishell1-tony.fournales
** File description:
** my_str_to_word_array.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "all.h"

int is_separator2(char c)
{
    if (c == ':') {
        return 1;
    } else {
        return 0;
    }
}

int compt_words2(char *str)
{
    int compt = 0;
    int letter_before = 0;
    int i = 0;

    for (i = 0; str[i] != '\0'; i++) {
        if (is_separator2(str[i]) == 1) {
            letter_before = 1;
        }
        if (is_separator2(str[i]) == 0 && letter_before == 1) {
            compt++;
            letter_before = 0;
        }
    }
    if (is_separator2(str[i]) == 0)
        compt++;
    return compt;
}

char **second_malloc2(char *str, int nb_letter, char **tab, int indice)
{
    int i = 0;

    if (nb_letter > 0 && is_separator2(str[i]) == 0) {
        tab[indice] = malloc(sizeof(char) * (nb_letter + 1));
        tab[indice][nb_letter] = '\0';
    }
    return 0;
}

char **malloc_tab2(char *str)
{
    int compt = compt_words2(str);
    char **tab = malloc(sizeof(char *) * (compt + 1));
    int nb_letter = 0;
    int indice = 0;
    int i = 0;

    tab[compt] = NULL;
    for (i = 0; str[i] != '\0'; i++) {
        if (is_separator2(str[i]) == 0) {
            nb_letter++;
        }
        if (is_separator2(str[i]) == 1 && nb_letter != 0) {
            tab[indice] = malloc(sizeof(char) * (nb_letter + 1));
            tab[indice][nb_letter] = '\0';
            nb_letter = 0;
            indice++;
        }
    }
    second_malloc2(str, nb_letter, tab, indice);
    return tab;
}

char **my_str_to_word_array2(char *str)
{
    char **tab = malloc_tab2(str);
    int y = 0;
    int j = 0;
    int letter_before = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (is_separator2(str[i]) == 0) {
            tab[j][y] = str[i];
            y++;
            letter_before = 0;
        }
        if (is_separator2(str[i]) == 1 && y > 0)
            letter_before = 1;
        if (is_separator2(str[i]) == 1 && letter_before == 1) {
            j++;
            y = 0;
        }
    }
    return tab;
}
