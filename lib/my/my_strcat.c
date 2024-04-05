/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** task11
*/

#include "my.h"

char *my_strcat(char *dest, const char *src)
{
    int i = my_strlen(dest);
    int i2 = 0;

    while (src[i2] != '\0') {
        dest[i] = src[i2];
        i++;
        i2++;
    }
    dest[i] = '\0';
    return dest;
}
