/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** gestion struct
*/

#include <sys/wait.h>
#include "../include/minishell.h"
#include "../include/my.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

char *clean_str_redirection(char *buf)
{
    int i2 = 0;
    int i3 = 0;
    int count = 0;
    char *redirection;

    for (int i = 0; buf[i] != '\0'; i++) {
        if (buf[i] == '|' || buf[i] == ';' || buf[i] == '<' ||
            buf[i] == '>' || buf[i] == ' ')
            count++;
    }
    redirection = malloc(sizeof(char) * count + 1);
    for (int i2 = 0; buf[i2] != '\0'; i2++) {
        if (buf[i2] == '|' || buf[i2] == ';' || buf[i2] == '<' ||
            buf[i2] == '>' || buf[i2] == ' ') {
            redirection[i3] = buf[i2];
            i3++;
        }
    }
    redirection[i3] = '\0';
    return redirection;
}

char *clean_str_cmd(char *buf)
{
    int i2 = 0;
    int i3 = 0;
    int count = my_strlen(buf);
    char *cmd;

    for (int i = 0; buf[i] != '\0'; i++) {
        if ((buf[i] == '<' && buf[i + 1] == '<') ||
            (buf[i] == '>' && buf[i + 1] == '>'))
            count--;
    }
    cmd = malloc(sizeof(char) * count + 1);
    for (int i2 = 0; buf[i2] != '\0'; i2++) {
        if ((buf[i2] == '<' || buf[i2] == '>') &&
            (buf[i2 + 1] == '<' || buf[i2 + 1] == '>'))
            i2++;
        cmd[i3] = buf[i2];
            i3++;
    }
    cmd[i3] = '\0';
    return cmd;
}

char **clean_tab(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++)
        tab[i] = clean_str(tab[i]);
    return tab;
}

int verif_redir(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '<' || str[i] == '>' || str[i] == ';' || str[i] == '|')
            count++;
    }
    if (count == 0)
        return 0;
    return 1;
}

cmd_t init_cmd(char *buf)
{
    cmd_t cmd;
    char *redirection = clean_str_redirection(buf);
    char *cmd_clean = clean_str_cmd(buf);

    if (verif_redir(redirection) != 0) {
        redirection = clean_str(redirection);
        cmd.redirection = my_str_to_word_array(redirection);
        cmd.redirection = clean_tab((cmd.redirection));
    }
    cmd_clean = clean_str(cmd_clean);
    cmd.cmd = my_str_to_word_cmd_array(cmd_clean);
    cmd.cmd = clean_tab((cmd.cmd));
    return cmd;
}
