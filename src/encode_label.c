/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Encode a label.
*/

#include "redcode.h"

int encode_label(parser_t *parser, instruction_t *ins, const char *name)
{
    instruction_t *label = find_label(parser, name);

    if (label == NULL)
        return -1;

    WRITE(parser, (uint16_t []) {SWAP_16(label->offset - ins->offset)}, 2, 1);

    return 0;
}
