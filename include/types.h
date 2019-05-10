/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** The library types definition.
*/

#ifndef RECODE_TYPES_H
#define RECODE_TYPES_H

#include <stdio.h>
#include <stddef.h>

#include "config.h"

typedef struct parser {
    off_t offset;

    FILE *in;
    FILE *out;
} parser_t;

typedef enum type {
    T_UNK = 0,
    T_REG = 1 << 0,
    T_DIR = 1 << 1,
    T_IND = 1 << 2,
    T_LAB = 1 << 3
} type_t;

typedef struct argument {
    type_t type;
    size_t size;
    const char *value;
} argument_t;

typedef struct mnemonic {
    const char *name;
    size_t argc;
    int argv[MAX_ARGS];
    char code;
    size_t cycles;
} mnemonic_t;

typedef struct instruction {
    size_t size;
    mnemonic_t mnemonic;
    argument_t argv[MAX_ARGS];
} instruction_t;

#endif
