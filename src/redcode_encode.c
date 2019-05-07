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

static const token_t tokens[] = {
    {"live", 1, {T_DIR}, 0x01, 10},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 0x0B, 25},
    {"st", 2, {T_REG, T_IND | T_REG}, 0x03, 5},
    {"add", 3, {T_REG, T_REG, T_REG}, 0x04, 10},
    {"sub", 3, {T_REG, T_REG, T_REG}, 0x05, 10},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 0x06, 6},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 0x08, 6},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 0x07, 6},
    {"zjmp", 1, {T_DIR}, 0x09, 20},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 0x0A, 25},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 0x02, 5},
    {"fork", 1, {T_DIR}, 0x0C, 800},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 0x0E, 50},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 0x0D, 10},
    {"lfork", 1, {T_DIR}, 0x0F, 1000},
    {"aff", 1, {T_REG}, 0x10, 2},
    {NULL, 0, {T_NONE}, 0, 0}
};

char *my_getline(FILE *src)
{
    size_t n = 0;
    char *line = NULL;

    while (getline(&line, &n, src) >= 0) {
        if (line != NULL && *line != '#') {
            return line;
        }
    }

    return NULL;
}

const token_t *get_token(const char *str)
{
    for (int i = 0; tokens[i].name != NULL; i++) {
        size_t len = my_strlen(tokens[i].name);

        if (my_strncmp(str, tokens[i].name, len) != 0)
            continue;
        if (str[len] == ' ')
            return &tokens[i];
    }

    return NULL;
}

static void encode_metadata(char *str, FILE *dst, int length)
{
    char *tmp = NULL;

    str = my_strtok(str, " ");
    while (str != NULL) {
        str = my_strtok(NULL, " ");
        if (str != NULL) {
            fwrite(str, sizeof(char), my_strlen(str), dst);
            for (size_t i = 0; i < length - my_strlen(str); i++)
                fwrite((int[]) {0}, sizeof(int), 1, dst);
        }
    }
}

static void parse_metadata(FILE *src, FILE *dst)
{
    char *line = NULL;

    while ((line = my_getline(src)) != NULL) {
        if (my_strncmp(line, NAME_STR, my_strlen(NAME_STR)) == 0)
            encode_metadata(line, dst, NAME_LENGTH);
        else if (my_strncmp(line, COMMENT_STR, my_strlen(COMMENT_STR)) == 0)
            encode_metadata(line, dst, COMMENT_LENGTH);
    }
}

static int encode_token(const char *str, const token_t *token, FILE *fp)
{
    fwrite(&token->code, sizeof token->code, 1, fp);

    return 0;
}

int redcode_encode(FILE *src, FILE *dst)
{
    char *line = NULL;

    fwrite((int[]) {REDCODE_HEADER}, sizeof(int), 1, dst);
    parse_metadata(src, dst);

    while ((line = my_getline(src)) != NULL) {
        const token_t *token = get_token(line);

        if (token == NULL)
            return -1;

        encode_token(line, token, dst);
    }

    return 0;
}
