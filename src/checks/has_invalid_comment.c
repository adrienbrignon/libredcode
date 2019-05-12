/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Check if the comment directive is valid.
*/

#include "redcode.h"
#include "my/my_string.h"

int has_invalid_comment(parser_t *parser)
{
    directive_t *directive = NULL;

    if ((directive = get_directive(parser, COMMENT_STR)) == NULL)
        return 1;
    if (directive->value == NULL)
        return 1;
    if (my_strlen(directive->value) > COMMENT_LENGTH)
        return 1;

    return 0;
}
