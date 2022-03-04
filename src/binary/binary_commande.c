/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** binary_commande
*/
#include "../../include/my.h"

int as_a_slash(char *commande0)
{
    int i = 0;

    while (commande0[i]) {
        if (commande0[i] == '/') {
            return 1;
        }
        i++;
    }
    return 0;
}

int binary(char **env, char **commande)
{
    int pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execve(commande[0], commande, env) == -1) {
            exit(0);
        }
    } else
        while (waitpid(pid, &status, 0) != -1 && !WIFEXITED(status))
            error_execve(status);

    return 0;
}

void binary_commande(char **env, char **commande)
{
    if ((commande[0][0] == '.' && commande[0][1] == '/') ||
    as_a_slash(commande[0]) == 1) {
        if (binary(env, commande) == 0)
            return;
    }
    path_commande(commande, env);
}
