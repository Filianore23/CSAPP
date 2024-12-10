#include<stdio.h>
#include<assert.h>
typedef unsigned float_bits;

float_bits float_bits(float_bits f) {
    int s = f >> 31;
    int exp = f >> 23 & 0xff
    int frac = f & 0x7fffff;
    // rounding to even means we need to consider the last two bits
    if(exp == 0xff && frac != 0) return f;
    // 00 -> 0 just >> 1
    // 10 -> 1 just >> 1
    // 01 -> 0 just >> 1
    // 11 -> 10 >> 1 and add 1
    int add = (frac & 0x3) == 0x3;
    if(exp = 0) {
        frac >>= 1;
        frac += add;
    } else if(exp == 1) {
        //by calculation , exp always turn to 0 , and E does not change. so f1/2 == f2 -> frac1 >>1
        exp = 0; 
        frac >>= 1;
        frac += add;
    } else {
        exp -= 1;
    }
    return s << 31 | exp << 23 | frac;
}
