/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** parse_comment
*/

#include "redcode.h"
#include "my_string.h"

int parse_comment(parser_t *parser)
{
    char *line = NULL;
    if (readfile(parser->src, &line) < 0)
        return -1;
    if (readfile(parser->src, &line) < 0)
        return -1;
    if (my_strncmp(line, COMMENT_STR, my_strlen(COMMENT_STR)) == 0)
        return encode_comment(parser, line, parser->dest);
    return -1;
}
