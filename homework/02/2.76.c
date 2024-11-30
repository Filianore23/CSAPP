/*
 * calloc.c
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
/*
 * void *malloc(size_t size) 该函数返回一个指针 ，指向已分配大小的内存。如果请求失败返回NULL
 * void *memset(void *s, int c, size_t n) 将指针变量 s 所指向的前 n 字节的内存单元用一个“整数” c 替换，注意 c 是 int 型。s 是 void* 型的指针变量，所以它可以为任何类型的数据进行初始化
 */

void* another_calloc(size_t nmemb, size_t size) {
if(nmemb == 0 || size == 0) {
    return NULL;
}
// nmemb == buf_size / size is a great way to detect overflow , as unlike addition , integer multiplication doesn't have multiplicative inverse.
    size_t buf_size = nmemb * size;
    if(nmemb == buf_size / size) {
        void* ptr = malloc(buf_size);
        memset(ptr,0,buf_size);
        return ptr;
    }
    return NULL;
}

int main(int argc, char* argv[]) {
  void* p;
  p = another_calloc(0x1234, 1);
  assert(p != NULL);
  free(p);

  p = another_calloc(SIZE_MAX, 2);
  assert(p == NULL);
  free(p);
  return 0;
}

