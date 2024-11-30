#include<stdio.h>
#include<assert.h>
#include<limits.h>

// Divided by power of 2 , assume 0 <= k < w - 1

int divide_power2(int x, int k) {
    int sig = x & INT_MIN;
    // for two's complement division , bias equals (1 << k) - 1
    return (sig ? (x + (1 << k) - 1) : x) >> k;
}

int main(int argc, char* argv[]) {
  int x = 0x80000007;
  assert(divide_power2(x, 1) == x / 2);
  assert(divide_power2(x, 2) == x / 4);
  return 0;
}
