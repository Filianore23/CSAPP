#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stddef.h> // 提供 size_t 类型定义

typedef unsigned char* byte_pointer; // 定义 byte_pointer 类型

// 函数声明
void show_bytes(byte_pointer start, size_t len);
void show_int(int x);
void show_float(float x);
void show_pointer(void* x);
void test_show_bytes(int val);

int is_little_endian();
int generate_word(int x, int y);

#endif // FUNCTIONS_H

