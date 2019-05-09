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
    char *line = NULL;

    if (readfile(src, &line) < 0)
        return -1;
    if (my_strncmp(line, NAME_STR, my_strlen(NAME_STR)) != 0)
        return -1;

    encode_metadata(line, dst, NAME_LENGTH);

    return 0;
}
