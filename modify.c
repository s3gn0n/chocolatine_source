/*
** EPITECH PROJECT, 2021
** modify.c
** File description:
** Modify
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int fd = open(av[1], O_RDWR);
    int f = 0;
    char *map = NULL;
    struct stat bf;

    stat(av[1], &bf);
    map = malloc(sizeof(char)*(bf.st_size));
    read(fd, map, bf.st_size);
    close(fd);
    for (int i = 0; map[i] != '\0'; i++) {
        (map[i] == 'X') ? map[i] = '#' : 0;
        (map[i] == '@') ? map[i] = 'P' : 0;
        (map[i] == '.') ? map[i] = 'O' : 0;
        (map[i] == '*') ? map[i] = 'X' : 0;
    }
    f = open(av[1], O_RDWR);
    write(f, map, bf.st_size);
    close(f);
    free(map);
    return (0);
}
