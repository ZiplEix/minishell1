/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** unsetenv_commande
*/
#include "../../include/my.h"

char **exec_unsetenv(char **env, char **commande)
{
    char **temp_env_var;
    int lines = count_line_double_array(env);
    char **new_env = malloc(sizeof(char *) * lines);
    int j = 0;

    for (int i = 0; i < lines; i++) {
        temp_env_var = my_split(env[i], '=');
        if (my_strcmp(temp_env_var[0], commande[1]) == 0) {
            continue;
        }
        new_env[j] = malloc(sizeof(env[i]) + 1);
        new_env[j] = env[i];
        j++;
    }
    return new_env;
}

/**
*@brief handle the unsetenv fonction
*
*@param env classic var containing all the environment var
*@param commande array get by getline()
*@return the new env created
*/
char **func_unsetenv(char **env, char **commande)
{
    if (!commande[1]) {
        print_error(commande, TOO_FEW_ARGUMENTS);
        return env;
    } else
        env = exec_unsetenv(env, commande);
    return env;
}
