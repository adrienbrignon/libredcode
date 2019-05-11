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

static int encode_header(parser_t *parser)
{
    directive_t *name = get_directive(parser, "name");
    directive_t *comment = get_directive(parser, "comment");

    if (name == NULL || comment == NULL)
        return -1;

    WRITE(parser, (uint32_t []) {REDCODE_HEADER}, 4, 1);
    WRITE(parser, name->value, 1, my_strlen(name->value));

    for (size_t i = my_strlen(name->value); i < NAME_LENGTH; i++)
        WRITE(parser, (uint8_t []) {0}, 1, 1);

    WRITE(parser, (uint32_t []) {0}, 4, 1);
    WRITE(parser, (uint32_t []) {__bswap_32(parser->size)}, 4, 1);
    WRITE(parser, comment->value, 1, my_strlen(comment->value));

    for (size_t i = my_strlen(comment->value); i < COMMENT_LENGTH; i++)
        WRITE(parser, (uint8_t []) {0}, 1, 1);

    WRITE(parser, (uint32_t []) {0}, 4, 1);

    return 0;
}

static int encode(parser_t *parser)
{
    node_t *node = parser->instructions->first;

    encode_header(parser);

    while (node != NULL) {
        instruction_t *ins = node->data;

        if (ins->mnemonic.name != NULL)
            encode_instruction(parser, ins);

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
    }

    encode(&parser);

    return 0;
}
