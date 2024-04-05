/*
** EPITECH PROJECT, 2023
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "my.h"
#include <stdlib.h>

int alphanum2(char c)
{
    if (c == '|' || c == ';' || c == '<' || c == '>')
        return 0;
    return 1;
}

int wordlen2(char const *str, int nb)
{
    int i = 0;
    int i2 = 0;

    if (nb > 0)
        i = nb;
    while (alphanum2(str[i]) != 0 && str[i] != '\0') {
        i2++;
        i++;
    }
    return i2;
}

int nbrword2(char *str)
{
    int i = 0;
    int na = 0;

    while (str[i] != '\0') {
        if (alphanum2(str[i]) == 0)
            na++;
        i++;
    }
    na++;
    return na;
}

char **my_str_to_word_cmd_array(char *str)
{
    char **tab = malloc(sizeof(char *) * (nbrword2(str)) + sizeof(NULL));
    char *strtp;
    int nb = 0;
    int nb2 = 0;
    int i2 = 0;

    for (; i2 < nbrword2(str); i2++) {
        strtp = malloc(sizeof(char) * wordlen2(str, nb2) + 1);
        nb = wordlen2(str, nb2);
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
