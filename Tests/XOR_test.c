// RUN: export PATH="/path/to/llvm/OBJ_ROOT/bin/:$PATH"
// RUN: clang XOR_test.c -S -emit-llvm -o XOR.ll
// RUN: opt -load lib/LLVMXOR.so -xor Tests/XOR_test.ll -S -o new_XOR.ll
// RUN: clang new_XOR.ll -o XOR
//
#include <stdio.h>

int main()
{
    int var = 0;
    int foo = 0;
    int ifoo = 0;
    int bar = 0;
    int quack = 0;
    quack = 0;
    printf("quack equals %d\n", quack);
    return 0;
}
