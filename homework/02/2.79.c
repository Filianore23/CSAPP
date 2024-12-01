#include <stdio.h>
#include <assert.h>
#include <limits.h>

int mul3div4(int x) {
    int mul = (x << 1) + x;
    int sig = mul & INT_MIN;
    (sig && (mul = mul + 3));
    return mul >> 2;
}

int main(int argc, char* argv[]) {
  int x = 0x87654321;
  assert(mul3div4(x) == x * 3 / 4);
  return 0;
}


