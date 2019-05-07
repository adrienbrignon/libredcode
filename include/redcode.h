/*
** EPITECH PROJECT, 2018
** libredcode
** File description:
** The library main header.
*/

#ifndef REDCODE_H
#define REDCODE_H

#include <stdio.h>

#define MAX_ARGS_NUMBER (4)

typedef enum type {
    T_NONE = 0,
    T_REGISTER = 1 << 0,
    T_DIRECT = 1 << 1,
    T_INDIRECT = 1 << 2,
    T_LABEL = 1 << 3,
    T_NAME = 1 << 4,
    T_COMMENT = 1 << 5
} type_t;

typedef struct token {
    const char *name;
    size_t args;
    unsigned int type[MAX_ARGS_NUMBER];
    unsigned char code;
    size_t cycles;
} token_t;

int redcode_encode(FILE *src, FILE *dst);

#endif
