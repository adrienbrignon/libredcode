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
    static char binary[(8 * 4 + 1)] = {0};

    my_itoa(type1, binary, 2);
    my_itoa(type2, binary + my_strlen(binary), 2);
    my_itoa(type3, binary + my_strlen(binary), 2);
    my_itoa(0, binary + my_strlen(binary), 2);
    my_itoa(0, binary + my_strlen(binary), 2);

    return binary;
}

static char *get_hexa(char *binary)
{
    unsigned int result = 0;
    static char hexa[2] = {0};
    int len = my_strlen(binary);

    for (int counter = 0; counter < len; counter++)
        result += ((binary[len - counter - 1] - '0') * my_pow(2, counter));

    my_itoa(result, hexa, 16);

    return hexa;
}

static unsigned int get_power(int number)
{
    int counter = 0;

    if (number == 1)
        return 1;

    while (my_pow(2, counter) != number)
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