/*
** EPITECH PROJECT, 2023
** my_show_word_array
** File description:
** my_show_word_array
*/

#include "my.h"
#include <stdlib.h>

int my_show_word_array(char *const *tab)
{
    int i = 0;

    while (tab[i] != NULL) {
        my_putstr(tab[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}
