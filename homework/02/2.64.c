#include<stdio.h>
#include<assert.h>

int any_odd_one(unsigned x) {
    int mask = 0xAA;
    mask |= mask << 8;
    mask |= mask << 16;
    return !!(x & mask);
}

int main(int argc , const char *argv[]) {
    assert(any_odd_one(0x2));
    assert(!any_odd_one(0x4));
    return 0;
}
