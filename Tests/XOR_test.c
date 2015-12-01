// RUN: export PATH="/path/to/llvm/OBJ_ROOT/bin/:$PATH"
// RUN: clang XOR_test.c -S -emit-llvm -o XOR.ll
// RUN: opt -load lib/LLVMXOR.so -xor Tests/XOR_test.ll -S -o new_XOR.ll
// RUN: clang new_XOR.ll -o XOR

int main(int argc, const char *argv[])
{
    int var = 0;
    int bar = 0;
    return 0;
}
