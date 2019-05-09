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

static char *recup_binary(int type)
{
    if (my_pow(2, type) == T_REG)
        return "01";
    if (my_pow(2, type) == T_DIR)
        return "10";
    if (my_pow(2, type) == T_IND)
        return "11";

    return "00";
}

static char *get_binary(int t1, int t2, int t3)
{
    static char binary[(8 * 4 + 1)] = {0};

    my_strcat(binary, recup_binary(t1));
    my_strcat(binary, recup_binary(t2));
    my_strcat(binary, recup_binary(t3));
    my_strcat(binary, recup_binary(-1));

    return binary;
}

static char *get_hexa(const char *binary)
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
        return 0;

    while (my_pow(2, counter) != number)
        counter++;

    return counter;
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