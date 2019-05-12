/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Check if the name directive has been defined.
*/

#include "redcode.h"
#include "my/my_string.h"

int has_missing_name(parser_t *parser)
{
    if (get_directive(parser, NAME_STR) == NULL)
        return 1;

    return 0;
}
