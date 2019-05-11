/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Check for duplicate directives.
*/

#include "redcode.h"
#include "my/my_string.h"

int has_duplicate_directives(parser_t *parser)
{
    node_t *a = parser->directives->first;

    while (a != NULL) {
        node_t *b = a->next;
        directive_t *c = a->data;

        while (b != NULL) {
            directive_t *d = b->data;

            if (my_strcmp(c->name, d->name) == 0)
                return 1;

            b = b->next;
        }

        a = a->next;
    }

    return 0;
}
