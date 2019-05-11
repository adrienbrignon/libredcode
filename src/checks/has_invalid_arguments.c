/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Check for invalid instruction arguments.
*/

#include "redcode.h"

int has_invalid_arguments(parser_t *parser)
{
    node_t *node = parser->instructions->first;

    while (node != NULL) {
        instruction_t *instruction = node->data;

        for (size_t i = 0; i < instruction->mnemonic.argc; i++) {
            if (instruction->argv[i].value == NULL)
                return 1;
            if ((instruction->argv[i].type & T_LAB) == T_LAB) {
                if (find_label(parser, instruction->argv[i].value) == NULL)
                    return 1;
            }
        }

        node = node->next;
    }

    return 0;
}
