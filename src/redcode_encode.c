/*
** EPITECH PROJECT, 2018
** libredcode
** File description:
** Encode a redcode file to an executable.
*/

#include "redcode.h"

int redcode_encode(FILE *src, FILE *dst)
{
    char *line = NULL;
    parser_t parser = {0, src, dst};

    redcode_header(&parser);

    while (readfile(src, &line) >= 0) {
        instruction_t instruction = parse_instruction(&parser, line);

        if (instruction.mnemonic.name == NULL)
            return -1;

        encode_instruction(&parser, &instruction);
    }

    return 0;
}
