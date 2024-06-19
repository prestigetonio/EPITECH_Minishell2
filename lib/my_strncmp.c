/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-minishell1-tony.fournales
** File description:
** my_strncmp.c
*/

int my_strncmp(char const *part1, char const *part2, int n)
{
    for (int i = 0; i < n; i++) {
        if (*part1 != *part2) {
            return (*part1 < *part2) ? -1 : 1;
        }
        if (*part1 == '\0') {
            return 0;
        }
        part1++;
        part2++;
    }
    return 0;
}
