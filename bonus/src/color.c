/*
** EPITECH PROJECT, 2021
** color.c
** File description:
** Display the map in color.
*/

#include "../include/header.h"

void d_map(char **map, int max_x, int y, int x)
{
    int a = x;
    int b = y;
    int c = (max_x-my_strlen("PRESS SPACE BAR TO RESET THE GAME"))/2;

    mvprintw(y-2, c, "PRESS SPACE BAR TO RESET THE GAME");
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    for (int r = 0; map[r] != NULL; r++, b++, a = x)
        for (int c = 0; map[r][c] != '\0'; c++, a++) {
            if (map[r][c] == '#') {
                attron(COLOR_PAIR(2));
                mvprintw(b, a, &map[r][c]);
                attroff(COLOR_PAIR(2));
            } else if (map[r][c] == 'X') {
                attron(COLOR_PAIR(3));
                mvprintw(b, a, &map[r][c]);
                attroff(COLOR_PAIR(3));
            } else
                mvprintw(b, a, &map[r][c]);
        }
    refresh();
}
