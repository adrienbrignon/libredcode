/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Check for errors before encoding.
*/

#include "redcode.h"
#include "my/my_string.h"

static int messy_directives(parser_t *parser)
{
    node_t *node = parser->directives->first;

    while (node != NULL) {
        directive_t *directive = node->data;

        if (my_strcmp(directive->name, NAME_STR) == 0)
            break;
        if (my_strcmp(directive->name, COMMENT_STR) == 0)
            return 1;

        node = node->next;
    }

    return 0;
}

static int has_invalid_directives(parser_t *parser)
{
    node_t *node = parser->directives->first;

    for (; node != NULL; node = node->next) {
        directive_t *directive = node->data;

        if (my_strcmp(directive->name, NAME_STR) == 0)
            continue;
        if (my_strcmp(directive->name, COMMENT_STR) == 0)
            continue;

        return 1;
    }

    return 0;
}

static int has_duplicates_directives(parser_t *parser)
{
    node_t *a = parser->directives->first;

    while (a != NULL) {
        node_t *b = a->next;
        directive_t *c = a->data;

        while (b != NULL) {
            directive_t *d = b->data;

            if (my_strcmp(c->name, d->name) == 0)
                return 1;

            b = b->next;
        }

        a = a->next;
    }

    return 0;
}

int encode_check(parser_t *parser)
{
    if (get_directive(parser, "name") == NULL)
        return ERROR(-1, "No name specified.");
    if (get_directive(parser, "comment") == NULL)
        return ERROR(-1, "No comment specified.");
    if (has_invalid_directives(parser))
        return ERROR(-1, "Invalid directive.");
    if (has_duplicates_directives(parser))
        return ERROR(-1, "Duplicate directives found.");
    if (messy_directives(parser))
        return ERROR(-1, "The comment must be after the name.");

    return 0;
}

