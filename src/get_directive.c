/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Get a directive by it name.
*/

#include "redcode.h"
#include "my/my_string.h"

directive_t *get_directive(parser_t *parser, const char *name)
{
    node_t *node = parser->directives->first;

    while (node != NULL) {
        directive_t *directive = node->data;

        if (my_strcmp(directive->name, name) == 0) {
            if (directive->value == NULL)
                return NULL;

            return directive;
        }

        node = node->next;
    }

    return NULL;
}
