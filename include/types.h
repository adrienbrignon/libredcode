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
#include <unistd.h>
#include <stdint.h>
#include <stdbool.h>
#include <byteswap.h>
#include <sys/types.h>

#include "list.h"
#include "config.h"

typedef struct parser {
    FILE *in;
    FILE *out;
    list_t *instructions;
    list_t *directives;
    size_t size;
} parser_t;

typedef struct directive {
    const char *name;
    const char *value;
} directive_t;

typedef enum type {
    T_UNK = 0,
    T_REG = 1 << 0,
    T_DIR = 1 << 1,
    T_IND = 1 << 2,
    T_LAB = 1 << 3,
    T_SPE = 1 << 4
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
    bool coding_byte;
} mnemonic_t;

typedef struct instruction {
    size_t size;
    off_t offset;
    const char *label;
    mnemonic_t mnemonic;
    argument_t argv[MAX_ARGS];
} instruction_t;

#endif
