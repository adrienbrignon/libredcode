#include "include/redcode.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FILE *src = fopen("zork.s", "rb");
    FILE *dst = fopen("zork.cor", "wb");

    redcode_encode(src, dst);

    return 0;
}
