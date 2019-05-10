/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Get instruction at the given line.
*/

#include "redcode.h"
#include "my/my_string.h"

static int get_arguments(parser_t *parser, instruction_t *ins, char *line)
{
    char *str = NULL;
    char *arg = NULL;

    if (ins->mnemonic.name == NULL)
        return -1;

    str = line + my_strlen(ins->mnemonic.name) + 1;
    arg = my_strtok(str, (char []) {SEPARATOR_CHAR});

    for (size_t i = 0; i < MAX_ARGS && arg != NULL; i++) {
        ins->argv[i] = get_argument(arg);
        ins->size = ins->size + ins->argv[i].size;
        arg = my_strtok(NULL, (char []) {SEPARATOR_CHAR});
    }

    return 0;
}

instruction_t parse_instruction(parser_t *parser, char *line)
{
    instruction_t ins = {0};

    ins.mnemonic = get_mnemonic(line);

    if (get_arguments(parser, &ins, line) < 0)
        return ins;

    return ins;
}
