```
export PATH="/path/to/llvm/OBJ_ROOT/bin/:$PATH"
clang XOR_test.c -S -emit-llvm -o XOR.ll
opt -load lib/LLVMXOR.so -xor Tests/XOR_test.ll -S -o new_XOR.ll
clang new_XOR.ll -o XOR
```
