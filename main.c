#include "include/redcode.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *src = fopen("zork.s", "r");
    FILE *dst = fopen("zork.cor", "w");

    redcode_encode(src, dst);

    return 0;
}
