/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** right redir
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
#include <sys/types.h>
#include <fcntl.h>

char **right_redirection(char **env_cpy, cmd_t *cmd, int i)
{
    int fd;

    if (my_strcmp(cmd->redirection[i], ">") == 0) {
        fd = open(cmd->cmd[i + 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
    } else if (my_strcmp(cmd->redirection[i], ">>") == 0)
        fd = open(cmd->cmd[i + 1], O_CREAT | O_APPEND | O_WRONLY, 0644);
    env_cpy = verif_error_exec(env_cpy, cmd->cmd[i], fd);
    close(fd);
    return env_cpy;
}
