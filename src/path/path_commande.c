/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** path_commande
*/
#include "../../include/my.h"

void exec_path_commande(char **commande, char *path, char **env)
{
    int pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execve(path, commande, env) == -1)
            exit(0);
    } else
        while (waitpid(pid, &status, 0) != -1 && !WIFEXITED(status))
            error_execve(status);

}

char **concat_path_commande(char **commande, char **path)
{
    int i = 1;

    while (path[i] != NULL) {
        path[i] = my_strcat(path[i], "/");
        path[i] = my_strcat(path[i], commande[0]);
        i++;
    }
    return path;
}

void search_path_commande(char **commande, char **env, char **path)
{
    int i = 1;

    path = concat_path_commande(commande, path);
    while (path[i] != NULL) {
        if (open(path[i], O_RDONLY) != -1) {
            exec_path_commande(commande, path[i], env);
            break;
        }
        i++;
    }
    if (i >= count_line_double_array(path)) {
        print_error(commande, NOT_FOUND_COMMANDE);
    }
}

/**
*@brief handle all the commande of the PATH
*
*@param commande array get by getline()
*@param env classic var containing all the environment var
*/
void path_commande(char **commande, char **env)
{
    char *path_s;
    char **path;
    int i = 0;

    while (env[i]) {
        if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T' &&
        env[i][3] == 'H') {
            path_s = env[i];
            break;
        }
        i++;
    }
    path = my_split(path_s, ':');
    i = 0;
    search_path_commande(commande, env, path);
}
