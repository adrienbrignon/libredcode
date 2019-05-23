/*
** EPITECH PROJECT, 2018
** libredcode
** File description:
** The library main header.
*/

#ifndef REDCODE_H
#define REDCODE_H

#include "types.h"
#include "my/my_stdio.h"

#define SWAP_16(x) (__bswap_16(x))
#define SWAP_32(x) (__bswap_32(x))
#define ENCODE_8(val) ((uint8_t []) {my_atoi(val)})
#define ENCODE_16(val) ((uint16_t []) {SWAP_16(my_atoi(val))})
#define ENCODE_32(val) ((uint32_t []) {SWAP_32(my_atoi(val))})
#define WRITE(parser, ptr, size, n) (fwrite(ptr, size, n, parser->out))

#define ERROR(code, msg) ((my_puts(msg) * 0) + code)

void encode_header(parser_t *parser);

int parse_size(parser_t *parser);
int parser_reset(parser_t *parser);
int parse_labels(parser_t *parser);
int redcode_encode(parser_t *parser);
int redcode_destroy(parser_t *parser);
int redcode_setinput(parser_t *parser, FILE *in);
int redcode_setoutput(parser_t *parser, FILE *out);
int redcode_check(parser_t *parser, const char **msg);
int encode_label(parser_t *parser, instruction_t *ins, size_t i);
int encode_instruction(parser_t *parser, instruction_t *instruction);

int has_invalid_name(parser_t *parser);
int has_missing_name(parser_t *parser);
int has_invalid_labels(parser_t *parser);
int has_missing_comment(parser_t *parser);
int has_invalid_comment(parser_t *parser);
int has_messy_directives(parser_t *parser);
int has_duplicate_labels(parser_t *parser);
int has_invalid_arguments(parser_t *parser);
int has_invalid_directives(parser_t *parser);
int has_duplicate_directives(parser_t *parser);

ssize_t readfile(FILE *fp, char **ptr);

parser_t *redcode_parser(void);
parser_t *redcode_parse(FILE *in);

mnemonic_t get_mnemonic(const char *str);

argument_t get_argument(unsigned int types, char *str);

directive_t *new_directive(const char *str);
directive_t *parse_directive(const char *str);
directive_t *get_directive(parser_t *parser, const char *name);

instruction_t *new_instruction(const char *line);
instruction_t *find_label(parser_t *parser, const char *name);
instruction_t *parse_instruction(parser_t *parser, char *line);

#endif
