/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Check for invalid labels.
*/

#include "redcode.h"
#include "my/my_string.h"

int has_invalid_labels(parser_t *parser)
{
    node_t *node = parser->instructions->first;

    for (; node != NULL; node = node->next) {
        instruction_t *ins = node->data;

        if (ins->label == NULL)
            continue;
        if (my_strspn(ins->label, LAB_CHARS) != my_strlen(ins->label)) {
            return 1;
        }
    }

    return 0;
}
