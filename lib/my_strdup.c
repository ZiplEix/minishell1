/*
** EPITECH PROJECT, 2022
** my_strdup
** File description:
** duplicate a string by allocating mem
*/
#include "../include/my.h"

char *my_strdup(char const *src)
{
    int len = my_strlen(src) + 1;
    int i = 0;
    char *dest = (char *)malloc(len * sizeof(char));

    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}
