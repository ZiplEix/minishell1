/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** minishell
*/
#include "../../include/my.h"

char **distribe_commande(char **commande, char **env)
{
    if (my_strcmp("exit", commande[0]) == 0)
        fonc_exit(commande);
    if (my_strcmp("env", commande[0]) == 0) {
        env_commande(env, commande);
        return env;
    }
    if (my_strcmp("setenv", commande[0]) == 0) {
        env = func_setenv(env, commande);
        return env;
    }
    if (my_strcmp("unsetenv", commande[0]) == 0) {
        env = func_unsetenv(env, commande);
        return env;
    }
    if (my_strcmp("cd", commande[0]) == 0) {
        env = func_cd(env, commande);
        return env;
    }
    binary_commande(env, commande);
    return env;
}

/**
*@brief main fonction of the programme
*
*@param argc classic var for the number of programme arguments
*@param argv classic var containing all the programme arguments
*@param env classic var containing all the environmant var
*@return 84 if error | 0 normaly
*/
int minishell(int argc, char **argv, char **env)
{
    size_t len;
    ssize_t size;
    char *buffer;
    char **commande;

    while (1) {
        buffer = NULL;
        print_promp();
        if (size = getline(&buffer, &len, stdin) == -1) {
            my_putstr(1, "exit\n");
            exit(0);
        }
        commande = my_str_to_word_array(buffer);
        if (commande[0] == NULL)
            continue;
        env = distribe_commande(commande, env);
    }
}
