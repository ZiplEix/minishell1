/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** split
*/
#include "../include/my.h"

int is_alpha_num_s(char c, char split)
{
    if (c == split || c == '=')
        return 0;
    if ((c >= 33 && c <= 127))
        return (1);
    return (0);
}

int word_count_s(char *str, char split)
{
    int i = 0;
    int word = 0;

    while (str != NULL && str[i]) {
        if (is_alpha_num_s(str[i], split) == 1 &&
        is_alpha_num_s(str[i + 1], split) == 0)
            word = word + 1;
        i = i + 1;
    }
    return (word);
}

char **my_split(char *str, char split)
{
    int i = 0;
    int j = 0;
    char **wordarray;
    int len = 0;

    wordarray = malloc((sizeof(char *)) * (word_count_s(str, split) + 1));
    while (str != NULL && str[i]) {
        if (is_alpha_num_s(str[i], split) == 1)
            len = len + 1;
        if (is_alpha_num_s(str[i], split) == 1 &&
        is_alpha_num_s(str[i + 1], split) == 0) {
            wordarray[j] = malloc((sizeof(char)) * (len + 2));
            my_strncpy(wordarray[j], &str[i - len + 1], len);
            len = 0;
            j++;
        }
        i++;
    }
    wordarray[j] = NULL;
    return (wordarray);
}
