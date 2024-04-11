/*
** EPITECH PROJECT, 2021
** essentials_functions.c
** File description:
** Functions that I use usually.
*/

#include "../include/header.h"

int my_getnbr(char *str)
{
    int res = 0;

    for (int i = 0; str[i] >= '0' && str[i] <= '9'; i++)
        res = res*10+(str[i]-48);
    return (res);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putnbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        my_putnbr(nb*(-1));
    }
    else if (nb >= 0 && nb <= 9)
        my_putchar(nb+48);
    if (nb > 9) {
        my_putnbr(nb/10);
        my_putchar(nb%10+48);
    }
}

void my_putstr(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        write(1, &str[i], 1);
}

int my_strlen(char *str)
{
    for (int len = 0; ; len++)
        if (str[len] == '\0')
            return (len);
}
