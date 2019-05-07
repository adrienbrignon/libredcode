/*
** EPITECH PROJECT, 2018
** libredcode
** File description:
** Encode a redcode file to an executable.
*/

#include <string.h>

#include "redcode.h"

static const token_t tokens[] = {
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

int redcode_encode(FILE *src, FILE *dst)
{
    size_t n = 0;
    char *line = NULL;

    while (getline(&line, &n, src) >= 0)
        printf("%s\n", line);

    return 0;
}
