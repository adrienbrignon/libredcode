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
#include <byteswap.h>

static int write_argument(parser_t *parser, char *str, FILE *dst, int size)
{
    for (int i = 1; i < size; i++)
        redcode_write(parser, (char []) {0}, sizeof(char), 1);
    redcode_write(parser, (char []) {my_atoi(str + 1)}, sizeof(char), 1);
    return 0;
}

static argument_t get_argument(char *line)
{
    if (*line == '%' || *line == 'r')
        return (argument_t) {
            *line == '%' ? T_DIR : T_REG,
            *line == '%' ? DIR_SIZE : *line == 'r' ? REG_SIZE : IND_SIZE,
            line + 1,
         };

    return (argument_t) {T_IND, IND_SIZE, line};
}

static int encode(parser_t *parser, char *str, const token_t *token)
{
    char *tok = my_strtok(str + my_strlen(token->name) + 1, (char []) {
        SEPARATOR_CHAR
    });

    redcode_write(parser, &token->code, sizeof token->code, 1);

    while (tok != NULL) {
        argument_t argument = get_argument(tok);
        printf("%ld\n", argument.size);
        write_argument(parser, tok, parser->dest, argument.size);

        tok = my_strtok(NULL, (char []) {SEPARATOR_CHAR});
    }

    return 0;
}

int redcode_encode(FILE *src, FILE *dst)
{
    char *line = NULL;
    parser_t parser = {0, 0, src, dst};

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

    return 0;
}
