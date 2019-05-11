/*
** EPITECH PROJECT, 2018
** readcode
** File description:
** Read a file line by line.
*/

#include "redcode.h"
#include "my/my_ctype.h"
#include "my/my_string.h"

static char *clean_line(char *str)
{
    size_t idx = 0;

    for (size_t i = 0; str[i]; i++) {
        if (!my_isspace(str[i]))
            str[idx++] = str[i];
        else if (idx && str[i + 1] && !my_isspace(str[i + 1]))
            str[idx++] = ' ';
    }

    str[idx] = '\0';

    return str;
}

ssize_t readfile(FILE *fp, char **ptr)
{
    size_t n = 0;
    ssize_t len = 0;
    char *comment = NULL;

    if ((len = getline(ptr, &n, fp)) == EOF)
        return len;
    if (**ptr == '\n' || **ptr == '\0' || **ptr == '#')
        return readfile(fp, ptr);
    if ((comment = my_strchr(*ptr, '#')) != NULL)
        *comment = '\0';

    (*ptr)[len - 1] = '\0';
    *ptr = clean_line(*ptr);

    return len;
}


