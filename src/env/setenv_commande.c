/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** setenv_commande
*/
#include "../../include/my.h"

char *build_new_var_env(char **commande)
{
    char *new_var_env = NULL;

    new_var_env = my_strcat(new_var_env, commande[1]);
    new_var_env = my_strcat(new_var_env, "=");
    if (commande[2]) {
        new_var_env = my_strcat(new_var_env, commande[2]);
    }

    return new_var_env;
}

char **exec_setenv(char **env, char **commande)
{
    int lines = count_line_double_array(env);
    char **new_env = malloc(sizeof(char *) * (lines + 1));
    char *new_var_env = build_new_var_env(commande);

    for (int i = 0; i < lines; i++) {
        new_env[i] = malloc(sizeof(env[i]));
        new_env[i] = env[i];
    }

    new_env[lines] = malloc(sizeof(new_var_env) + 1);
    new_env[lines] = new_var_env;

    new_env[lines + 1] = NULL;

    return new_env;
}

/**
*@brief handle the setenv fonction
*
*@param env classic var containing all the environment var
*@param commande array get by getline()
*@return the new env created
*/
char **func_setenv(char **env, char **commande)
{
    int nb_arg = count_line_double_array(commande);

    if (!commande[1]) {
        commande[0] = "env";
        env_commande(env, commande);
        return env;
    } else if (nb_arg > 3) {
        print_error(commande, TOO_MANY_ARGUMENTS);
        return env;
    } else
        env = exec_setenv(env, commande);

    return env;
}
