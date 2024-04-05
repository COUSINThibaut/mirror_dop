/*
** EPITECH PROJECT, 2024
** mini shell
** File description:
** my_exec
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

int count_args(char **arg)
{
    int i = 0;

    while (arg[i] != NULL) {
        i++;
    }
    return (i - 1);
}

static char *rm_slashn(char *buf)
{
    int i = 0;
    char *buffer;
    int count = 0;

    for (; buf[i] != '\0'; i++)
        if (buf[i] == '\n')
            count++;
    i = 0;
    if (count == 0)
        return buffer;
    for (; buf[i] != '\n'; i++);
    buffer = malloc(sizeof(char) * i + 1);
    i = 0;
    for (; buf[i] != '\n'; i++)
        buffer[i] = buf[i];
    buffer[i] = '\0';
    buffer = clean_str(buffer);
    return buffer;
}

static void free_tab(char **env_cpy)
{
    for (int i = 0; env_cpy[i] != NULL; i++)
        free(env_cpy[i]);
    free(env_cpy);
}

static char **cpy_tab_env(char **env)
{
    int i = 0;
    char **cpy_env;

    for (; env[i] != NULL; i++);
    cpy_env = malloc(sizeof(char *) * i + sizeof(NULL));
    i = 0;
    for (; env[i] != NULL; i++)
        cpy_env[i] = my_strdup(env[i]);
    cpy_env[i] = NULL;
    return cpy_env;
}

char **verif_arg(char **env_cpy, char **arg, char *buf, int fd)
{
    if (my_strcmp(arg[0], "setenv") == 0) {
        env_cpy = my_setenv(env_cpy, arg);
        return env_cpy;
    }
    if (my_strcmp(arg[0], "unsetenv") == 0) {
        env_cpy = my_unsetenv(env_cpy, arg);
        return env_cpy;
    }
    if (my_strcmp(arg[0], "env") == 0)
        my_show_word_array(env_cpy);
    else if (my_strcmp(arg[0], "cd") == 0)
        env_cpy = cd_fonct(env_cpy, arg);
    else
        exec_cmd(buf, env_cpy, fd);
    return env_cpy;
}

static int verif_is_tty(void)
{
    if (isatty(0))
        my_putstr("&> ");
}

char **verif_error_exec(char **env_cpy, char *buf, int fd)
{
    char **arg = my_str_to_word_array(buf);
    int rtrn = 0;

    if (my_strcmp(arg[0], "exit") == 0)
        exit(0);
    rtrn = error_handling(arg);
    if (rtrn == 0)
        env_cpy = verif_arg(env_cpy, arg, buf, fd);
    else if (rtrn == 1 && isatty(0) == 0)
        exit(1);
    return env_cpy;
}

char **gestion_syntaxe(char **env_cpy, cmd_t *cmd, int i)
{
    if ((i > 0) && (my_strcmp(cmd->redirection[i - 1], "|") == 0))
        return env_cpy;
    if ((i > 0) && (my_strcmp(cmd->redirection[i - 1], ">") == 0 ||
    my_strcmp(cmd->redirection[i - 1], ">>") == 0))
        return env_cpy;
    if (cmd->cmd[1] == NULL || cmd->redirection[i] == NULL)
        return (verif_error_exec(env_cpy, cmd->cmd[i], 1));
    if (my_strcmp(cmd->redirection[i], ";") == 0)
        return (verif_error_exec(env_cpy, cmd->cmd[i], 1));
    if (my_strcmp(cmd->redirection[i], ">") == 0 ||
    my_strcmp(cmd->redirection[i], ">>") == 0)
        return (right_redirection(env_cpy, cmd, i));
    if (my_strcmp(cmd->redirection[i], "|") == 0) {
        return (pipes_exec(env_cpy, cmd, i));
    } else
        return env_cpy;
}

int main(int ac, char **av, char **env)
{
    cmd_t cmd;
    char **env_cpy = cpy_tab_env(env);
    char *buf;
    char **arg;
    size_t n = 50;
    int rtrn = 0;

    for (; 1; free(buf)) {
        buf = malloc(sizeof(char) * n);
        verif_is_tty();
        if (getline(&buf, &n, stdin) == -1)
            return 0;
        buf = rm_slashn(buf);
        cmd = init_cmd(buf);
        for (int i = 0; cmd.cmd[i] != NULL; i++) {
            env_cpy = gestion_syntaxe(env_cpy, &cmd, i);
        }
    }
    free_tab(env_cpy);
    return 0;
}
