#include<stdio.h>
#include<assert.h>
/*
 * Do rotating left shift , Assume 0 <= n < w
 * Example when x = 0x12345678 and w = 32
 * n=4 -> 0x23456781 , n = 20 -> 0x67812345
 */
unsigned rotate_left(unsigned x, int n) {
    int w = sizeof(int) << 3;
    return x >> (w - n - 1) >> 1 | (x << n); 
}

int main(int argc, char* argv[]) {
  assert(rotate_left(0x12345678, 4) == 0x23456781);
  assert(rotate_left(0x12345678, 20) == 0x67812345);
  return 0;
}
