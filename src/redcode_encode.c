/*
** EPITECH PROJECT, 2018
** libredcode
** File description:
** Encode a redcode file to an executable.
*/

#include <stdint.h>
#include <stdlib.h>

#include "redcode.h"
#include "my/my_ctype.h"
#include "my/my_string.h"

int redcode_encode(parser_t *parser)
{
    node_t *node = parser->instructions->first;

    if (parser->out == NULL)
        return -1;

    encode_header(parser);

    while (node != NULL) {
        instruction_t *ins = node->data;

        if (ins->mnemonic.name != NULL && encode_instruction(parser, ins) < 0)
            return -1;

        node = node->next;
    }

    return 0;
}
