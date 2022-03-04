/*
** EPITECH PROJECT, 2022
** my_strcat
** File description:
** concat 2 strings
*/
#include "../include/my.h"

char *my_strcat(char *src, char *to_add)
{
    int i = 0;
    int len = 0;
    char *new_str;

    if (src == NULL)
        return (my_strdup(to_add));
    len = my_strlen(src) + my_strlen(to_add) + 1;
    new_str = (char *)malloc(len * sizeof(char));
    while (src[i] != '\0') {
        new_str[i] = src[i];
        i++;
    }
    for (int x = 0; to_add[x] != '\0'; x++) {
        new_str[i] = to_add[x];
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}
