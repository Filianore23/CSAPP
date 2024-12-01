#include<stdio.h>
#include<assert.h>
#include<limits.h>
int threeforths(int x) {
    // when consider rounding , we simply consider the number represented by the low bits , see by division is less than one , in this case division by four gives lower 2 bit
    // no overflow means we calculate 3/x then divide by 4
    // consider f and l , where f is represented by the higher 30 bit and l by lower 2 bit, we have x = f + l
    int f = x & ~0x3;
    int l = x & 0x3;
    int is_neg = x & INT_MIN;
    int fd4 = f >> 2;
    int fd4m3 = (fd4 << 1) + fd4;
    int lm3 = (l << 1) + l;
    (is_neg && (lm3 += 3));
    int lm3d4 = lm3 >> 2;
    return fd4m3 + lm3d4;
}

int main(int argc, char* argv[]) {
  assert(threeforths(8) == 6);
  assert(threeforths(9) == 6);
  assert(threeforths(10) == 7);
  assert(threeforths(11) == 8);
  assert(threeforths(12) == 9);

  assert(threeforths(-8) == -6);
  assert(threeforths(-9) == -6);
  assert(threeforths(-10) == -7);
  assert(threeforths(-11) == -8);
  assert(threeforths(-12) == -9);
  return 0;
}


