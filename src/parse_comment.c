/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** parse_comment
*/

#include "redcode.h"
#include "my_string.h"

int parse_comment(FILE *src, FILE *dst)
{
    char *line = NULL;
    if (readfile(src, &line) < 0)
        return -1;
    if (my_strncmp(line, COMMENT_STR, my_strlen(COMMENT_STR)) == 0)
        return encode_comment(line, dst);

    return -1;
}
