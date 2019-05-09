/*
** EPITECH PROJECT, 2018
** readcode
** File description:
** Read a file line by line.
*/

#include "redcode.h"

__ssize_t readfile(FILE *fp, char **ptr)
{
    size_t n = 0;
    __ssize_t len = 0;

    if ((len = getline(ptr, &n, fp)) == EOF)
        return len;
    if (**ptr == '\n' || **ptr == '\0' || **ptr == '#')
        return readfile(fp, ptr);

    (*ptr)[len - 1] = '\0';

    return len;
}


