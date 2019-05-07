/*
** EPITECH PROJECT, 2018
** libredcode
** File description:
** Encode a redcode file to an executable.
*/

#include <string.h>

#include "redcode.h"

static const token_t tokens[] = {
    {"live", 1, {T_DIRECT}, 0x01, 10},
    {"ld", 2, {T_DIRECT | T_INDIRECT, T_REGISTER}, 0x01, 10},
    {".name", 0, {T_NAME}, 0x00, 0},
    {".comment", 0, {T_COMMENT}, 0x00, 0},
    {NULL, 0, {T_NONE}, 0x00, 0}
};

int redcode_encode(FILE *src, FILE *dst)
{
    size_t n = 0;
    char *line = NULL;

    while (getline(&line, &n, src) >= 0)
        printf("%s\n", line);

    return 0;
}
