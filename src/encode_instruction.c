/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Encode an instruction.
*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

#include "redcode.h"
#include "my/my_math.h"
#include "my/my_string.h"
#include "my/my_stdlib.h"

static uint8_t get_dec(const char *binary)
{
    uint8_t result = 0;
    size_t len = my_strlen(binary);

    for (size_t counter = 0; counter < len; counter++)
        result += ((binary[len - counter - 1] - '0') * my_pow(2, counter));

    return result;
}

static void coding_byte(parser_t *parser, instruction_t *ins)
{
    size_t i = 0;
    char byte[sizeof (uint64_t) + 1] = {0};

    if (!ins->mnemonic.coding_byte)
        return;
    for (; i < ins->mnemonic.argc; i++) {
        if ((ins->argv[i].type & T_IND) == T_IND)
            my_strcat(byte, "11");
        if ((ins->argv[i].type & T_DIR) == T_DIR)
            my_strcat(byte, "10");
        if ((ins->argv[i].type & T_REG) == T_REG)
            my_strcat(byte, "01");
    }

    for (; i < sizeof (uint32_t); i++)
        my_strcat(byte, "00");

    WRITE(parser, (uint8_t []) {get_dec(byte)}, 1, 1);
}

int encode_instruction(parser_t *parser, instruction_t *ins)
{
    WRITE(parser, (char []) {ins->mnemonic.code}, 1, 1);
    coding_byte(parser, ins);

    for (size_t i = 0; i < ins->mnemonic.argc; i++) {
        if ((ins->argv[i].type & T_LAB) == T_LAB) {
            if (encode_label(parser, ins, ins->argv[i].value) < 0)
                return -1;
        }

        if (ins->argv[i].size == 1)
            WRITE(parser, ENCODE_8(ins->argv[i].value), 1, 1);
        if (ins->argv[i].size == 2 && (ins->argv[i].type & T_LAB) == 0)
            WRITE(parser, ENCODE_16(ins->argv[i].value), 2, 1);
        if (ins->argv[i].size == 4)
            WRITE(parser, ENCODE_32(ins->argv[i].value), 4, 1);
    }

    return 0;
}