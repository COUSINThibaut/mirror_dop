/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** clean_str
*/

#include <stdio.h>
#include <stdlib.h>
#include "../include/my.h"

char *remove_last_space(char *str_cpy, int i2)
{
    int i = 0;
    int len = my_strlen(str_cpy);
    char *str = malloc(sizeof(char) * len);

    if (str_cpy[i2 - 1] != ' ' && str_cpy[i2 - 1] != '\t')
        return str_cpy;
    while (str_cpy[i + 1] != '\0') {
        str[i] = str_cpy[i];
        i++;
    }
    str[i] = '\0';
    return str;
}

int skip_space(char *str, int i)
{
    for (; (str[i] == ' ' || str[i] == '\t') && str[i] != '\0'; i++);
    return i;
}

int strlen_clean(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'))
        i++;
    while (str[i] != '\0') {
        if (str[i] != ' ') {
            count++;
            i++;
        }
        if (str[i] == ' ') {
            i = skip_space(str, i);
            count++;
        }
    }
    return count;
}

char *clean_str(char *str)
{
    int i = 0;
    int i2 = 0;
    char *str_cpy = malloc(sizeof(char) * strlen_clean(str) + 1);

    for (; str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'); i++);
    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t') {
            str_cpy[i2] = str[i];
            i2++;
            i++;
        }
        if (str[i] == ' ' || str[i] == '\t') {
            i = skip_space(str, i);
            str_cpy[i2] = ' ';
            i2++;
        }
    }
    str_cpy[i2] = '\0';
    return remove_last_space(str_cpy, i2);
}
