#include<stdio.h>
#include"homework.h"
#include<assert.h>
typedef unsigned char* byte_pointer;
int is_little_endian() {
     int mask = 0xff;
     byte_pointer byte_start =(byte_pointer)& mask;
     return !!*(byte_start);
 }

/*
 * generate-a-word
 */

int generate_word(int x,int y) {
    int mask = 0xff;
    return (x & mask) | (y & ~mask);
}

/*
 * C-Bit-Expressions
 */

int expressions_A(int x) {
    return !~x;
}
 

int expression_B(int x) {
   return !x; 
}
int expression_C(int x) {
   return !~(x | ~0xff);             
}

int expression_D(int x) {
    return !((x >> ((sizeof(int)-1) << 3)) & 0xff);
}

