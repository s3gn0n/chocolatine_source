/*
** EPITECH PROJECT, 2021
** none_boxe_b.
** File description:
** Manage none boxe
*/

#include "../include/header.h"

int none_boxe_a(char **map, int r, int c)
{
    if ((map[r][c+1] == 'X' && map[r][c+2] != '#' && map[r][c-1] != '#'
    && map[r+1][c] == '#' && map[r+1][c+1] == '#')
    || (map[r][c-1] == 'X' && map[r][c+1] != '#'
    && map[r][c-2] != '#' && map[r+1][c] == '#' && map[r+1][c-1] == '#')
    || (map[r][c+1] == 'X' && map[r][c+2] != '#' && map[r][c-1] != '#'
    && map[r-1][c] == '#' && map[r-1][c+1] == '#')
    || (map[r][c-1] == 'X' && map[r][c+1] != '#' && map[r][c-2] != '#'
    && map[r-1][c] == '#' && map[r-1][c-1] == '#')
    || (map[r][c+1] == '#' && map[r+1][c] == 'X' && map[r+1][c+1] == '#'
    && map[r+2][c] == '#' && map[r+2][c+1] == '#')
    || (map[r][c+1] == '#' && map[r-1][c] == 'X' && map[r-1][c+1] == '#'
    && map[r-2][c] == '#' && map[r-2][c+1] == '#')
    || (map[r][c-1] == '#' && map[r+1][c] == 'X' && map[r-1][c-1] == '#'
    && map[r+2][c] == '#' && map[r+2][c-1] == '#')
    || (map[r][c-1] == '#' && map[r-1][c] == 'X' && map[r-1][c-1] == '#'
    && map[r-2][c] == '#' && map[r-2][c-1] == '#'))
        return (1);
}

int none_boxe_b(char **map, int r, int c)
{
    if ((map[r-1][c] == '#' && map[r][c+1] == '#') ||
    (map[r-1][c] == '#' && map[r][c-1] == '#') ||
    (map[r+1][c] == '#' && map[r][c+1] == '#') ||
    (map[r+1][c] == '#' && map[r][c-1] == '#') ||
    (map[r][c-1] == 'X' && map[r+1][c] == 'X' && map[r+1][c-1] == 'X'))
        return (1);
    else if ((map[r][c-1] == 'X' && map[r][c-2] == '#'
    && map[r+1][c] == '#' && map[r+1][c-1] == '#')
    || (map[r][c+1] == 'X' && map[r][c+2] == '#'
    && map[r+1][c] == '#' && map[r+1][c+1] == '#')
    || (map[r][c-1] == 'X' && map[r][c-2] == '#'
    && map[r-1][c] == '#' && map[r-1][c-1] == '#')
    || (map[r][c+1] == 'X' && map[r][c+2] == '#'
    && map[r-1][c] == '#' && map[r-1][c+1] == '#'))
        return (1);
}

int none_boxe(char **map, struct pos_p *pos)
{
    int m = 0;

    for (int r = 0; map[r] != NULL; r++)
        for (int c = 0; map[r][c] != '\0'; c++)
            if (map[r][c] == 'X') {
                (none_boxe_a(map, r, c) == 1) ? m++ : 0;
                (none_boxe_b(map, r, c) == 1) ? m++ : 0;
            }
    if (m == pos->nb_x)
        return (1);
    return (0);
}
