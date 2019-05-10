/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Get an argument from string.
*/

#include "redcode.h"

argument_t get_argument(unsigned int types, const char *str)
{
    if (*str == REG_CHAR)
        return (argument_t) {T_REG, REG_SIZE, str + 1};
    if (*str == DIR_CHAR)
        return (argument_t) {T_DIR, (types & T_SPE) == T_SPE ? IND_SIZE : DIR_SIZE, str + 1};

    return (argument_t) {T_IND, IND_SIZE, str};
}
