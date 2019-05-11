/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Get an argument from string.
*/

#include "redcode.h"

static char *extract_label(char *str)
{
    if (*str == '%')
        str++;
    if (*str == ':')
        str++;
    if (*str == '\0')
        return (NULL);
    return (str);
}

argument_t get_argument(unsigned int types, const char *str)
{
    if (*str == LAB_CHAR)
        return (argument_t) {T_LAB | T_IND, IND_SIZE, extract_label((char *) str)};
    if (*str == DIR_CHAR && *(str + 1) == LAB_CHAR)
        return (argument_t) {T_LAB | T_DIR, IND_SIZE, extract_label((char *) str)};
    if (*str == REG_CHAR)
        return (argument_t) {T_REG, REG_SIZE, str + 1};
    if (*str == DIR_CHAR && (types & T_SPE) == T_SPE)
        return (argument_t) {T_DIR, IND_SIZE, str + 1};
    if (*str == DIR_CHAR)
        return (argument_t) {T_DIR, DIR_SIZE, str + 1};

    return (argument_t) {T_IND, IND_SIZE, str};
}
