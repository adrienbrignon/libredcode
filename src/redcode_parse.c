/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Parse a file.
*/

#include "redcode.h"

parser_t *redcode_parse(FILE *in)
{
    char *line = NULL;
    parser_t *parser = NULL;

    if ((parser = redcode_parser()) == NULL || redcode_setinput(parser, in) < 0)
        return NULL;
    while (readfile(parser->in, &line) != EOF) {
        instruction_t *ins = NULL;
        directive_t *directive = NULL;

        if ((ins = parse_instruction(parser, line)) == NULL)
            return NULL;

        if (ins->mnemonic.name != NULL || ins->label != NULL)
            list_push(parser->instructions, ins);
        else if ((directive = parse_directive(line)) != NULL)
            list_push(parser->directives, directive);
        else
            return NULL;
    }
    return parser;
}
