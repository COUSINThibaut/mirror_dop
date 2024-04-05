/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** task13
*/
#include <stdlib.h>
#include "my.h"

char *my_strdup(const char *src)
{
    char *str = malloc(sizeof(char) * my_strlen(src) + 1);

    my_strcpy(str, src);
    return str;
}
