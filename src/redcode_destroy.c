/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Destroy a parser instance.
*/

#include <stdlib.h>
#include <stdio.h>

#include "redcode.h"

static void free_directives(list_t *directives)
{
    node_t *node = directives->first;

    while (node != NULL) {
        node_t *next = node->next;
        directive_t *directive = node->data;

        free((void *) directive->name);
        free((void *) directive->value);
        free((void *) directive->line);
        free(directive);

        node = next;
    }
}

static void free_instructions(list_t *instructions)
{
    node_t *node = instructions->first;

    while (node != NULL) {
        node_t *next = node->next;
        instruction_t *ins = node->data;

        free((void *) ins->label);
        free((void *) ins->line);
        free(ins);

        node = next;
    }
}


int redcode_destroy(parser_t *parser)
{
    if (parser->directives != NULL) {
        free_directives(parser->directives);
        list_destroy(parser->directives);
    }

    if (parser->instructions != NULL) {
        free_instructions(parser->instructions);
        list_destroy(parser->instructions);
    }

    free(parser);

    return 0;
}
