#include<stdio.h>
#include<assert.h>
typedef unsigned float_bits;

float_bits float_negate(float_bits f) {
    int sig = f >> 31;
    int exp = f >> 23 & 0xff;
    int frac = f & 0x7fffff;
    if(exp == 0xff && frac != 0) {
        return f;
    }
    return ~sig << 31 | exp << 23 | frac;
}
