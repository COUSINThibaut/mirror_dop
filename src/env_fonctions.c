/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** env_fonctions
*/

#include <sys/wait.h>
#include "../include/my.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static char **cpy_tab_env_plus(char **env, char *new_elem)
{
    int i = 0;
    char **cpy_env;

    for (; env[i] != NULL; i++);
    i++;
    cpy_env = malloc(sizeof(char *) * i + sizeof(NULL));
    i = 0;
    for (; env[i] != NULL; i++)
        cpy_env[i] = my_strdup(env[i]);
    cpy_env[i] = my_strdup(new_elem);
    cpy_env[i + 1] = NULL;
    return cpy_env;
}


char *concat_arg_setenv(char **arg, int nb_arg)
{
    char *arg1;
    int len = 0;

    if (nb_arg == 2) {
        len = (my_strlen(arg[1]) + my_strlen(arg[2]));
        arg1 = malloc(sizeof(char) * len + 2);
        arg1[0] = '\0';
        my_strcat(arg1, arg[1]);
        my_strcat(arg1, my_strdup("="));
        my_strcat(arg1, arg[2]);
    }
    if (nb_arg == 1) {
        arg1 = malloc(sizeof(char) * my_strlen(arg[1]) + 2);
        arg1[0] = '\0';
        my_strcat(arg1, arg[1]);
        my_strcat(arg1, my_strdup("="));
    }
    return arg1;
}

char **my_setenv_case(char **env_cpy, char **arg, int line)
{
    if (line != -1) {
        env_cpy[line] = malloc(sizeof(char) * my_strlen(arg[1]) + 1);
        env_cpy[line] = my_strcat(env_cpy[line], arg[1]);
    }
    if (line == -1)
        env_cpy = cpy_tab_env_plus(env_cpy, arg[1]);
    return env_cpy;
}

char **my_setenv(char **env_cpy, char **arg)
{
    int len_element;
    int nb_arg = count_args(arg);
    int line;

    if (nb_arg == 0) {
        my_show_word_array(env_cpy);
        return env_cpy;
    }
    line = get_line_env(env_cpy, arg[1]);
    arg[1] = concat_arg_setenv(arg, nb_arg);
    len_element = my_strlen(arg[1]);
    env_cpy = my_setenv_case(env_cpy, arg, line);
    return env_cpy;
}

static char **cpy_tab_env_moin(char **env, int line)
{
    int i = 0;
    int i2 = 0;
    char **cpy_env;

    for (; env[i] != NULL; i++);
    cpy_env = malloc(sizeof(char *) * (i - 1) + sizeof(NULL));
    i = 0;
    for (; env[i] != NULL; i++) {
        if (i == line)
            continue;
        cpy_env[i2] = my_strdup(env[i]);
        i2++;
    }
    cpy_env[i2] = NULL;
    return cpy_env;
}

char **my_unsetenv(char **env_cpy, char **arg)
{
    int line;
    int i = 1;

    while (arg[i] != NULL) {
        line = get_line_env(env_cpy, arg[i]);
        if (line == -1)
            return env_cpy;
        env_cpy = cpy_tab_env_moin(env_cpy, line);
        i++;
    }
    return env_cpy;
}
