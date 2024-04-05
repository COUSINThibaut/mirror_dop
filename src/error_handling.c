/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** error handling
*/

#include <unistd.h>
#include <stddef.h>
#include "../include/my.h"
#include <fcntl.h>
#include <sys/stat.h>

int error_handling_path(char *path)
{
    struct stat s;
    int rtrn;

    rtrn = stat(path, &s);
    if (rtrn == -1) {
        my_putstr(path);
        my_putstr(": No such file or directory.\n");
        return 1;
    }
    if (!(s.st_mode & S_IROTH)) {
        my_putstr(path);
        my_putstr(": Permission denied.\n");
        return 1;
    }
    if (!(s.st_mode & S_IFDIR)) {
        my_putstr(path);
        my_putstr(": Not a directory.\n");
        return 1;
    }
    return 0;
}

int error_handling_cd(char **arg, int nb)
{
    if (arg[1] == NULL)
        return 0;
    if (nb != 1)
        return 1;
    if ((my_strcmp(arg[1], "~") == 0) ||
        (my_strcmp(arg[1], "-") == 0) ||
        (my_strcmp(arg[1], "/") == 0))
        return 0;
    if (error_handling_path(arg[1]) == 1)
        return 1;
    return 0;
}

static int is_alphanum(char c)
{
    int i = 0;

    if (c >= 48 && c <= 57)
        i++;
    if (c >= 65 && c <= 90)
        i++;
    if (c >= 97 && c <= 122)
        i++;
    if (i == 0) {
        return 0;
    } else
        return 1;
}

int error_setenv(char *name, int nb)
{
    int i = 1;

    if (!((name[0] >= 'a' && name[0] <= 'z') ||
        (name[0] >= 'A' && name[0] <= 'Z'))) {
        my_putstr("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    while (name[i] != '\0') {
        if (is_alphanum(name[i]) == 0) {
            my_putstr("setenv: Variable name must ");
            my_putstr("contain alphanumeric characters.\n");
            return 1;
        }
        i++;
    }
    return 0;
}

int error_nb_argument_setenv(char **arg, int nb)
{
    if (nb == 0)
        return 0;
    if (nb > 2) {
        my_putstr("setenv: Too many arguments.\n");
        return 1;
    }
    if (error_setenv(arg[1], nb) == 1)
        return 1;
}

int error_handling(char **arg)
{
    int nb = count_args(arg);

    if (my_strcmp(arg[0], "setenv") == 0)
        return (error_nb_argument_setenv(arg, nb));
    if (my_strcmp(arg[0], "unsetenv") == 0)
        if (nb < 1) {
            my_putstr("unsetenv: Too few arguments.\n");
            return 1;
        }
    if (my_strcmp(arg[0], "env") == 0)
        if (nb > 1)
            return 1;
    if (my_strcmp(arg[0], "cd") == 0)
        if (error_handling_cd(arg, nb) == 1)
            return 1;
    return 0;
}
