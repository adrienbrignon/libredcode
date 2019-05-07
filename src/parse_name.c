/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** parse_name
*/

#include "redcode.h"
#include "my_string.h"

int parse_name(FILE *src, FILE *dst)
{
    char *line = my_getline(src);

    if (my_strncmp(line, NAME_STR, my_strlen(NAME_STR)) == 0)
        return (encode_metadata(line, dst, NAME_LENGTH));
    return (-1);
}