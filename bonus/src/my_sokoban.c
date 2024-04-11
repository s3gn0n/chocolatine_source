/*
** EPITECH PROJECT, 2021
** my_sokoban.c
** File description:
** Main file.
*/

#include "../include/header.h"

int check_the_end_of_the_game(char **map, struct pos_p *p, struct o_p *p_o)
{
    int e_o_g = 0;

    for ( ; p_o != NULL; p_o = p_o->next)
        (map[p_o->row][p_o->col] == 'X') ? e_o_g++ : 0;
    return (e_o_g == p->nb_x ? 0 : 1);
}

void start_the_game(char **map, struct pos_p *pos, int rows)
{
    find_the_position_of_p(map, pos);
    pos->cols = biggest_number_of_columns(map);
    pos->rows = rows;
    initscr();
    noecho();
    curs_set(FALSE);
    start_color();
    keypad(stdscr, TRUE);
}

void end_of_the_game(char **map, int nb_rows, struct pos_p *pos_of_p)
{
    endwin();
    destroy_2d_array(map, nb_rows);
    free(pos_of_p);
}

int my_sokoban(char *filepath, int nb_rows)
{
    int e_o_g = 1;
    int n_b = 0;
    char **map = load_2d_array_from_file(filepath, nb_rows);
    struct pos_p *pos_of_p = malloc(sizeof(struct pos_p));
    struct o_p *p_o = check_the_o(map);
    struct c_list *c_l = control_list(p_o);

    start_the_game(map, pos_of_p, nb_rows);
    for ( ; ; ) {
        e_o_g = check_the_end_of_the_game(map, pos_of_p, p_o);
        n_b = none_boxe(map, pos_of_p);
        if (e_o_g == 0 || n_b == 1)
            break;
        verify_the_o(map, p_o);
        display_the_map(map, pos_of_p->cols, nb_rows);
        moves(map, filepath, pos_of_p);
    }
    my_popwin((e_o_g == 0) ? e_o_g : n_b);
    end_of_the_game(map, nb_rows, pos_of_p);
    destroy_the_list(p_o, c_l);
    return ((e_o_g == 0) ? e_o_g : n_b);
}

int main(int ac, char **av)
{
    char **lev = level();
    char **music = musics();
    struct music *mus = create_music();

    initscr();
    curs_set(FALSE);
    my_popup();
    sokoban(lev, music, mus);
    sfSound_destroy(mus->loop);
    sfSoundBuffer_destroy(mus->music);
    free(mus);
    free(lev);
    free(music);
    return (0);
}
