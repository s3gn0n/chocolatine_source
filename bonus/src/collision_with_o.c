/*
** EPITECH PROJECT, 2021
** collision_with_o.c
** File description:
** Manage collision with O
*/

#include "../include/header.h"

struct o_p *create_list(void)
{
    return (NULL);
}

struct o_p *add_element(struct o_p *p_o, int r, int c)
{
    struct o_p *temp = p_o;
    struct o_p *next_o = malloc(sizeof(struct o_p));
    next_o->row = r;
    next_o->col = c;
    next_o->next = NULL;

    if (p_o == NULL)
        return (next_o);
    for ( ; temp->next != NULL; temp = temp->next);
    temp->next = next_o;
    return (p_o);
}

void destroy_the_list(struct o_p *p_o, struct c_list *c_l)
{
    struct o_p *temp = c_l->begin;

    for (p_o = c_l->begin; p_o != NULL; ) {
        temp = p_o;
        p_o = p_o->next;
        free(temp);
    }
    free(c_l);
}

struct o_p *check_the_o(char **map)
{
    struct o_p *p_o = create_list();

    for (int r = 0; map[r] != NULL; r++)
        for (int c = 0; map[r][c] != '\0'; c++)
            if (map[r][c] == 'O')
                p_o = add_element(p_o, r, c);
    return (p_o);
}

void verify_the_o(char **map, struct o_p *p_o)
{
    for ( ; p_o != NULL; p_o = p_o->next)
        if (map[p_o->row][p_o->col] == ' ')
            map[p_o->row][p_o->col] = 'O';
}
