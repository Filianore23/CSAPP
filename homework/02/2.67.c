#include<stdio.h>
#include<assert.h>
//A: if the value of the right operand is netative or greater than the width of the prompt left operand , the behavior is undefined.
//B : check the code
//1 << 31 << 1 is undefined as 1 << 31 generates an negative number
int int_size_is_32() {
   int set_msb = 1 << 31;
   int beyond_msb = set_msb << 1;
   return !beyond_msb && set_msb;
}

// C : check the code
int int_size_is_32_for_16bits() {
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;
    return !beyond_msb && set_msb;
}

int main(int argc, char *argv[]) {
  assert(int_size_is_32());
  assert(int_size_is_32_for_16bits());
  return 0;
}
