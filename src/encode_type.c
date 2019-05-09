/*
** EPITECH PROJECT, 2019
** libredcode
** File description:
** encode_type
*/

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include "redcode.h"
#include "my.h"

static char *get_binary(int type1, int type2, int type3)
{
    char *binary = NULL;

    if ((binary = malloc(sizeof(char) * (8 * 4) + 1)) == NULL)
        return NULL;

    my_itoa(type1, binary, 2);
    my_itoa(type2, binary + my_strlen(binary), 2);
    my_itoa(type3, binary + my_strlen(binary), 2);
    my_itoa(0, binary + my_strlen(binary), 2);
    my_itoa(0, binary + my_strlen(binary), 2);

    return binary;
}

static char *get_hexa(char *binary)
{
    char *hex = NULL;
    unsigned int result = 0;
    int len = my_strlen(binary);

    if ((hex = malloc(sizeof(char) * 3)) == NULL)
        return NULL;

    for (int counter = 0; counter < len; counter++)
        result += ((binary[len - counter - 1] - '0') * pow(2, counter));

    free(binary);
    my_itoa(result, hex, 16);

    return hex;
}

static unsigned int get_power(int number)
{
    int counter = 0;

    if (number == 1)
        return 1;

    while (pow(2, counter) != number)
        counter++;

    return counter + 1;
}

char *encode_type(int type1, int type2, int type3)
{
    char *hexa = NULL;

    type1 = get_power(type1);
    type2 = get_power(type2);
    type3 = get_power(type3);

    if ((hexa = get_hexa(get_binary(type1, type2, type3))) == NULL)
        return NULL;

    return hexa;
}