/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Get a token by its name.
*/

#include "redcode.h"
#include "my_string.h"

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
