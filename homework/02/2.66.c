#include<stdio.h>
#include<assert.h>
/*
 * Generate mask indicating the leftmost 1 , assuming w = 32
 * For example , 0xFF00 -> 0x800, 0x6600 -> 0x4000
 */

int leftmost_one(unsigned x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    return ~(x >> 1) & x;
    // (~x >> 1) fail because of the sign bit
}

int main(int argc, char* argv[]) {
  assert(leftmost_one(0xFF00) == 0x8000);
  assert(leftmost_one(0x6000) == 0x4000);
  assert(leftmost_one(0x0) == 0x0);
  assert(leftmost_one(0x80000000) == 0x80000000);
  return 0;
}
