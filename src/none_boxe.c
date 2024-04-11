/*
** EPITECH PROJECT, 2021
** none_boxe.c
** File description:
** Check if none of the boxes can be moved anymore.
*/
#include "../include/header.h"

int check_the_end_of_the_game(char **map, struct pos_p *p, struct o_p *p_o)
{
    int e_o_g = 0;

    for ( ; p_o != NULL; p_o = p_o->next)
        (map[p_o->row][p_o->col] == 'X') ? e_o_g++ : 0;
    return (e_o_g == p->nb_x ? 0 : 1);
}

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
