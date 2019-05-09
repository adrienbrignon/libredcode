/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** encode_metadata
*/

#include <limits.h>

#include "config.h"
#include "redcode.h"
#include "my_string.h"

static void pad(FILE *dst, size_t length)
{
    for (size_t i = 1; i < length; i++)
        fwrite((char []) {0}, sizeof (char), 1, dst);
}

int encode_metadata(char *str, FILE *dst, size_t length)
{
    size_t len = 0;
    char *value = NULL;
    char *tok = my_strtok(str, " ");

    if (tok == NULL || *(tok + my_strlen(tok) + 1) == '\0')
        return -1;

    value = tok + my_strlen(tok) + 1;
    len = my_strlen(value);

    if (len == 0 || value[0] != '"' || value[len - 1] != '"')
        return -1;

    printf("%ld\n", len - 2);

    fwrite((int []) {(int) len - 1}, sizeof(int), 1, dst);
    fwrite(value + 1, 1, len - 2, dst);

    pad(dst, length - ((len - 2) * CHAR_BIT));

    return 0;
}
