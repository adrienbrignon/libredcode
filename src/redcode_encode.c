/*
** EPITECH PROJECT, 2018
** libredcode
** File description:
** Encode a redcode file to an executable.
*/

#include <stdint.h>
#include <string.h>
#include "redcode.h"
#include "my_string.h"
#include <stddef.h>
#include "my_stdlib.h"

char *my_getline(FILE *src)
{
    size_t n = 0;
    char *line = NULL;

    while (getline(&line, &n, src) >= 0) {
        if (line != NULL && *line != '\0' && *line != '#')
            return line;
    }
    return NULL;
}

argument_t get_argument(char *line)
{
    if (*line == '%' || *line == 'r')
        return (argument_t) {
            *line == '%' ? T_DIR : T_REG,
            *line == '%' ? DIR_SIZE : *line == 'r' ? REG_SIZE : IND_SIZE,
            line + 1,
         };

    return (argument_t) {T_IND, IND_SIZE, line};
}

void invert_byte(unsigned int *val)
{
	int i = 3;
	unsigned int revnbr = 0;
	unsigned int nbr = *val;

	while (i >= 0) {
		((char*)(&revnbr))[i] = ((char*)(&nbr))[0];
		nbr = nbr >> 8;
		i--;
	}
	*val = revnbr;
}

void magic_reverse(void *x)
{
	*((char *)x) ^= *(((char *)x) + 3);
	*(((char *)x) + 3) ^= *((char *)x);
	*((char *)x) ^= *(((char *)x) + 3);
	*(((char *)x) + 1) ^= *(((char *)x) + 2);
	*(((char *)x) + 2) ^= *(((char *)x) + 1);
	*(((char *)x) + 1) ^= *(((char *)x) + 2);
}

void the_magic_reverse(void *x, int size)
{
	for (int i = 0 ; i <= (size - 1) / 2 ; i++) {
		*(((char *)x) + i) ^= *(((char *)x) + (size - 1 - i));
		*(((char *)x) + (size - 1 - i)) ^= *(((char *)x) + i);
		*(((char *)x) + i) ^= *(((char *)x) + (size - 1 - i));
	}
}


static int encode_token(char *str, const token_t *token, FILE *fp)
{
    char *tok = NULL;
    char *start = str + my_strlen(token->name) + 1;

    fwrite(&token->code, sizeof token->code, 1, fp);

    tok = my_strtok(start, ", ");

    for (size_t i = 0; tok != NULL; i++) {
        argument_t argument = get_argument(tok);

        if ((token->type[i] & argument.type) == 0)
            return -1;
        // int n = ((uint16_t) n >> 8) | ((uint16_t) n << 8);
        unsigned int tmp = my_atoi(argument.value);
        the_magic_reverse(&tmp, argument.size);
        printf("->%d\n", tmp);
        printf("=>%ld\n", argument.size);
        fwrite(&tmp, sizeof (char), argument.size, fp);
        printf("%ld: %s\n", argument.size, argument.value);
        tok = my_strtok(NULL, ", ");
    }

    return 0;
}

int redcode_encode(FILE *src, FILE *dst)
{
    char *line = NULL;

    fwrite((int[]) {REDCODE_HEADER}, sizeof(int), 1, dst);
    if (parse_name(src, dst) != 0)
        return -1;
    if (parse_comment(src, dst) != 0)
        return -1;
    while (readfile(src, &line) >= 0) {
        const token_t *token = get_token(line);
        if (token == NULL)
            return -1;
        encode_token(line, token, dst);
    }
    return 0;
}
