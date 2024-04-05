/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** error handling commande
*/

#include <stdlib.h>
#include "../include/my.h"

int nb_slash(char *arg)
{
    int i = 0;
    int count = 0;

    while (arg[i] != '\0') {
        if (arg[i] == '/')
            count++;
        i++;
    }
    return count;
}

int get_i(int count_save, char *arg)
{
    int i = 0;
    int count = 0;

    for (; count < count_save; i++) {
        if (arg[i] == '/')
            count++;
    }
    return i;
}

char *verif_command(char *arg)
{
    int i = 0;
    int count = 0;
    char *str;
    int i2 = 0;
    int i_save = 0;

    count = nb_slash(arg);
    if (count == 0)
        return arg;
    i = get_i(count, arg);
    i_save = i;
    for (; arg[i] != '\0'; i++);
    str = malloc(sizeof(char) * i - i_save + 1);
    for (; arg[i_save] != '\0'; i2++) {
        str[i2] = arg[i_save];
        i_save++;
    }
    str[i2] = '\0';
    return str;
}
