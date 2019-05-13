/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Check for invalid directives.
*/

#include "redcode.h"
#include "my/my_string.h"

int has_invalid_directives(parser_t *parser)
{
    node_t *node = parser->directives->first;

    for (; node != NULL; node = node->next) {
        directive_t *directive = node->data;

        if (directive->name == NULL || directive->value == NULL)
            return 1;
        if (my_strcmp(directive->name, NAME_STR) == 0)
            continue;
        if (my_strcmp(directive->name, COMMENT_STR) == 0)
            continue;

        return 1;
    }

    return 0;
}
