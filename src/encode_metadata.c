/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** encode_metadata
*/

#include "redcode.h"
#include "my_string.h"

int encode_metadata(char *str, FILE *dst, int length)
{
    char *tmp = NULL;

    str = my_strtok(str, " ");
    while (str != NULL) {
        str = my_strtok(NULL, " ");
        if (str != NULL) {
            fwrite(str, sizeof(char), my_strlen(str), dst);
            for (size_t i = 0; i < length - my_strlen(str); i++)
                fwrite((int[]) {0}, sizeof(int), 1, dst);
        }
    }
    return (0);
}
