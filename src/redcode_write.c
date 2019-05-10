/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Write to output and store offset.
*/

#include "redcode.h"

size_t redcode_write(parser_t *parser, const void *ptr, size_t size, size_t n)
{
    return fwrite(ptr, size, n, parser->out);
}
