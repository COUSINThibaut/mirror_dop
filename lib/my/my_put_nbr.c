/*
** EPITECH PROJECT, 2023
** my_put_nbr
** File description:
** task07 day03
*/
#include "my.h"

int my_put_nbr(int nb)
{
    int div = 1000000000;
    int res = 0;
    int nb2 = nb;

    if (nb == 0)
        my_putchar('0');
    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    while (div > 0) {
        res = nb2 / div;
        if (res < 1)
            nb2 = nb;
        if (res >= 1) {
            my_putchar(res + '0');
            nb2 = nb2 - (div * res);
        }
        div = div / 10;
    }
}
