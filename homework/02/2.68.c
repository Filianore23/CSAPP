#include<stdio.h>
#include<assert.h>

/*
 * Mask with least significant n bits to 1
 * Example n = 6 -> 0x3f , n = 17 -> 0x 1ffff
 * Assume 1 <= n <= w
 */

int lower_one_mask(int n) {
    int w = sizeof(int) << 3;
    int mask =(unsigned)-1 >> (w - n);
    return mask;
}

int main(int argc, char* argv[]) {
  assert(lower_one_mask(6) == 0x3F);
  assert(lower_one_mask(17) == 0x1FFFF);
  assert(lower_one_mask(32) == 0xFFFFFFFF);
  return 0;
}

