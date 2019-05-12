/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Set the output file.
*/

#include "redcode.h"

int redcode_setoutput(parser_t *parser, FILE *out)
{
    if (out == NULL)
        return -1;

    parser->out = out;

    return 0;
}
