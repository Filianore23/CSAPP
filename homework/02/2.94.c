#include<stdio.h>
#include<assert.h>
typedef unsigned float_bits;

// Compute 2*f , if f is NaN , return f

float_bits float_twice(float_bits f) {
    int s = f >> 31;
    int exp = f >> 23 & 0xff;
    int frac = f & 0x7fffff;
    if(exp == 0xff && frac != 0) return f;
// There are three situations : denormalized , normalized , and exp = 0xff - 1
    if(exp == 0) /* denormalieze */{
        frac <<= 1;
    } else if(exp == 0xff -1) /* special value */ {
        exp = 0xff;
        frac = 0; /* infinite */
    } else /* normalized value */ {
        exp += 1;
    }
    return s << 31 | exp << 23 | frac;
}
