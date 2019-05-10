/*
** EPITECH PROJECT, 2018
** libredcode
** File description:
** The library main header.
*/

#ifndef REDCODE_H
#define REDCODE_H

#include "types.h"

#define ENCODE_8(val) ((uint8_t []) {my_atoi(val)})
#define ENCODE_16(val) ((uint16_t []) {__bswap_16(my_atoi(val))})
#define ENCODE_32(val) ((uint32_t []) {__bswap_32(my_atoi(val))})

int parse_size(parser_t *parser);
int parser_reset(parser_t *parser);
int parse_labels(parser_t *parser);
int redcode_encode(FILE *src, FILE *dst);
int encode_instruction(parser_t *parser, instruction_t *instruction);

size_t redcode_write(parser_t *parser, const void *ptr, size_t size, size_t n);

ssize_t readfile(FILE *fp, char **ptr);

off_t redcode_header(parser_t *parser);

mnemonic_t get_mnemonic(const char *str);

argument_t get_argument(unsigned int types, const char *str);

directive_t *parse_directive(const char *str);
directive_t *get_directive(parser_t *parser, const char *name);

instruction_t *parse_instruction(parser_t *parser, char *line);

#endif
