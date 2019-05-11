/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Encode header.
*/

#include "redcode.h"
#include "my/my_string.h"

void encode_header(parser_t *parser)
{
    directive_t *name = get_directive(parser, "name");
    directive_t *comment = get_directive(parser, "comment");

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
}
