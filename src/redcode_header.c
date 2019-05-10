/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Write header to file.
*/

#include <stdint.h>
#include <limits.h>

#include "redcode.h"
#include "my/my_string.h"

static int write_header(parser_t *parser, char *line, size_t length)
{
    size_t len = 0;
    char *value = NULL;
    char *tok = my_strtok(line, " ");

    if (tok == NULL || *(tok + my_strlen(tok) + 1) == '\0')
        return -1;

    value = tok + my_strlen(tok) + 1;
    len = my_strlen(value);

    if (len == 0 || value[0] != '"' || value[len - 1] != '"')
        return -1;

    redcode_write(parser, value + 1, sizeof (char), len - 2);

    for (size_t i = 0; i < length; i++)
        redcode_write(parser, (uint8_t []) {0}, 1, 1);

    return 0;
}

static off_t parse_name(parser_t *parser)
{
    char *line = NULL;
    size_t len = my_strlen(NAME_STR);

    while (readfile(parser->in, &line) != EOF) {
        if (my_strncmp(line, NAME_STR, len) == 0 && line[len] == ' ')
            return write_header(parser, line, NAME_LENGTH);
    }

    return -1;
}

static off_t parse_comment(parser_t *parser)
{
    char *line = NULL;
    size_t len = my_strlen(COMMENT_STR);

    while (readfile(parser->in, &line) != EOF) {
        if (my_strncmp(line, COMMENT_STR, len) == 0 && line[len] == ' ')
            return write_header(parser, line, COMMENT_LENGTH - 4);
    }

    return -1;
}

int redcode_header(parser_t *parser)
{
    parser_reset(parser);
    redcode_write(parser, (int []) {REDCODE_HEADER}, sizeof (int), 1);

    if (parse_name(parser) < 0 || parse_size(parser) < 0)
        return -1;
    if (parse_comment(parser) < 0)
        return -1;

    for (size_t i = 0; i < (COMMENT_LENGTH / CHAR_BIT); i++)
        redcode_write(parser, (char []) {0}, sizeof (char), 1);

    return parser->offset;
}
