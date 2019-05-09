/*
** EPITECH PROJECT, 2018
** libredcode
** File description:
** Encode a redcode file to an executable.
*/

#include "config.h"
#include "redcode.h"
#include "my_string.h"
#include "my_stdlib.h"

static int write_argument(parser_t *parser, const char *str, FILE *dst)
{
    redcode_write(parser, (int []) {my_atoi(str + 1)}, sizeof (int), 1);

    return 0;
}

static int encode(parser_t *parser, char *str, const token_t *token)
{
    char *tok = my_strtok(str + my_strlen(token->name) + 1, (char []) {
        SEPARATOR_CHAR
    });

    redcode_write(parser, &token->code, sizeof token->code, 1);

    while (tok != NULL) {
        write_argument(parser, tok, parser->dest);

        tok = my_strtok(NULL, (char []) {SEPARATOR_CHAR});
    }

    return 0;
}

int redcode_encode(FILE *src, FILE *dst)
{
    char *line = NULL;
    parser_t parser = {0, src, dst};

    redcode_write(&parser, (int []) {REDCODE_HEADER}, sizeof(int), 1);

    if (parse_name(&parser) < 0)
        return -1;
    if (parse_size(&parser) < 0)
        return -1;
    if (parse_comment(&parser) < 0)
        return -1;

    while (readfile(src, &line) >= 0) {
        const token_t *token = get_token(line);

        if (token == NULL)
            return -1;

        encode(&parser, line, token);
    }

    redcode_write(&parser, (off_t []) {parser.offset}, sizeof parser.offset, 1);
    printf("%ld\n", parser.offset);

    return 0;
}
