/*
** EPITECH PROJECT, 2021
** my_sokoban.c
** File description:
** Main file.
*/

#include "../include/header.h"

void start_the_game(char **map, struct pos_p *pos, int rows)
{
    find_the_position_of_p(map, pos);
    pos->rows = rows;
    pos->cols = biggest_number_of_columns(map);
    initscr();
    noecho();
    curs_set(FALSE);
    keypad(stdscr, TRUE);
}

void end_of_the_game(char **map, int nb_rows, struct pos_p *pos_of_p)
{
    endwin();
    destroy_2d_array(map, nb_rows);
    free(pos_of_p);
}

void my_sokoban(int ac, char **av, int nb_rows)
{
    int e_o_g = 1;
    int n_b = 0;
    char **map = load_2d_array_from_file(av[1], nb_rows);
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
        moves(map, av[1], pos_of_p);
    }
    end_of_the_game(map, nb_rows, pos_of_p);
    destroy_the_list(p_o, c_l);
    (e_o_g == 0) ? exit(e_o_g) : exit(n_b);
}

int main(int ac, char **av)
{
    int win_or_lose = 0;
    int lines = 0;
    char *ma = 0;

    errors_cases_and_usage(ac, av);
    ma = load_file_in_mem(av[1]);
    lines = number_of_lines(ma);
    free(ma);
    my_sokoban(ac, av, lines);
    return (0);
}
