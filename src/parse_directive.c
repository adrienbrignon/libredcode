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

static void *free_and_return_null(directive_t *dir)
{
    free((void *) dir->name);
    free((void *) dir->value);
    free((void *) dir->line);
    free(dir);

    return NULL;
}

directive_t *parse_directive(const char *str)
{
    directive_t *dir = NULL;

    if (*str != '.' || (dir = new_directive(str)) == NULL)
        return NULL;
    if ((dir->name = my_strndup(str + 1, my_strcspn(str, " ") - 1)) == NULL)
        return free_and_return_null(dir);
    if (my_strlen((dir->value = ((char *) str + 1) + my_strcspn(str, " "))) < 2)
        return free_and_return_null(dir);
    if (*dir->value != '"' || dir->value[my_strlen(dir->value) - 1] != '"')
        return free_and_return_null(dir);

    dir->value = my_strndup(dir->value + 1, my_strlen(dir->value + 1) - 1);

    if (dir->value == NULL)
        return free_and_return_null(dir);

    return dir;
}
