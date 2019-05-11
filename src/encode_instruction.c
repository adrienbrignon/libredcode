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
#include "my/my_string.h"
#include "my/my_stdlib.h"

static void coding_byte(parser_t *parser, instruction_t *ins)
{
    char byte[CHAR_BIT + 1] = {0};

    for (size_t i = 0; i < ins->mnemonic.argc; i++) {
        if ((ins->argv[i].type & T_IND) == T_IND)
            my_strcat(byte, "11");
        if ((ins->argv[i].type & T_DIR) == T_DIR)
            my_strcat(byte, "10");
        if ((ins->argv[i].type & T_REG) == T_REG)
            my_strcat(byte, "01");
    }

    my_strcat(byte, "00");
    WRITE(parser, (uint8_t []) {strtol(byte, NULL, 2)}, 1, 1);
}

int encode_instruction(parser_t *parser, instruction_t *ins)
{
    WRITE(parser, (char []) {ins->mnemonic.code}, 1, 1);
    coding_byte(parser, ins);

    for (size_t i = 0; i < ins->mnemonic.argc; i++) {
        if (ins->argv[i].size == 1)
            WRITE(parser, ENCODE_8(ins->argv[i].value), 1, 1);
        if (ins->argv[i].size == 2)
            WRITE(parser, ENCODE_16(ins->argv[i].value), 2, 1);
        if (ins->argv[i].size == 4)
            WRITE(parser, ENCODE_32(ins->argv[i].value), 4, 1);
    }

    return 0;
}

