/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Check for messy directives.
*/

#include "redcode.h"

#include "my/my_string.h"

int has_messy_directives(parser_t *parser)
{
    node_t *node = parser->directives->first;

    while (node != NULL) {
        directive_t *directive = node->data;

        if (my_strcmp(directive->name, NAME_STR) == 0)
            break;
        if (my_strcmp(directive->name, COMMENT_STR) == 0)
            return 1;

        node = node->next;
    }

    return 0;
}
