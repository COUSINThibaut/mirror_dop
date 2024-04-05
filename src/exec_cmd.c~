/*
** EPITECH PROJECT, 2024
** minishell
** File description:
** child_process
*/

#include <sys/wait.h>
#include <sys/types.h>
#include "../include/my.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <errno.h>

static void exit_error(int count_exec, int count, int redirect, char *av)
{
    if ((count_exec * -1) == count) {
        my_putstr(av);
        my_putstr(": Command not found.\n");
    }
}


char *concat_cmd_line(char *path, char *cmd)
{
    int len = (my_strlen(path) + my_strlen(cmd) + 2);
    char *cmd_line = malloc(sizeof(char) * (len));

    cmd_line[0] = '\0';
    cmd_line = my_strcat(cmd_line, path);
    cmd_line = my_strcat(cmd_line, my_strdup("/"));
    cmd_line = my_strcat(cmd_line, cmd);
    return cmd_line;
}

static void exit_binari_error(int redirect, char *cmd)
{
    if (errno == 13) {
        my_putstr(cmd);
        my_putstr(": Permission denied.\n");
        if (isatty(0) == 0)
        exit(1);
    }
    if (errno == 8) {
        my_putstr(cmd);
        my_putstr(": Exec format error. Wrong Architecture.\n");
        if (isatty(0) == 0)
        exit(1);
    }
}

static int child_process(char *av, char **env, int redirect, int fd)
{
    char **arg;
    char *cmd;
    char **path;
    int count = 0;
    int count_exec = 0;

    if (av[0] == '\0')
        return 0;
    arg = my_str_to_word_array(av);
    if (execve(arg[0], arg, env) == -1)
        exit_binari_error(redirect, arg[0]);
    arg[0] = verif_command(arg[0]);
    path = my_str_to_word_array_path(env[get_line_env(env, "PATH")]);
    for (; path[count] != NULL; count++);
    dup2(fd, 1);
    for (int i = 0; path[i] != NULL; i++) {
        cmd = concat_cmd_line(path[i], arg[0]);
        count_exec += execve(cmd, arg, env);
    }
    exit_error(count_exec, count, redirect, av);
}

void error_handling_exec(int status, int redirect)
{
    if (WIFEXITED(status)) {
        if (WEXITSTATUS(status) == 1 && redirect == 0)
            exit(1);
        if (WEXITSTATUS(status) == 2 && redirect == 0)
            exit(2);
    }
    if (WIFSIGNALED(status)) {
        if (WCOREDUMP(status)) {
            write(2, "Segmentation fault\n", 19);
        } else
            write(2, "Segmentation fault\n", 19);
        if (isatty(0) == 0)
            exit(status);
    }
}

int exec_cmd(char *av, char **env, int fd)
{
    int pid;
    int redirect = isatty(0);
    int status = 0;

    pid = fork();
    if (pid < 0)
        return 84;
    if (pid == 0)
        child_process(av, env, redirect, fd);
    if (pid > 0) {
        waitpid(pid, &status, WUNTRACED);
        error_handling_exec(status, redirect);
    }
}
