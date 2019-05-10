/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Encode an instruction.
*/

#include <stdint.h>
#include <stdlib.h>
#include <limits.h>
#include <byteswap.h>

#include "redcode.h"
#include "my/my_string.h"
#include "my/my_stdlib.h"

static char *coding_byte(parser_t *parser, instruction_t *ins)
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
    redcode_write(parser, (char []) {strtol(byte, NULL, 2)}, 1, 1);

    return NULL;
}

int encode_instruction(parser_t *parser, instruction_t *ins)
{
    redcode_write(parser, (char []) {ins->mnemonic.code}, 1, 1);

    coding_byte(parser, ins);

    return 0;
}

