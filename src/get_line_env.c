/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** get_line_env
*/

#include <stddef.h>
#include "../include/my.h"

int verif_line(char **env, char *name, int i, int len)
{
    int i2 = 0;
    int count = 0;
    int i3 = 0;

    for (; env[i][i3] != '='; i3++);
    if (i3 != len)
        return -1;
    while (env[i][i2] != '=') {
        if (env[i][i2] != name[i2])
            count++;
        i2++;
    }
    if (count == 0)
        return i;
    return -1;
}

int get_line_env(char **env, char *name)
{
    int i = 0;
    int len = my_strlen(name);

    while (env[i] != NULL) {
        if (verif_line(env, name, i, len) != -1)
            return i;
        i++;
    }
    return -1;
}
