/*
** EPITECH PROJECT, 2018
** libredcode
** File description:
** The library main header.
*/

#ifndef REDCODE_H
#define REDCODE_H

#include "types.h"

int redcode_header(parser_t *parser);
int redcode_encode(FILE *src, FILE *dst);
int encode_instruction(parser_t *parser, instruction_t *instruction);

size_t redcode_write(parser_t *parser, const void *ptr, size_t size, size_t n);

ssize_t readfile(FILE *fp, char **ptr);

mnemonic_t get_mnemonic(const char *str);

argument_t get_argument(const char *str);

instruction_t parse_instruction(parser_t *parser, char *line);

#endif
