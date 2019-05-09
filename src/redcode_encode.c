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

static int write_argument(const char *str, FILE *dst)
{
    fwrite((int []) {my_atoi(str + 1)}, sizeof (int), 1, dst);

    return 0;
}

static int encode(char *str, const token_t *token, FILE *dst)
{
    char *tok = my_strtok(str + my_strlen(token->name) + 1, (char []) {
        SEPARATOR_CHAR
    });

    fwrite(&token->code, sizeof token->code, 1, dst);

    while (tok != NULL) {
        write_argument(tok, dst);

        tok = my_strtok(NULL, (char []) {SEPARATOR_CHAR});
    }

    return 0;
}

int redcode_encode(FILE *src, FILE *dst)
{
    char *line = NULL;

    fwrite((int[]) {REDCODE_HEADER}, sizeof(int), 1, dst);

    if (parse_name(src, dst) < 0 || parse_comment(src, dst) < 0)
        return -1;
    while (readfile(src, &line) >= 0) {
        const token_t *token = get_token(line);

        if (token == NULL)
            return -1;

        encode(line, token, dst);
    }

    return 0;
}
