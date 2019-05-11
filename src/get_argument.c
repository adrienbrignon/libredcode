/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Get an argument from string.
*/

#include "redcode.h"
#include "my/my_ctype.h"
#include "my/my_stdlib.h"

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

static char *extract_argument(char *str)
{
    if (str[0] == DIR_CHAR && (my_isdigit(str[1]) || str[1] == LAB_CHAR))
        return (str + 1);
    if (str[0] == REG_CHAR) {
        if (my_atoi(&str[1]) > 0 && my_atoi(&str[1]) < 17)
            return (str + 1);
        else
            return (NULL);
    }
    if (str[0] != DIR_CHAR && str[1] == LAB_CHAR)
        return (str + 1);
    if (str[0] != DIR_CHAR && my_isdigit(str[1]))
        return (str);
    return (NULL);
}

argument_t get_argument(unsigned int types, const char *str)
{
    while (my_isspace(*str))
        str++;
    if (*str == LAB_CHAR)
        return (argument_t) {T_LAB | T_IND, IND_SIZE, extract_label((char *) str)};
    if (*str == DIR_CHAR && *(str + 1) == LAB_CHAR)
        return (argument_t) {T_LAB | T_DIR, IND_SIZE, extract_label((char *) str)};
    if (*str == REG_CHAR)
        return (argument_t) {T_REG, REG_SIZE, extract_argument((char *) str)};
    if (*str == DIR_CHAR && (types & T_SPE) == T_SPE)
        return (argument_t) {T_DIR, IND_SIZE, extract_argument((char *) str)};
    if (*str == DIR_CHAR)
        return (argument_t) {T_DIR, DIR_SIZE, extract_argument((char *) str)};

    return (argument_t) {T_IND, IND_SIZE, extract_argument((char *) str)};
}
