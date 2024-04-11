/*
** EPITECH PROJECT, 2021
** usage.c
** File description:
** Description of the usage of the game.
*/

#include "../include/header.h"

void usage(int ac, char **av)
{
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_putstr("USAGE\n");
        my_putstr("     ./my_sokoban map\n");
        my_putstr("DESCRIPTION\n");
        my_putstr("     map   file representing the warehouse map, containing");
        my_putstr(" '#' for walls,\n");
        my_putstr("           'P' for the player, 'X' for boxes and 'O' ");
        my_putstr("for storage locations.\n");
    }
    exit (0);
}

void next_level(char **lev)
{
    lev[10] = "../tests_files/test11";
    lev[11] = "../tests_files/test12";
    lev[12] = "../tests_files/test13";
    lev[13] = "../tests_files/test14";
    lev[14] = "../tests_files/test15";
    lev[15] = "../tests_files/test16";
    lev[16] = "../tests_files/test17";
    lev[17] = "../tests_files/test18";
    lev[18] = "../tests_files/test19";
    lev[19] = "../tests_files/test20";
    lev[20] = NULL;
}

char **level(void)
{
    char **level = malloc(sizeof(char *)*21);

    level[0] = "../tests_files/test01";
    level[1] = "../tests_files/test02";
    level[2] = "../tests_files/test03";
    level[3] = "../tests_files/test04";
    level[4] = "../tests_files/test05";
    level[5] = "../tests_files/test06";
    level[6] = "../tests_files/test07";
    level[7] = "../tests_files/test08";
    level[8] = "../tests_files/test09";
    level[9] = "../tests_files/test10";
    next_level(level);
    return (level);
}
