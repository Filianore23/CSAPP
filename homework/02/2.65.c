#include<stdio.h>
#include<assert.h>
// return 1 if x contains an odd number  1 and 0 otherwise
int odd_ones(unsigned x) {
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    x &= 1;
    return x;
    // reduce all 1s in x , if by xor the first half to the last half
    // 1 ^ 1 will be reduced , and 1 ^ 0 will be culculated in next round
    // keep xoring if odd number of 1 , there will one 1 left and 0 otherwise.
}

int main(int argc, char* argv[]) {
  assert(odd_ones(0x10101011));
  assert(!odd_ones(0x01010101));
  return 0;
}
