/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Set parser input file.
*/

#include "redcode.h"

int redcode_setinput(parser_t *parser, FILE *in)
{
    if (in == NULL)
        return -1;

    parser->in = in;

    return 0;
}
