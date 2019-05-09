/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** blabla
*/

#include "redcode.h"

size_t redcode_write(parser_t *p, const void *ptr, size_t size, size_t nmemb)
{
    p->offset += nmemb * size;

    return fwrite(ptr, size, nmemb, p->dest);
}
