/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** count_line_double_array
*/
#include "../include/my.h"

int count_line_double_array(char **double_array)
{
    int i = 1;

    while (double_array[i] != NULL) {
        i++;
    }
    return i;
}
