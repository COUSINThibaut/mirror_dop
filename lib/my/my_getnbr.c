/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** my_getnbr
*/

#include "my.h"
#include <stdlib.h>

int my_getnbr(char const *str)
{
    int isave = 0;
    int i = 0;
    int moin = 0;
    int mult = 1;
    int nb = 0;

    if (str[i] == '-')
        moin++;
    for (; (str[i] < 48 || str[i] > 57) && (str[i] != '\0'); i++);
    if (str[i] == '\0')
        return -1;
    isave = i;
    for (; str[i + 1] >= 48 && str[i + 1] <= 57; i++);
    for (; i >= isave; i--) {
        nb += (str[i] - 48) * mult;
        mult *= 10;
    }
    if (moin != 0)
        nb *= -1;
    return nb;
}
