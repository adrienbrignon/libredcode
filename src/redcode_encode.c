/*
** EPITECH PROJECT, 2018
** libredcode
** File description:
** Encode a redcode file to an executable.
*/

#include <string.h>
#include "redcode.h"
#include "my_string.h"
#include <stddef.h>

char *my_getline(FILE *src)
{
    size_t n = 0;
    char *line = NULL;

    while (getline(&line, &n, src) >= 0) {
        if (line != NULL && *line != '\0' && *line != '#') {
            return line;
        }
    }
    return NULL;
}

argument_t get_argument(char *line)
{
    if (*line == '%' || *line == 'r')
        return (argument_t) {*line == '%' ? T_DIR : T_REG, line + 1};
    return (argument_t) {T_IND, line};
}

static int encode_token(char *str, const token_t *token, FILE *fp)
{
    char *tok = NULL;
    char *start = str + my_strlen(token->name) + 1;

    fwrite(&token->code, sizeof token->code, 1, fp);
    tok = my_strtok(start, ", ");
    for (size_t i = 0; tok != NULL; i++) {
        if ((token->type[i] & get_argument(tok).type) == 0)
            return -1;
        tok = my_strtok(NULL, ", ");
    }
    return 0;
}

int redcode_encode(FILE *src, FILE *dst)
{
    char *line = NULL;

    fwrite((int[]) {REDCODE_HEADER}, sizeof(int), 1, dst);
    if (parse_name(src, dst) != 0)
        return -1;
    if (parse_comment(src, dst) != 0)
        return -1;
    while (readfile(src, &line) >= 0) {
        const token_t *token = get_token(line);
        if (token == NULL)
            return -1;
        encode_token(line, token, dst);
    }
    return 0;
}
