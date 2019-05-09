/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** encode_metadata
*/

#include <limits.h>
#include <byteswap.h>

#include "config.h"
#include "redcode.h"
#include "my_string.h"

static void pad(parser_t *parser, FILE *dst, size_t length)
{
    for (size_t i = 0; i < length; i++)
        redcode_write(parser, (char []) {0}, sizeof (char), 1);
}

int encode_comment(parser_t *parser, char *str, FILE *dst)
{
    size_t len = 0;
    char *value = NULL;
    char *tok = my_strtok(str, " ");

    if (tok == NULL || *(tok + my_strlen(tok) + 1) == '\0')
        return -1;

    value = tok + my_strlen(tok) + 1;
    len = my_strlen(value);

    if (len == 0 || value[0] != '"' || value[len - 1] != '"')
        return -1;

    redcode_write(parser, (int []) {bswap_32(len - 2)}, sizeof (int), 1);
    redcode_write(parser, value + 1, sizeof (char), len - 2);
    pad(parser, dst, COMMENT_LENGTH - ((len - 2) * CHAR_BIT));

    return 0;
}
