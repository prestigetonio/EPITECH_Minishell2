/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** emacs
*/

#ifndef MY
    #define MY

typedef struct Env {
    char **newenv;
    char *path;
    char *pwd;
    char *oldpwd;
    char *home;
} Env_t;

typedef struct machin_s {
    const char *function_name;
    int (*function_pointer)(Env_t *, char *, char **);
} machin_t;

int cd_command(Env_t *env_s, char *tab, char **arg);
int env_command(Env_t *env_s, char *tab, char **arg);
int leave_terminal(char **arg, char *buffer, Env_t *env_s);
void check_separator(Env_t *env_s, char **arg, char *buf, char **env);
void choice_command(Env_t *env_s, char **arg, char *buf, char **env);
char *cut_path(Env_t *env_s, char *buf);
char **strtok_check(Env_t *env_s, char **arg, char *buf, char **env);
void clean_cd(Env_t *env_s);
void check_tty(int tty);
char *handle_path(Env_t *env_s, char **arg);
int simple_echo(char **arg, char *buffer);
char *spaces_before(char *buffer);
char *remove_bn(char *str);
void init_path(Env_t *env_s);
void init_pwd(Env_t *env_s);
void init_home(Env_t *env_s);
void init_struct(Env_t *env_s, char **env);
void minishell(char **arg, char **env);
void print_arg(char **arg);
char **my_str_to_word_array2(char *str);
char **my_str_to_word_array(char *str);
int my_strlen(char const *str);
int my_put_nbr(int nb);
unsigned int my_put_nbru(unsigned int nb);
int my_putchar(char l);
int my_sort_alpha(int argc, char argv, char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_strncmp(char const *part1, char const *part2, int n);
int my_strcmp(const char *str, const char *str2);
char *my_strdup(const char *str);
char *my_strcat(char *dest, char const *src);
int setenv_command(Env_t *env_s, char *tab, char **arg);
int unsetenv_command(Env_t *env_s, char *tab, char **arg);

#endif
