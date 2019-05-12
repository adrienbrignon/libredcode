/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Encode a label.
*/

#include "redcode.h"

int encode_label(parser_t *parser, instruction_t *ins, size_t i)
{
    instruction_t *label = find_label(parser, ins->argv[i].value);

    if (label == NULL)
        return -1;

    WRITE(parser, (uint16_t []) {SWAP_16(label->offset - ins->offset)}, 2, 1);

    if (ins->argv[i].size == 4)
        WRITE(parser, (uint16_t []) {0}, 2, 1);

    return 0;
}
