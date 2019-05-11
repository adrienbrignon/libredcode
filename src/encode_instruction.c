/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Encode an instruction.
*/

#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

#include "redcode.h"
#include "my/my_math.h"
#include "my/my_string.h"
#include "my/my_stdlib.h"

static char to_dec(const char *binary)
{
    char result = 0;
    int len = my_strlen(binary);

    for (int counter = 0; counter < len; counter++)
        result += ((binary[len - counter - 1] - '0') * my_pow(2, counter));

    return result;
}

static void coding_byte(parser_t *parser, instruction_t *ins)
{
    size_t i;
    char byte[CHAR_BIT + 1] = {0};

    if (!ins->mnemonic.coding_byte)
        return;
    for (i = 0; i < ins->mnemonic.argc; i++) {
        if ((ins->argv[i].type & T_IND) == T_IND)
            my_strcat(byte, "11");
        if ((ins->argv[i].type & T_DIR) == T_DIR)
            my_strcat(byte, "10");
        if ((ins->argv[i].type & T_REG) == T_REG)
            my_strcat(byte, "01");
    }

    for (; i < 4; i++)
        my_strcat(byte, "00");

    WRITE(parser, (uint8_t []) {strtol(byte, NULL, 2)}, 1, 1);
}

static int encode_label(parser_t *parser, instruction_t *ins, size_t i)
{
    instruction_t *label = find_label(parser, ins->argv[i].value);

    if (label == NULL)
        return (-1);
    if (ins->offset > label->offset) {
        WRITE(parser, (uint8_t []) {0xff}, 1, 1);
        WRITE(parser, (uint8_t []) {256 - (ins->offset - label->offset)}, 1, 1);
    } else {
        WRITE(parser, (uint8_t []) {0}, 1, 1);
        WRITE(parser, (uint8_t []) {(label->offset - ins->offset)}, 1, 1);
    }

    return (0);
}

int encode_instruction(parser_t *parser, instruction_t *ins)
{
    WRITE(parser, (char []) {ins->mnemonic.code}, 1, 1);
    coding_byte(parser, ins);

    for (size_t i = 0; i < ins->mnemonic.argc; i++) {
        if ((ins->argv[i].type & T_LAB) == T_LAB)
            encode_label(parser, ins, i);
        if (ins->argv[i].size == 1)
            WRITE(parser, ENCODE_8(ins->argv[i].value), 1, 1);
        if (ins->argv[i].size == 2 && (ins->argv[i].type & T_LAB) == 0)
            WRITE(parser, ENCODE_16(ins->argv[i].value), 2, 1);
        if (ins->argv[i].size == 4)
            WRITE(parser, ENCODE_32(ins->argv[i].value), 4, 1);
    }

    return 0;
}

