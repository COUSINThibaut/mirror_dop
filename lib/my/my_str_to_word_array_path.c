/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/
#include "my.h"
#include <stdlib.h>

int alphanum1(char c)
{
    if (c == 58 || c == 61) {
        return 0;
    } else
        return 1;
}

int wordlen1(char const *str, int nb)
{
    int i = 0;
    int i2 = 0;

    if (nb > 0)
        i = nb;
    while (alphanum1(str[i]) != 0 && str[i] != '\0') {
        i2++;
        i++;
    }
    return i2;
}

int nbrword1(char *str)
{
    int i = 0;
    int na = 0;

    while (str[i] != '\0') {
        if (alphanum1(str[i]) == 0)
            na++;
        i++;
    }
    na++;
    return na;
}

char **my_str_to_word_array_path(char *str, char *cmd)
{
    char **tab = malloc(sizeof(char *) * (nbrword1(str)) + sizeof(NULL));
    char *strtp;
    int nb = 0;
    int nb2 = 0;
    int i2 = 0;

    for (; i2 < nbrword1(str); i2++) {
        strtp = malloc(sizeof(char) * wordlen1(str, nb2) + 1);
        nb = wordlen1(str, nb2);
        for (int i = 0; i < nb; i++) {
            strtp[i] = str[nb2];
            nb2++;
            strtp[i + 1] = '\0';
        }
        tab[i2] = strtp;
        nb++;
        nb2++;
    }
    tab[i2] = NULL;
    return (tab);
}
