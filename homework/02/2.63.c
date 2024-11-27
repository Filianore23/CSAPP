#include<stdio.h>
#include<assert.h>

unsigned srl(unsigned x, int k) {
    /*Perform shift arithmetically*/
    unsigned xsra = (int) x >> k;
    int w = sizeof(int) << 3;
    unsigned mask = ~(-1 << (w - k - 1) << 1);
    return xsra & mask;
    // 1 << k is actually 1 << (k mod w)
    // 1 << (w - k) malfunctions as k == 0 
    // 1 << (w - k) won't shift ,  as in some machine it's undefined behavior
}

int sra(int x , int k) {
    int xsrl = (unsigned) x >> k;
    int w = sizeof(int) << 3;
    int mask = (-1 << (w - k - 1) << 1);
    int neg_sign = 1 << (w - 1);
    mask &= !(x & neg_sign) - 1;
    // if x & neg_sign != 0
    // x is negative number, so mask should remain intack 
    // else x is positive , and mask should be reduced to zero
    // | as complement
    return xsrl | mask;
}

int main(int argc, const char *argv[]) {
  unsigned test_unsigned = 0x12345678;
  int test_int = 0x12345678;

  assert(srl(test_unsigned, 4) == test_unsigned >> 4);
  assert(sra(test_int, 4) == test_int >> 4);

  test_unsigned = 0x87654321;
  test_int = 0x87654321;

  assert (srl (test_unsigned, 4) == test_unsigned >> 4);
  assert (sra (test_int, 4) == test_int >> 4);

  return 0;

}
