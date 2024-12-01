#include<stdio.h>
#include<assert.h>

// A 
int A(int k) {
    return -1 << k;
}

// B
int B(int k,int j) {
    return ~A(k) << j;
}

int main(int argc, char* argv[]) {
  assert(A(8) == 0xFFFFFF00);
  assert(B(16, 8) == 0x00FFFF00);
  return 0;
}

