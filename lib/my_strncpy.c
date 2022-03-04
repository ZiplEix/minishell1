/*
** EPITECH PROJECT, 2021
** Task 02 - my_strncpy
** File description:
** a function that copies n characters from a string into another.
*/
#include "../include/my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (src[i] != '\0' && i != n) {
        dest[i] = src[i];
        i++;
    }
    if (my_strlen(src) < n)
        dest[i] = '\0';
    return dest;
}
