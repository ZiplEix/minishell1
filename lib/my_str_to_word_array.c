/*
** EPITECH PROJECT, 2021
** Task 04 - my_str_to_word_array
** File description:
** a function that splits a string into words
*/
#include "../include/my.h"

int is_alpha_num(char c)
{
    if ((c >= 33 && c <= 127))
        return (1);
    return (0);
}

int word_count(char *str)
{
    int i = 0;
    int word = 0;

    while (str != NULL && str[i]) {
        if (is_alpha_num(str[i]) == 1 && is_alpha_num(str[i + 1]) == 0)
            word = word + 1;
        i = i + 1;
    }
    return (word);
}

char **my_str_to_word_array(char *str)
{
    int i = 0;
    int j = 0;
    char **wordarray;
    int len = 0;

    wordarray = malloc((sizeof(char *)) * (word_count(str) + 1));
    while (str != NULL && str[i]) {
        if (is_alpha_num(str[i]) == 1)
            len = len + 1;
        if (is_alpha_num(str[i]) == 1 && is_alpha_num(str[i + 1]) == 0) {
            wordarray[j] = malloc((sizeof(char)) * (len + 1));
            my_strncpy(wordarray[j], &str[i - len + 1], len);
            len = 0;
            j++;
        }
        i++;
    }
    wordarray[j] = NULL;
    return (wordarray);
}
