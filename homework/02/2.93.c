#include<stido.h>
#include<assert.h>
typedef unsigned float_bits;

/* Compute |f| , if f is NaN , returb f */
float_bits float_abval(float_bits f) {
     int sig = f >> 31;
     int exp = f >> 23 & 0xff;
     int frac = f & 0x7fffff;
     int is_NaN = (exp == 0xff) && (frac != 0);
     if(is_NaN) return f;
     (!sig && (sig = ~sig));
     return sig << 31 | exp << 23 | frac;

}
