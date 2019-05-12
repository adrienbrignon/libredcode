/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Get a directive from line.
*/

#include <stdlib.h>

#include "redcode.h"
#include "my/my_ctype.h"
#include "my/my_string.h"

directive_t *parse_directive(const char *str)
{
    directive_t *dir = NULL;

    if ((dir = malloc(sizeof *dir)) == NULL || *str != '.')
        return NULL;
    if ((dir->name = my_strndup(str + 1, my_strcspn(str, " ") - 1)) == NULL)
        return NULL;


    dir->value = ((char *) str + 1) + my_strcspn(str, " ");

    if (my_strlen(dir->value) <= 2)
        return NULL;
    if (*dir->value != '"' || dir->value[my_strlen(dir->value) - 1] != '"')
        return NULL;

    dir->value = my_strndup(dir->value + 1, my_strlen(dir->value + 1) - 1);

    if (dir->value == NULL)
        return NULL;

    return dir;
}
