#include<stdio.h>
#include<assert.h>
#include<limits.h>
typedef unsigned float_bits;

float_bits i2f(int i) { 
    //assume that float and int datatype both take 32 bit
    //With the implict 1 , IEEE standard has at most 24 bits to represent number , so integer with more than 24 bits must be rounded.
    //rounding : if larger than half -> rounded up
    //if smaller than half -> rounded down
    //if half -> rounded to even
    //we need to cast negative number to positive , while saving the sign bit
    unsigned exp , frac , sign , bias;
    unsigned t , rp , lp;
    bias = 127;
    if(i == 0) return i;
    sign = (i & INT_MIN) == INT_MIN;
    if(sign) i = ~i + 1;
    for(rp = 1 , t = INT_MIN; t == (t % i); t >>= 1) 
        rp += 1;
    lp = (sizeof(int) << 3) - rp;
    exp = lp + bias;
    if(lp > 23) {
       unsigned shift = lp - 23;
       unsigned mask = ((1 << shift) - 1) & i;
       unsigned half = (1 << shift - 1);
       unsigned hide = 1 << shift;
       unsigned round = ((mask == half) && (i & hide) == hide) || mask > half;
       frac = i >> shift & 0x7fffff;
       if(round == 1 && frac == 0x7fffff) {
           frac = 0;
           exp += 1;
       } else {
           frac += 1;
       }
    } else {
        frac = i << (23 - lp) & i;
    }
    return sign << 31 | exp << 23 | frac;
}
