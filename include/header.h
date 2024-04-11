/*
** EPITECH PROJECT, 2021
** header.h
** File description:
** Librairies that I use.
*/

#ifndef SOKOBAN_H
#define SOKOBAN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <curses.h>

struct pos_p {
    int row;
    int col;
    int nb_x;
    int rows;
    int cols;
};

struct o_p {
    int row;
    int col;
    struct o_p *next;
};

struct c_list {
    struct o_p *begin;
    struct o_p *end;
};

void my_putchar(char);
void my_putstr(char *);
void my_putnbr(int);
void usage(int, char **);
void display_the_map(char **, int, int);
void invalid_maps(int, char **);
void errors_cases_and_usage(int, char **);
void destroy_2d_array(char **, int);
void destroy_the_list(struct o_p *, struct c_list *);
void find_the_position_of_p(char **, struct pos_p *);
void moves(char **, char *, struct pos_p *);
void verify_the_o(char **, struct o_p *);
void input_errors(char *);
int my_getnbr(char *);
int my_strlen(char *);
int none_boxe(char **, struct pos_p *);
int check_the_end_of_the_game(char **, struct pos_p *, struct o_p *);
int biggest_number_of_columns(char **);
int number_of_lines(char *);
char *load_file_in_mem(char *);
char **mem_alloc_2d_array(int, int);
char **load_2d_array_from_file(char *, int);
struct c_list *control_list(struct o_p *);
struct o_p *check_the_o(char **);

#endif
