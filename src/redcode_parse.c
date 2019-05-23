/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Parse a file.
*/

#include <stdlib.h>

#include "redcode.h"

static parser_t *free_and_return_parser(parser_t *parser, instruction_t *ins)
{
    free((void *) ins->line);
    free((void *) ins->label);
    free((void *) ins);

    return parser;
}

static int push(parser_t *parser, instruction_t *ins, char *line)
{
    directive_t *directive = NULL;

    if (ins->mnemonic.name != NULL || ins->label != NULL)
        return list_push(parser->instructions, ins);
    else if ((directive = parse_directive(line)) != NULL)
        return list_push(parser->directives, directive);

    return -1;
}

parser_t *redcode_parse(FILE *in)
{
    char *line = NULL;
    parser_t *parser = NULL;

    if ((parser = redcode_parser()) == NULL || redcode_setinput(parser, in) < 0)
        return NULL;
    while (readfile(parser->in, &line) != EOF) {
        instruction_t *ins = NULL;

        if ((ins = parse_instruction(parser, line)) == NULL)
            return free_and_return_parser(parser, ins);
        if (push(parser, ins, line) < 0)
            return free_and_return_parser(parser, ins);
    }

    return parser;
}
