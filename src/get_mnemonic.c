/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Get a mnemonic from a string.
*/

#include "redcode.h"
#include "my/my_ctype.h"
#include "my/my_string.h"
#include <stdbool.h>

static const mnemonic_t mnemonics[] = {
    {"live", 1, {T_DIR}, 0x01, 10, false},
    {"sti", 3, {T_REG, T_REG | T_DIR | T_IND | T_SPE, T_DIR | T_REG | T_SPE}, 0x0b, 25, true},
    {"st", 2, {T_REG, T_IND | T_REG}, 0x03, 5, true},
    {"add", 3, {T_REG, T_REG, T_REG}, 0x04, 10, true},
    {"sub", 3, {T_REG, T_REG, T_REG}, 0x05, 10, true},
    {"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 0x06, 6, true},
    {"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 0x08, 6, true},
    {"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 0x07, 6, true},
    {"zjmp", 1, {T_DIR | T_SPE}, 0x09, 20, false},
    {"ldi", 3, {T_REG | T_DIR | T_IND | T_SPE, T_DIR | T_REG | T_SPE, T_REG}, 0x0a, 25, true},
    {"ld", 2, {T_DIR | T_IND, T_REG}, 0x02, 5, true},
    {"fork", 1, {T_DIR | T_SPE}, 0x0c, 800, false},
    {"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 0x0e, 50, true},
    {"lld", 2, {T_DIR | T_IND, T_REG}, 0x0d, 10, true},
    {"lfork", 1, {T_DIR}, 0x0f, 1000, false},
    {"aff", 1, {T_REG}, 0x10, 2, true},
    {NULL, 0, {0}, 0, 0, false}
};

mnemonic_t get_mnemonic(const char *str)
{
    while (my_isspace(*str))
        str++;
    for (int i = 0; mnemonics[i].name != NULL; i++) {
        size_t len = my_strlen(mnemonics[i].name);

        if (my_strncmp(str, mnemonics[i].name, len) == 0 && (str[len] == ' ' || str[len] == '\0'))
            return mnemonics[i];
    }

    return (mnemonic_t) {NULL, 0, {0}, 0, 0, false};
}
