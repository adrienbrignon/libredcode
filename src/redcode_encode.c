/*
** EPITECH PROJECT, 2018
** libredcode
** File description:
** Encode a redcode file to an executable.
*/

#include <string.h>

#include "redcode.h"
#include "my_string.h"

static const token_t tokens[] = {
    {".name", 0, {T_NAME}, 0, 0},
    {".comment", 0, {T_COMMENT}, 0, 0},
    {"live", 1, {T_DIR}, 0x01, 10},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 0x02, 5},
    {"st", 2, {T_REG, T_IND | T_REG}, 0x03, 5},
    {"add", 3, {T_REG, T_REG, T_REG}, 0x04, 10},
    {"sub", 3, {T_REG, T_REG, T_REG}, 0x05, 10},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 0x06, 6},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 0x07, 6},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 0x08, 6},
    {"zjmp", 1, {T_DIR}, 0x09, 20},
    {"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 0x0A, 25},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 0x0B, 25},
    {"fork", 1, {T_DIR}, 0x0C, 800},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 0x0D, 10},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 0x0E, 50},
    {"lfork", 1, {T_DIR}, 0x0F, 1000},
    {"aff", 1, {T_REG}, 0x10, 2},
    {NULL, 0, {T_NONE}, 0, 0}
};

char *my_getline(FILE *src)
{
    size_t n = 0;
    char *line = NULL;

    while (getline(&line, &n, src) >= 0) {
        if (line != NULL && line[0] != '#')
            return (line);
    }
    return (NULL);
}

token_t *get_token(const char *str)
{
    for (int i = 0; tokens[i].name != NULL; i++) {
        if (my_strncmp(str, tokens[i].name, my_strlen(tokens[i].name)) == 0)
            return (&tokens[i]);
    }
    return (NULL);
}

void encode_token(token_t *token, const char *str, FILE *dst)
{
    if (my_strcmp(token->name, ".name") == 0) {
        str = my_strtok(str, " ");
        while (str != NULL) {
            str = my_strtok(NULL, " ");
            if (str != NULL)
                fwrite(str, sizeof(char), my_strlen(str), dst);
            printf("=>%s\n", str);
        }
        //fwrite(dst, my_strlen(str));
    }
}

int redcode_encode(FILE *src, FILE *dst)
{
    char *line = NULL;

    fwrite((int[]) {REDCODE_HEADER}, sizeof(int), 1, dst);
    while ((line = my_getline(src)) != NULL) {
        //char *str = my_strtok(line, " ");
        //while (str != NULL) {
        token_t *token = get_token(line);
        printf("%s\n", line);
        if (token != NULL)
            encode_token(token, line, dst);
        //}
    }
    return (0);
}