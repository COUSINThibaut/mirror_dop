/*
** EPITECH PROJECT, 2023
** my_strncat
** File description:
** my_strncat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int i = my_strlen(dest);
    int i2 = 0;
    int i3 = 0;

    while (i3 < nb && src[i2] != '\0') {
        dest[i] = src[i2];
        i++;
        i2++;
        i3++;
    }
    dest[i] = '\0';
    return dest;
}
