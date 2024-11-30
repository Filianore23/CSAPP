#include<stdio.h>
#include<assert.h>
typedef unsigned packed_t;
// A : can't extract negative number from word
// B : check the code
int xbyte(packed_t word, int bytenum) {
    return (int) word << ((3 - bytenum) << 3) >> (3 << 3); 
}

int main(int argc, char* argv[]) {
  assert(xbyte(0x00112233, 0) == 0x33);
  assert(xbyte(0x00112233, 1) == 0x22);
  assert(xbyte(0x00112233, 2) == 0x11);
  assert(xbyte(0x00112233, 3) == 0x00);

  assert(xbyte(0xAABBCCDD, 0) == 0xFFFFFFDD);
  assert(xbyte(0xAABBCCDD, 1) == 0xFFFFFFCC);
  assert(xbyte(0xAABBCCDD, 2) == 0xFFFFFFBB);
  assert(xbyte(0xAABBCCDD, 3) == 0xFFFFFFAA);

  return 0;
}
