/*
** EPITECH PROJECT, 2021
** maps_functions.c
** File description:
** Contains all the functions about the map.
*/

#include "../include/header.h"

char *load_file_in_mem(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer;
    struct stat bf;

    stat(filepath, &bf);
    buffer = malloc(sizeof(char)*(bf.st_size));
    read(fd, buffer, bf.st_size);
    close(fd);
    return (buffer);
}

int number_of_lines(char *map)
{
    int lines = 0;

    for (int i = 0; map[i] != '\0'; i++)
        if (map[i] == '\n')
            lines++;
    return (lines);
}

int biggest_number_of_columns(char **map)
{
    int r = 0;
    int c = 0;
    int columns = 0;

    for (r = 0; map[r] != NULL; r++) {
        for (c = 0; map[r][c] != '\0'; c++);
        (c > columns) ? columns = c : 0;
    }
    return (columns);
}

void destroy_2d_array(char **map, int nb_rows)
{
    for (int i = 0; i < nb_rows; i++)
        free(map[i]);
    free(map);
}
