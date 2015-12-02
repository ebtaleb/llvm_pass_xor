#!/bin/bash
export PATH="/media/jmbto/1decfa63-a052-4827-837e-f93d3d14e9d4/llvm/r/bin/:$PATH"
#export PATH="/path/to/llvm/OBJ_ROOT/bin/:$PATH"

echo
echo Listing of XOR_test.c :
echo ----------------------
cat Tests/XOR_test.c
echo ----------------------

clang Tests/XOR_test.c -S -emit-llvm -o Tests/XOR_test.ll
echo
echo IR listing of XOR_test.ll before the pass :
echo ----------------------
cat Tests/XOR_test.ll
echo ----------------------

opt -load lib/LLVMXOR.so -xor Tests/XOR_test.ll -S -o Tests/new_XOR_test.ll

echo
echo IR listing of XOR_test.ll after the pass
echo ----------------------
cat Tests/new_XOR_test.ll
echo ----------------------

clang Tests/new_XOR_test.ll -o XOR_test

echo
echo Test output
./XOR_test
