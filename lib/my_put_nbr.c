/*
** EPITECH PROJECT, 2021
** TTask 07 - my_put_nbr
** File description:
** this file allow to print int with multiple digit
*/
#include "../include/my.h"

void putnb(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    int number;
    int number_div_10 = 0;
    unsigned nbr;

    if (nb < 0) {
        nb = nb * -1;
        my_putstr(1, "-");
    }
    nbr = nb;
    if (nbr < 10) {
        putnb(nbr + 48);
    } else if (nbr > 9) {
        number_div_10 = nbr / 10;
        my_put_nbr(number_div_10);
        number = nbr % 10;
        putnb(number + 48);
    }
}
