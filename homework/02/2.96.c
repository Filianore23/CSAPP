#include<stdio.h>
#include<assert.h>
typedef unsigned float_bits;

/*
 * Compute (int) f , if computation causes overflow or NaN , return 0x80000000
 */

 float_bits float_int(float_bits f) {
 unsigned s = f >> 31;
 unsigned exp = f >> 23 & 0xff;
 unsigned frac = f & 0x7fffff;
/* Consider rounding to zero -> numbers less than 1 will be rounded to zero
 * 0 00000000 00000000000000000000000 -> 0 01111111 00000000000000000000000
 * and for f in range 1 <= f < 2^31 , integers round to zero
 * 0 01111111 00000000000000000000000 -> 0 11111110 11111111111111111111111
 * for f >= 2^31 -> return 0x80000000
 */
unsigned bias = 0x7f;
unsigned M;
unsigned E = exp - biasa;
unsigned result;
if(E < 0) {
    result = 0;
} else if(E >= 0 && E < 31) { /* The biggest integer is 2^31 - 1 */
    M = frac | 0x800000; /* Implicit 1 */
    if(E > 23) /* M has enough bits to fill higer order for integer */ {
        num = M << (E - 23);
    } else if(E <= 23) {
        num = M >> (23 - E);
    }
} else {
    result =  0x80000000;
}
return s ? -num : num;
 }
