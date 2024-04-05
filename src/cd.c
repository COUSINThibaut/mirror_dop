/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** cd
*/

#include "../include/my.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static char **replace_oldpwd(char **env_cpy, char *path)
{
    char *oldpwd = my_strdup("OLDPWD=");
    int line = get_line_env(env_cpy, "OLDPWD");

    env_cpy[line] = malloc(sizeof(char) * my_strlen(path) + 8);
    env_cpy[line][0] = '\0';
    env_cpy[line] = my_strcat(env_cpy[line], oldpwd);
    env_cpy[line] = my_strcat(env_cpy[line], path);
    return env_cpy;
}

static char **replace_pwd(char **env_cpy, char *path)
{
    char *pwd = my_strdup("PWD=");
    int line = get_line_env(env_cpy, "PWD");

    env_cpy[line] = malloc(sizeof(char) * my_strlen(path) + 5);
    env_cpy[line][0] = '\0';
    env_cpy[line] = my_strcat(env_cpy[line], pwd);
    env_cpy[line] = my_strcat(env_cpy[line], path);
    return env_cpy;
}

char **cd_root(char **env_cpy)
{
    size_t n = 1000;
    char *buf = malloc(sizeof(char) * n);
    char *path = getcwd(buf, n);

    chdir("/");
    env_cpy = replace_oldpwd(env_cpy, path);
    path = getcwd(buf, n);
    env_cpy = replace_pwd(env_cpy, path);
    return env_cpy;
}

char **cd_home(char **env_cpy)
{
    size_t n = 1000;
    char *buf = malloc(sizeof(char) * n);
    char *path = getcwd(buf, n);
    int i = 5;
    int i2 = 0;
    int home_line = get_line_env(env_cpy, "HOME");
    char *HOME = malloc(sizeof(char) * my_strlen(env_cpy[home_line]) - 4);

    while (env_cpy[home_line][i] != '\0') {
        HOME[i2] = env_cpy[home_line][i];
        i2++;
        i++;
    }
    HOME[i2] = '\0';
    chdir(HOME);
    env_cpy = replace_oldpwd(env_cpy, path);
    path = getcwd(buf, n);
    env_cpy = replace_pwd(env_cpy, path);
    return env_cpy;
}

char **cd_previous(char **env_cpy)
{
    size_t n = 1000;
    char *buf = malloc(sizeof(char) * n);
    char *path = getcwd(buf, n);
    int i = 7;
    int i2 = 0;
    int oldpwd_line = get_line_env(env_cpy, "OLDPWD");
    char *OLDPWD = malloc(sizeof(char) * my_strlen(env_cpy[oldpwd_line]) - 6);

    while (env_cpy[oldpwd_line][i] != '\0') {
        OLDPWD[i2] = env_cpy[oldpwd_line][i];
        i2++;
        i++;
    }
    OLDPWD[i2] = '\0';
    chdir(OLDPWD);
    env_cpy = replace_oldpwd(env_cpy, path);
    path = getcwd(buf, n);
    env_cpy = replace_pwd(env_cpy, path);
    return env_cpy;
}

char **cd_dir(char **env_cpy, char **arg)
{
    size_t n = 1000;
    char *buf = malloc(sizeof(char) * n);
    char *path = getcwd(buf, n);

    chdir(arg[1]);
    env_cpy = replace_oldpwd(env_cpy, path);
    path = getcwd(buf, n);
    env_cpy = replace_pwd(env_cpy, path);
    return env_cpy;
}

char **cd_fonct(char **env_cpy, char **arg)
{
    int count = 0;

    if ((arg[1] == NULL) || (my_strcmp(arg[1], "~") == 0)) {
        env_cpy = cd_home(env_cpy);
        return env_cpy;
    }
    if (my_strcmp(arg[1], "-") == 0)
        env_cpy = cd_previous(env_cpy);
    else if (my_strcmp(arg[1], "/") == 0)
        env_cpy = cd_root(env_cpy);
    else {
        env_cpy = cd_dir(env_cpy, arg);
    }
    return env_cpy;
}
