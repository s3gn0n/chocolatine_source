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
#include <SFML/Audio.h>
#include <SFML/Audio/SoundBuffer.h>
#include <SFML/Audio/Sound.h>
#include <SFML/Audio/Export.h>
#include <SFML/Audio/SoundStatus.h>
#include <SFML/Audio/Types.h>
#include <time.h>

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

struct music {
    sfSound *loop;
    sfSoundBuffer *music;
};

void my_putchar(char);
void my_putstr(char *);
void my_putnbr(int);
void usage(int, char **);
void d_map(char **, int, int, int);
void display_the_map(char **, int, int);
void input_errors(int, char **);
void invalid_maps(int, char **);
void errors_cases_and_usage(int, char **);
void destroy_2d_array(char **, int);
void destroy_the_list(struct o_p *, struct c_list *);
void find_the_position_of_p(char **, struct pos_p *);
void check_the_o_lf(char **, struct pos_p *, int *);
void check_the_o_ud(char **, struct pos_p *, int *);
void set_music(struct music *, char *);
void sokoban(char **, char **, struct music *);
void my_popup(void);
void my_popwin(int);
void moves(char **, char *, struct pos_p *);
void verify_the_o(char **, struct o_p *);
int my_getnbr(char *);
int my_sokoban(char *, int);
int my_strlen(char *);
int none_boxe(char **, struct pos_p *);
int biggest_number_of_columns(char **);
int number_of_lines(char *);
int *o_left_or_right(char **, struct pos_p *);
int *o_up_or_down(char **, struct pos_p *);
char *load_file_in_mem(char *);
char **level(void);
char **mem_alloc_2d_array(int, int);
char **musics(void);
char **load_2d_array_from_file(char *, int);
struct c_list *control_list(struct o_p *);
struct o_p *check_the_o(char **);
struct music *create_music(void);

#endif
