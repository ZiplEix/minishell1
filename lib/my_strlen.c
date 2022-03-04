/*
** EPITECH PROJECT, 2021
** Task 03 - my_strlen
** File description:
** a fonction that count the numbre of charactere in a word
*/

int my_strlen(char const *str)
{
    int count = 0;
    int i = 0;
    while (str[i]) {
        count++;
        i++;
    }
    return count;
}
