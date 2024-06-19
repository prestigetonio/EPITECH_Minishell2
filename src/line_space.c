/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-tony.fournales
** File description:
** line_space.c
*/

#include <stdlib.h>
#include <string.h>
#include "all.h"
#include "my_printf.h"

char *spaces_before(char *buf)
{
    while (*buf == ' ' || *buf == '\t' || *buf == '\r' || *buf == '\a') {
        buf++;
    }
    return buf;
}

char *remove_bn(char *str)
{
    char *temp = NULL;
    int len = my_strlen(str);
    int i = 0;

    temp = malloc(sizeof(char) * (len + 1));
    if (str[len - 1] == '\n') {
        for (; i != len - 1; i++) {
            temp[i] = str[i];
        }
        temp[i] = '\0';
        str = my_strdup(temp);
        return str;
    } else {
        return str;
    }
}

char **strtok_separteur(char *buf)
{
    char *token = NULL;
    int i = 0;
    char **tab = NULL;

    tab = malloc(sizeof(char *) * (my_strlen(buf) + 1));
    token = strtok(buf, ";");
    while (token != NULL) {
        tab[i] = token;
        i++;
        token = strtok(NULL, ";");
    }
    tab[i] = NULL;
    return tab;
}

char **strtok_check(Env_t *env_s, char **arg, char *buf, char **env)
{
    char *token = NULL;
    int i = 0;
    char **tab = NULL;

    tab = malloc(sizeof(char *) * (my_strlen(buf) + 1));
    token = strtok(buf, " \t\r\n\a");
    while (token != NULL) {
        tab[i] = token;
        i++;
        token = strtok(NULL, " \t\r\n\a");
    }
    tab[i] = NULL;
    return tab;
}
