/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** env_commande
*/
#include "../../include/my.h"

/**
*@brief handle the env commande
*
*@param env classic var containing all the environment var
*@param commande array get by getline()
*/
void env_commande(char **env, char **commande)
{
    int i = 0;

    if (!commande[1]) {
        while (env[i] != NULL) {
            my_putstr(1, env[i]);
            my_putstr(1, "\n");
            i++;
        }
    }
    if (commande[1]) {
        commande = &commande[1];
        path_commande(commande, env);
    }
    return;
}
