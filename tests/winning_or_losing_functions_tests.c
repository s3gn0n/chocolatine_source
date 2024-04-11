/*
** EPITECH PROJECT, 2021
** win_or_lose
** File description:
** Tests my winning and losing functions.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/header.h"

void destroy_2d_array(char **map, int rows);
char **load_2d_array_from_file(char *filepath, int nb_rows);
int none_boxe(char **map, struct pos_p *pos);
void find_the_position_of_p(char **map, struct pos_p *pos);

Test(none_boxe, check_if_these_is_no_more_boxe)
{
    int boxe = 0;
    char **m = load_2d_array_from_file("tests_files/test01", 11);
    char **map = load_2d_array_from_file("tests_files/none_boxe", 11);
    struct pos_p *pos = malloc(sizeof(struct pos_p));

    find_the_position_of_p(m, pos);
    boxe = none_boxe(map, pos);
    cr_assert_eq(boxe, 1);
    destroy_2d_array(map, 11);
    destroy_2d_array(m, 11);
}
