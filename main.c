/*
** EPITECH PROJECT, 2018
** redcode
** File description:
** Sample entry point.
*/

#include <stdio.h>

#include "include/redcode.h"

int main(int argc, char const *argv[])
{
    FILE *src = fopen("zork.s", "r");
    FILE *dst = fopen("zork.cor", "w");

    if (redcode_encode(src, dst) < 0)
        printf("Got an error whilst encoding file...");

    return 0;
}
