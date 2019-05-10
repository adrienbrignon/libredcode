/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Get a mnemonic from a string.
*/

#include "redcode.h"
#include "my/my_ctype.h"
#include "my/my_string.h"

static const mnemonic_t mnemonics[] = {
    {"live", 1, {T_DIR}, 0x01, 10},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND | T_SPE, T_DIR | T_REG | T_SPE}, 0x0b, 25},
    {"st", 2, {T_REG, T_IND | T_REG}, 0x03, 5},
    {"add", 3, {T_REG, T_REG, T_REG}, 0x04, 10},
    {"sub", 3, {T_REG, T_REG, T_REG}, 0x05, 10},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 0x06, 6},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 0x08, 6},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 0x07, 6},
    {"zjmp", 1, {T_DIR | T_SPE}, 0x09, 20},
    {"ldi", 3, {T_REG | T_DIR | T_IND | T_SPE, T_DIR | T_REG | T_SPE, T_REG}, 0x0a, 25},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 0x02, 5},
    {"fork", 1, {T_DIR | T_SPE}, 0x0c, 800},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 0x0e, 50},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 0x0d, 10},
    {"lfork", 1, {T_DIR}, 0x0f, 1000},
    {"aff", 1, {T_REG}, 0x10, 2},
    {NULL, 0, {0}, 0, 0}
};

mnemonic_t get_mnemonic(const char *str)
{
    while (my_isspace(*str))
        str++;
    for (int i = 0; mnemonics[i].name != NULL; i++) {
        size_t len = my_strlen(mnemonics[i].name);

        if (my_strncmp(str, mnemonics[i].name, len) == 0 && str[len] == ' ')
            return mnemonics[i];
    }

    return (mnemonic_t) {NULL, 0, {0}, 0, 0};
}
