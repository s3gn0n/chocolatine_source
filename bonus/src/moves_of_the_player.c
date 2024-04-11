/*
** EPITECH PROJECT, 2021
** moves_of_the_player.c
** File description:
** Move the player.
*/

#include "../include/header.h"

void move_up(char **map, struct pos_p *p)
{
    int r = p->row;
    int c = p->col;

    if ((p->row-1 >= 0 || p->col-1 >= 0) &&
        map[p->row-1][p->col] != '#') {
        map[p->row][p->col] = ' ';
        if (map[r-1][c] == 'X' && (map[r-2][c] == ' ' || map[r-2][c] == 'O')) {
            map[p->row-1][p->col] = 'P';
            map[p->row-2][p->col] = 'X';
            p->row--;
        } else if (map[r-1][c] == ' ' || map[r-1][c] == 'O') {
            map[p->row-1][p->col] = 'P';
            p->row--;
        } else {
            map[p->row][p->col] = 'P';
            map[p->row-1][p->col] = 'X';
        }
    }
}

void move_down(char **map, struct pos_p *p)
{
    int r = p->row;
    int c = p->col;

    if ((map[p->row+1] != NULL || p->col-1 >= 0) &&
        map[p->row+1][p->col] != '#') {
        map[p->row][p->col] = ' ';
        if (map[r+1][c] == 'X' && (map[r+2][c] == ' ' || map[r+2][c] == 'O')) {
            map[p->row+1][p->col] = 'P';
            map[p->row+2][p->col] = 'X';
            p->row++;
        } else if (map[r+1][c] == ' ' || map[r+1][c] == 'O') {
            map[p->row+1][p->col] = 'P';
            p->row++;
        } else {
            map[p->row][p->col] = 'P';
            map[p->row+1][p->col] = 'X';
        }
    }
}

void move_left(char **map, struct pos_p *p)
{
    int r = p->row;
    int c = p->col;

    if (p->col-1 >= 0 && map[p->row][p->col-1] != '#') {
        map[p->row][p->col] = ' ';
        if (map[r][c-1] == 'X' && (map[r][c-2] == ' ' || map[r][c-2] == 'O')) {
            map[p->row][p->col-1] = 'P';
            map[p->row][p->col-2] = 'X';
            p->col--;
        } else if (map[r][c-1] == ' ' || map[r][c-1] == 'O') {
            map[p->row][p->col-1] = 'P';
            p->col--;
        } else {
            map[p->row][p->col] = 'P';
            map[p->row][p->col-1] = 'X';
        }
    }
}

void move_right(char **map, struct pos_p *p)
{
    int r = p->row;
    int c = p->col;

    if (map[p->row][p->col+1] != '\0' && map[p->row][p->col+1] != '#') {
        map[p->row][p->col] = ' ';
        if (map[r][c+1] == 'X' && (map[r][c+2] == ' ' || map[r][c+2] == 'O')) {
            map[p->row][p->col+1] = 'P';
            map[p->row][p->col+2] = 'X';
            p->col++;
        } else if (map[r][c+1] == ' ' || map[r][c+1] == 'O') {
            map[p->row][p->col+1] = 'P';
            p->col++;
        } else {
            map[p->row][p->col] = 'P';
            map[p->row][p->col+1] = 'X';
        }
    }
}

void moves(char **map, char *filepath, struct pos_p *p)
{
    int ch = getch();

    clear();
    (ch == KEY_UP) ? move_up(map, p) : 0;
    (ch == KEY_DOWN) ? move_down(map, p) : 0;
    (ch == KEY_LEFT) ? move_left(map, p) : 0;
    (ch == KEY_RIGHT) ? move_right(map, p) : 0;
    if (ch == 32) {
        destroy_2d_array(map, p->rows);
        map = load_2d_array_from_file(filepath, p->rows);
        find_the_position_of_p(map, p);
    }
}
