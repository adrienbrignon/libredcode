/*
** EPITECH PROJECT, 2018
** corewar
** File description:
** Create a new directive instance.
*/

#include <stdlib.h>

#include "types.h"

directive_t *new_directive(const char *str)
{
    directive_t dir = {0};
    directive_t *directive = NULL;

    if ((directive = malloc(sizeof *directive)) == NULL)
        return NULL;

    *directive = dir;
    directive->line = str;

    return directive;
}
