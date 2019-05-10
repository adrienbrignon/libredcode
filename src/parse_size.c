/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Parse program size.
*/

#include <unistd.h>
#include <byteswap.h>
#include <sys/types.h>

#include "redcode.h"
#include "my/my_string.h"
#include "my/my_stdlib.h"

int parse_size(parser_t *parser)
{
    char *line = NULL;
    size_t counter = 0;

    while (readfile(parser->in, &line) >= 0) {
        instruction_t instruction = parse_instruction(parser, line);

        if (instruction.mnemonic.name == NULL)
            continue;

        counter += instruction.size + 2;
    }

    redcode_write(parser, (int []) {bswap_32(counter)},sizeof(int),1);
    parser_reset(parser);

    return 0;
}
