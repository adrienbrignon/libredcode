/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Check for invalid instruction arguments.
*/

#include "redcode.h"

int has_invalid_arguments(parser_t *p)
{
    node_t *node = p->instructions->first;

    while (node != NULL) {
        instruction_t *ins = node->data;

        for (size_t i = 0; i < ins->mnemonic.argc; i++) {
            const char *v = ins->argv[i].value;

            if (v == NULL || (ins->mnemonic.argv[i] & ins->argv[i].type) == 0)
                return 1;
            if ((ins->argv[i].type & T_LAB) == T_LAB) {
                if (find_label(p, v) == NULL)
                    return 1;
            }
        }

        node = node->next;
    }

    return 0;
}
