/*
** EPITECH PROJECT, 2024
** B-PSU-200-TLS-2-1-minishell1-tony.fournales
** File description:
** my_strcmp
*/

int my_strcmp(char *str, char *str2)
{
    int i = 0;

    while (str[i] == str2[i]) {
        if (str[i] == '\0' && str2[i] == '\0')
            return 0;
        i++;
    }
    return (str[i] - str2[i]);
}
