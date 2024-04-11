/*
** EPITECH PROJECT, 2021
** test.c
** File description:
** Test functions.
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../include/header.h"

void find_the_position_of_p(char **map, struct pos_p *pos);
void my_putchar(char c);
void my_putstr(char *str);
int my_getnbr(char *str);
int my_strlen(char *str);
int biggest_number_of_columns(char **map);
int number_of_lines(char *map);
char *load_file_in_mem(char *filepath);
char **load_2d_array_from_file(char *filepath, int nb_rows);

void redirect_all_std(void)
{
    cr_redirect_stdout();
}

Test(essentials_functions, basics_functions, .init = redirect_all_std)
{
    int len = my_strlen("My sokoban\n");
    int year = my_getnbr("2021");

    my_putstr("My sokoban\n");
    cr_assert_stdout_eq_str("My sokoban\n");
    cr_assert_eq(year, 2021);
    cr_assert_eq(len, 11);
}

Test(maps_functions_part_a, load_file_in_mem_number_of_lines_and_biggest_column)
{
    char *file = load_file_in_mem("tests_files/test01");
    int nb_rows = number_of_lines(file);
    char **map = load_2d_array_from_file("tests_files/map1_1", 29);
    int col = biggest_number_of_columns(map);

    cr_assert_eq(nb_rows, 11);
    cr_assert_eq(col, 81);
    free(file);
    destroy_2d_array(map, 29);
}

Test(load_2d_arr_from_file, 1d_array_in_2d_array)
{
    char **map = load_2d_array_from_file("tests_files/test01", 11);

    cr_assert_str_eq("############\n", map[0]);
    cr_assert_str_eq("#        O #\n", map[1]);
    cr_assert_str_eq("#   P   ####\n", map[2]);
    cr_assert_str_eq("#          #\n", map[3]);
    cr_assert_str_eq("#######    #\n", map[4]);
    cr_assert_str_eq("#  O ##    #\n", map[5]);
    cr_assert_str_eq("#    ##    #\n", map[6]);
    cr_assert_str_eq("#          #\n", map[7]);
    cr_assert_str_eq("#       XX #\n", map[8]);
    cr_assert_str_eq("#       #  #\n", map[9]);
    cr_assert_str_eq("############\n", map[10]);
    destroy_2d_array(map, 11);
}

Test(find_the_position_of_p, Position_of_p)
{
    char **map = load_2d_array_from_file("tests_files/test01", 11);
    struct pos_p *p = malloc(sizeof(struct pos_p));

    find_the_position_of_p(map, p);
    cr_assert_eq(p->row, 2);
    cr_assert_eq(p->col, 4);
    cr_assert_eq(p->nb_x, 2);
    free(p);
    destroy_2d_array(map, 11);
}
