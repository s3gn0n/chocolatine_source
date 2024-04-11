/*
** EPITECH PROJECT, 2021
** errors_handling.c
** File description:
** Handling of the error cases.
*/

#include "../include/header.h"

void input_errors(int ac, char **av)
{
    int fd = 0;

    if (ac != 2)
        exit (84);
    else if (av[1][0] != '-' && av[1][1] != 'h') {
        fd = open(av[1], O_RDONLY);
        if (fd == -1) {
            close(fd);
            exit (84);
        }
        close(fd);
    }
}

void invalid_maps(int ac, char **av)
{
    FILE *stream = fopen(av[1], "r");
    char *str = NULL;
    int *p_o_x = malloc(sizeof(int)*3);
    size_t no = 0;

    (stream == NULL) ? exit(84) : 0;
    for (ssize_t rd = 0; (rd = getline(&str, &no, stream)) != -1; )
        for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] != '#' && str[i] != 'P' && str[i] != ' ' && str[i] != 'X'
                && str[i] != 'O' && str[i] != '\n') {
                fclose(stream);
                exit (84);
            }
            (str[i] == 'P') ? p_o_x[0]++ : 0;
            (str[i] == 'O') ? p_o_x[1]++ : 0;
            (str[i] == 'X') ? p_o_x[2]++ : 0;
        }
    (p_o_x[0] != 1 || p_o_x[1] != p_o_x[2]) ? exit(84) : 0;
    free(str);
    free(p_o_x);
    fclose(stream);
}

void errors_cases_and_usage(int ac, char **av)
{
    input_errors(ac, av);
    (av[1][0] != '-' && av[1][1] != 'h') ? invalid_maps(ac, av) : usage(ac, av);
}
