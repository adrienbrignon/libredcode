/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Create a new instruction instance.
*/

#include <stdlib.h>

#include "redcode.h"

instruction_t *new_instruction(const char *line)
{
    instruction_t base = {0};
    instruction_t *instruction = NULL;

    if ((instruction = malloc(sizeof *instruction)) == NULL)
        return NULL;

    *instruction = base;
    instruction->line = line;

    return instruction;
}
