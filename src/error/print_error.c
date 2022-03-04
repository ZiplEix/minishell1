/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** print_error
*/
#include "../../include/my.h"

/**
*@brief display the error message relativly of the typed commande
*
*@param commande array get by getline
*/
void print_error(char **commande, int error)
{
    if (error == NOT_FOUND_COMMANDE) {
        my_putstr(2, commande[0]);
        my_putstr(2, ": Command not found.\n");
    }
    if (error == TOO_MANY_ARGUMENTS) {
        my_putstr(2, commande[0]);
        my_putstr(2, ": Too many arguments.\n");
    }
    if (error == TOO_FEW_ARGUMENTS) {
        my_putstr(2, commande[0]);
        my_putstr(2, ": Too few arguments.\n");
    }
}

void error_execve(int status)
{
    int sigid = WTERMSIG(status);

    if (sigid == 8) {
        my_putstr(2, "Floating exception");
    }
    if (sigid == 11) {
        my_putstr(2, "Segmentation fault");
    }
    if (WCOREDUMP(status))
        my_putstr(2, " (core dumped)");
    if (sigid == 8 || sigid == 11 || WCOREDUMP(status))
        my_putstr(2, "\n");
}
