/*
** EPITECH PROJECT, 2022
** antman
** File description:
** my_strcmp
*/
#include "../include/my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i = i + 1;
    }
    return (s1[i] - s2[i]);
}
