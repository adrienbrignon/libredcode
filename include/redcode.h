/*
** EPITECH PROJECT, 2018
** libredcode
** File description:
** The library main header.
*/

#ifndef REDCODE_H
#define REDCODE_H

#include <stdio.h>
#include <stddef.h>

#include "config.h"

typedef enum type {
    T_NONE = 0,
    T_REG = 1 << 0,
    T_DIR = 1 << 1,
    T_IND = 1 << 2,
    T_LAB = 1 << 3,
    T_NAME = 1 << 4,
    T_COMMENT = 1 << 5
} type_t;

typedef struct parser {
    off_t offset;
    size_t size;
    FILE *src;
    FILE *dest;
} parser_t;

typedef struct argument {
    type_t type;
    size_t size;
    const void *value;
} argument_t;

typedef struct token {
    const char *name;
    size_t args;
    unsigned int type[MAX_ARGS];
    unsigned char code;
    size_t cycles;
} token_t;

int redcode_encode(FILE *src, FILE *dst);

int parse_name(parser_t *parser);
int encode_name(parser_t *parser, char *str, FILE *dst);
int parse_comment(parser_t *parser);
int encode_comment(parser_t *parser, char *str, FILE *dst);
int parse_size(parser_t *parser);

ssize_t readfile(FILE *fp, char **ptr);

size_t redcode_write(parser_t *p, const void *ptr, size_t size, size_t nmemb);

const token_t *get_token(const char *str);

#endif
