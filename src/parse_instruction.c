/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Get instruction at the given line.
*/

#include <stdlib.h>

#include "redcode.h"
#include "my/my_string.h"

static int get_arguments(instruction_t *ins, char *line)
{
    size_t i;
    char *str = NULL;
    char *arg = NULL;

    str = line + my_strlen(ins->mnemonic.name) + 1;
    str += ins->label != NULL ? my_strlen(ins->label) + 1 : 0;
    arg = my_strtok(str, (char []) {SEPARATOR_CHAR, '\0'});

    for (i = 0; i < ins->mnemonic.argc && arg != NULL; i++) {
        ins->argv[i] = get_argument(ins->mnemonic.argv[i], arg);
        ins->size = ins->size + ins->argv[i].size;
        arg = my_strtok(NULL, (char []) {SEPARATOR_CHAR, '\0'});
    }

    if (arg != NULL || i < ins->mnemonic.argc)
        return -1;

    return 0;
}

instruction_t *parse_instruction(parser_t *parser, char *str)
{
    instruction_t *ins = NULL;
    size_t len = my_strcspn(str, (char []) {LAB_CHAR, '\0'});

    if ((ins = new_instruction()) == NULL)
        return NULL;
    if (str[len] == ':' && (str[len + 1] == ' ' || str[len + 1] == '\0'))
        if ((ins->label = my_strndup(str, len)) == NULL)
            return NULL;

    ins->mnemonic = get_mnemonic(ins->label ? str + len + 1 : str);

    if (ins->mnemonic.name != NULL && get_arguments(ins, str) < 0)
        return NULL;

    ins->offset = parser->size;

    if (ins->mnemonic.name != NULL)
        parser->size = parser->size + ins->size + 1 + ins->mnemonic.coding_byte;

    return ins;
}
