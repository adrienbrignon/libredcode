/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Get a label by its name.
*/

#include "redcode.h"
#include "my/my_string.h"

instruction_t *find_label(parser_t *parser, const char *name)
{
    node_t *node = parser->instructions->first;

    while (node != NULL) {
        instruction_t *ins = node->data;

        if (ins->label != NULL && my_strcmp(ins->label, name) == 0) {
            return ins;
        }

        node = node->next;
    }

    return NULL;
}
