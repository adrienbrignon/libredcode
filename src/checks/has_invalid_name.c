/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Check if the name directive is valid.
*/

#include "redcode.h"
#include "my/my_string.h"

int has_invalid_name(parser_t *parser)
{
    directive_t *directive = NULL;

    if ((directive = get_directive(parser, NAME_STR)) == NULL)
        return 1;
    if (my_strlen(directive->value) > NAME_LENGTH)
        return 1;

    return 0;
}
