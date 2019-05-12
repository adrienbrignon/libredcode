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
        instruction_t *ins = node->data;

        for (size_t i = 0; i < ins->mnemonic.argc; i++) {
            if (ins->argv[i].value == NULL) {
                printf("=>%s\n", ins->argv[i + 1].value);
                return 1;
            }
            if ((ins->mnemonic.argv[i] & ins->argv[i].type) == 0) {
                printf("aha2\n");
                return 1;
            }
            if ((ins->argv[i].type & T_LAB) == T_LAB) {
                if (find_label(parser, ins->argv[i].value) == NULL) {
                printf("aha3\n");
                    return 1;
                }
            }
        }

        node = node->next;
    }

    return 0;
}
