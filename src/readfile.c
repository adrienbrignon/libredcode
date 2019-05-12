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

    while (my_isspace(*str))
        str++;
    for (size_t i = 0; str[i] != '\0'; i++) {
        if (!my_isspace(str[i]))
            str[idx++] = str[i];
        else if (str[i + 1] != '\0' && !my_isspace(str[i + 1]))
            str[idx++] = ' ';
    }

    str[idx] = '\0';

    return str;
}

ssize_t readfile(FILE *fp, char **ptr)
{
    size_t n = 0;
    size_t len = 0;
    char *comment = NULL;

    if ((getline(ptr, &n, fp)) == EOF)
        return -1;
    if (**ptr == '\n' || **ptr == '\0' || **ptr == '#')
        return readfile(fp, ptr);
    if ((comment = my_strchr(*ptr, '#')) != NULL)
        *comment = '\0';

    *ptr = clean_line(*ptr);
    len = my_strlen(*ptr);

    if (len == 0 || **ptr == '\0')
        return readfile(fp, ptr);
    if ((*ptr)[len - 1] == '\n')
        (*ptr)[len - 1] = '\0';

    return len;
}
