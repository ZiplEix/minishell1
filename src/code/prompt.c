/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** prompt
*/
#include "../../include/my.h"

/**
*@brief print the right prompt
*/
void print_promp(void)
{
    my_putstr(1, "\033[0;31m");
    my_putstr(1, "\033[1m");
    my_putstr(1, "$");
    my_putstr(1, "\033[0;36m");
    my_putstr(1, "\033[1m");
    my_putstr(1, "~");
    my_putstr(1, "\033[0;32m");
    my_putstr(1, "\033[1m");
    my_putstr(1, "> ");
    my_putstr(1, "\033[0;37m");
    my_putstr(1, "\033[0m");
}
