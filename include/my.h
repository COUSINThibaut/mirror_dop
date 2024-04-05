/*
** EPITECH PROJECT, 2023
** my_h
** File description:
** my_h
*/

#include <stdarg.h>
#include "minishell.h"

#ifndef MY_H_
    #define MY_H_

char **pipes_exec(char **env_cpy, cmd_t *cmd, int i);
char **right_redirection(char **env_cpy, cmd_t *cmd, int i);
char **verif_error_exec(char **env_cpy, char *buf, int fd);
char **my_str_to_word_cmd_array(char *str);
cmd_t init_cmd(char *buf);
int exec_cmd(char *av, char **env, int fd);
int error_handling(char **arg);
char *verif_command(char *arg);
char *clean_str(char *str);
int count_args(char **arg);
char **my_setenv(char **env_cpy, char **arg);
char **my_unsetenv(char **env_cpy, char **arg);
char **cd_fonct(char **env, char **arg);
int get_line_env(char **env, char *name);
void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
void my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char *, char const *);
int my_strcmp(char const *, char *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
char *my_strdup(char const *);
void my_show_word_array(char **env);
char **my_str_to_word_array(char *arg);
char **my_str_to_word_array_path(char *arg);

#endif /* MY_H_ */
