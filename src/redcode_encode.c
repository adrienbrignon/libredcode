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

static int encode(parser_t *parser)
{
    node_t *node = parser->instructions->first;

    encode_header(parser);

    while (node != NULL) {
        instruction_t *ins = node->data;

        if (ins->mnemonic.name != NULL) {
            if (encode_instruction(parser, ins) < 0)
                return -1;
        }

        node = node->next;
    }

    return 0;
}

int redcode_encode(FILE *src, FILE *dst)
{
    char *line = NULL;
    parser_t parser = {src, dst, new_list(), new_list(), 0};

    if (parser.instructions == NULL || parser.directives == NULL)
        return -1;
    while (readfile(src, &line) >= 0) {
        instruction_t *ins = NULL;
        directive_t *directive = NULL;

        if ((ins = parse_instruction(&parser, line)) == NULL)
            return -1;
        if (ins->mnemonic.name != NULL || ins->label != NULL)
            list_push(parser.instructions, ins);
        else if ((directive = parse_directive(line)) != NULL)
            list_push(parser.directives, directive);
        else
            return ERROR(-1, "Invalid instruction.");
    }

    return encode_check(&parser) < 0 || encode(&parser) < 0 ? -1 : 0;
}
