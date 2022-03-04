/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** exit
*/
#include "../../include/my.h"

/**
*@brief print the correct exit msg
*
*@param commande array get by getline()
*/
void fonc_exit(char **commande)
{
    if (commande[0] && commande[1] == NULL) {
        my_putstr(1, "exit\n");
        exit(0);
    } else {
        my_putstr(2, "exit: Expression Syntax.\n");
    }
}
