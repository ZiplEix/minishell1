/*
** EPITECH PROJECT, 2021
** Task 02 - my_putstr
** File description:
** print a entire strint with a fonction
*/
#include "../include/my.h"

int my_putstr(int channel, char const *str)
{
    write(channel, str, my_strlen(str));
}
