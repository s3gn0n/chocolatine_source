/*
** EPITECH PROJECT, 2021
** none_boxe.c
** File description:
** Check if none of the boxes can be moved anymore.
*/
#include "../include/header.h"

void my_popup(void)
{
    int x = 0;
    int y = 0;
    int max_x = 0;
    int max_y = 0;
    char ec;

    getmaxyx(stdscr, max_y, max_x);
    y = (max_y-2)/2;
    while (ec != '\n') {
        x = (max_x-my_strlen("WELCOME TO MY SOKOBAN"))/2;
        mvprintw(y, x, "WELCOME TO MY SOKOBAN");
        x = (max_x-my_strlen("PRESS ENTER TO CONTINUE"))/2;
        mvprintw(y+1, x, "PRESS ENTER TO CONTINUE");
        refresh();
        ec = getch();
    }
}

void win(int max_x, int max_y)
{
    int x = (max_x-my_strlen("CONGRATULATIONS !"))/2;
    int y = (max_y-2)/2;

    init_pair(4, COLOR_GREEN, COLOR_BLACK);
    attron(COLOR_PAIR(4));
    mvprintw(y, x, "CONGRATULATIONS !");
    x = (max_x-my_strlen("YOU WIN"))/2;
    mvprintw(y+1, x, "YOU WIN");
    attroff(COLOR_PAIR(4));
}

void lose(int max_x, int max_y)
{
    int x = (max_x-my_strlen("NONE OF THE BOXES CAN BE MOVED ANYMORE"))/2;
    int y = (max_y-2)/2;

    init_pair(5, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(5));
    mvprintw(y, x, "NONE OF THE BOXES CAN BE MOVED ANYMORE");
    x = (max_x-my_strlen("YOU LOSE"))/2;
    mvprintw(y+1, x, "YOU LOSE");
    attroff(COLOR_PAIR(5));
}

void my_popwin(int end)
{
    int max_x = 0;
    int max_y = 0;

    clear();
    getmaxyx(stdscr, max_y, max_x);
    (end == 0) ? win(max_x, max_y) : lose(max_x, max_y);
    refresh();
    usleep(2000000);
}
