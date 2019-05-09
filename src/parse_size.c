/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Parse program size.
*/

#include "redcode.h"
#include "my_string.h"
#include "my_stdlib.h"
#include <sys/types.h>
#include <byteswap.h>
#include <unistd.h>

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

static int get_prog_size(char *str, const token_t *token)
{
    char *tok = NULL;
    char *start = str + my_strlen(token->name) + 1;
    int counter = 0;

    tok = my_strtok(start, ", ");
    for (size_t i = 0; tok != NULL; i++) {
        argument_t argument = get_argument(tok);
        counter += argument.size;
        tok = my_strtok(NULL, ", ");
    }
    return counter;
}

int parse_size(parser_t *parser)
{
    char *line = NULL;
    int counter = 0;

    while (readfile(parser->src, &line) >= 0) {
        const token_t *token = get_token(line);
        if (token != NULL)
            counter += get_prog_size(line, token);
    }
    redcode_write(parser, (int []) {bswap_32(counter)},sizeof(int),1);
    fseek(parser->src, 0, SEEK_SET);
    return 0;
}