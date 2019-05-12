/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Check if the comment directive has been defined.
*/

#include "redcode.h"

int has_missing_comment(parser_t *parser)
{
    if (get_directive(parser, COMMENT_STR) == NULL)
        return 1;

    return 0;
}
