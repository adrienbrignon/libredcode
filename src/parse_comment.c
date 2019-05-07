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
    char *line = my_getline(src);

    if (my_strncmp(line, COMMENT_STR, my_strlen(COMMENT_STR)) == 0)
        return (encode_metadata(line, dst, COMMENT_LENGTH));
    return (-1);
}