/*
** EPITECH PROJECT, 2021
** maps_functions.c
** File description:
** Load file in 2d array.
*/

#include "../include/header.h"

char **load_2d_array_from_file(char *filepath, int nb_rows)
{
    int a = 0;
    int b = 0;
    int len = 0;
    char *map = load_file_in_mem(filepath);
    char **map_2d = malloc(sizeof(char *)*(nb_rows+1));

    for (int i = 0; a < nb_rows; i++, a++) {
        for (len = i; map[len] != '\n'; len++);
        len = (i == 0) ? len : len-i;
        map_2d[a] = malloc(sizeof(char *)*(len+2));
        for (b = 0; map[i] != '\n'; i++, b++)
            map_2d[a][b] = map[i];
        map_2d[a][b] = '\n';
        map_2d[a][b+1] = '\0';
    }
    map_2d[a] = NULL;
    free(map);
    return (map_2d);
}

void find_the_position_of_p(char **map, struct pos_p *pos)
{
    pos->nb_x = 0;
    for (int r = 0; map[r] != NULL; r++)
        for (int c = 0; map[r][c] != '\0'; c++)
            if (map[r][c] == 'P') {
                pos->row = r;
                pos->col = c;
            } else if (map[r][c] == 'X')
                pos->nb_x++;
}

void verify_size_terminal(int nb_cols, int nb_rows)
{
    int *size = malloc(sizeof(int)*6);

    getmaxyx(stdscr, size[6], size[5]);
    for (size[0] = 0; size[6] < nb_rows+1 || size[5] < nb_cols+1; size[0]++) {
        (size[0] == 0) ? clear() : 0;
        getmaxyx(stdscr, size[6], size[5]);
        size[2] = (size[6]-1)/2;
        size[1] = (size[5]-my_strlen("Please, enlarge the terminal !\n"))/2;
        (size[3] != size[1] || size[4] != size[2]) ? clear() : 0;
        mvprintw(size[2], size[1], "Please, enlarge the terminal !\n");
        refresh();
        size[3] = size[1];
        size[4] = size[2];
    }
    (size[0] != 0) ? clear() : 0;
    free(size);
}

void display_the_map(char **map, int nb_cols, int nb_rows)
{
    int x = 0;
    int y = 0;

    verify_size_terminal(nb_cols, nb_rows);
    for (int i = 0; map[i] != NULL; i++)
        mvprintw(y+i, x, map[i]);
    refresh();
}

struct c_list *control_list(struct o_p *p_o)
{
    struct o_p *temp = p_o;
    struct c_list *c_l = malloc(sizeof(struct c_list));

    c_l->begin = temp;
    for ( ; temp->next != NULL; temp = temp->next);
    c_l->end = temp;
    return (c_l);
}
