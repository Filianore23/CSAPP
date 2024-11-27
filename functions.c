/*

 * show-bytes.c
 */

#include <stdio.h>
#include"homework.h"
typedef unsigned char* byte_pointer;

void show_bytes(byte_pointer start, size_t len) {
  size_t i;
  for (i = 0; i < len; i++) {
    printf(" %.2x",start[i]);
  }
  printf("\n");
}

void show_int(int x) {
  show_bytes((byte_pointer) &x, sizeof(int));
}

void show_float(float x){
show_bytes((byte_pointer) &x,sizeof(float));
}

void show_pointer(void* x) {
  show_bytes((byte_pointer) &x, sizeof(void*));
}

void test_show_bytes(int val) {
  int ival = val;
  float fval = (float) ival;
  int* pval = &ival;

  show_int(ival);
  show_float(fval);
  show_pointer(pval);
}

/*
 * is-little-endian
 */

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



