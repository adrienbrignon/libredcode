/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Reset parser offset to the beginning.
*/

#include "redcode.h"

int parser_reset(parser_t *parser)
{
    if (fseek(parser->in, 0, SEEK_SET) < 0)
        return -1;

    parser->offset = 0;

    return 0;
}
