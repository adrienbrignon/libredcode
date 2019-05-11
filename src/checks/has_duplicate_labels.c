/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Check for duplicate labels.
*/

#include "redcode.h"
#include "my/my_string.h"

int has_duplicate_labels(parser_t *parser)
{
    node_t *a = parser->instructions->first;

    while (a != NULL) {
        node_t *b = a->next;
        instruction_t *c = a->data;

        for (; b != NULL; b = b->next) {
            instruction_t *d = b->data;

            if (c->label == NULL || d->label == NULL)
                continue;
            if (my_strcmp(c->label, d->label) == 0)
                return 1;
        }

        a = a->next;
    }

    return 0;
}
