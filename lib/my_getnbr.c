/*
** EPITECH PROJECT, 2021
** Task 05 - my_getnbr
** File description:
** a function that returns a number, sent to the function as a string.
*/

int my_getnbr(char const *str)
{
    int signe = 1;
    int i = 0;
    long int result = 0;
    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-') {
            signe = signe * -1;
        }
        i++;
    }
    while (str[i] >= 48 && str[i] <= 57) {
        result = result * 10 + (str[i] - 48);
        if (result > 2147483648 || (result == 2147483648 && signe == 1)) {
            return 0;
        }
        i++;
    }
    return (result * signe);
}
