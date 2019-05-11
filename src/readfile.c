/*
** EPITECH PROJECT, 2018
** readcode
** File description:
** Read a file line by line.
*/

#include "redcode.h"
#include "my/my_string.h"

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

    printf("%s\n", *ptr);

    return len;
}


