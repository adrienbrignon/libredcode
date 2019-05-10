/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Write header to file.
*/

#include <limits.h>

#include "redcode.h"

int redcode_header(parser_t *parser)
{
    redcode_write(parser, (int []) {REDCODE_HEADER}, sizeof (int), 1);

    for (size_t i = 0; i < (NAME_LENGTH / CHAR_BIT); i++)
        redcode_write(parser, (char []) {0}, sizeof (char), 1);
    for (size_t i = 0; i < (COMMENT_LENGTH / CHAR_BIT); i++)
        redcode_write(parser, (char []) {0}, sizeof (char), 1);

    return 0;
}
