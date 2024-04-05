/*
** EPITECH PROJECT, 2024
** mysh
** File description:
** pipes_exec
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

char **pipes_exec(char **env, cmd_t *cmd, int i)
{
    int from_cmd[2];
    int pid = 0;
    int pid2 = 0;

    pid = fork();
    pipe(from_cmd);
    if (pid == 0)
        env = verif_error_exec(env, cmd->cmd[i], from_cmd[1]);
    pid2 = fork();
    if (pid2 == 0) {
        dup2(from_cmd[0], 0);
        env = verif_error_exec(env, cmd->cmd[i + 1], 1);
    }
    close(from_cmd[0]);
    close(from_cmd[1]);
    return env;
}
