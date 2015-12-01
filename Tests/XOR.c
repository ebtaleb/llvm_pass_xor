// RUN: clang %s -O2 -S -emit-llvm -o %t.ll
// RUN: opt -load %bindir/lib/LLVMMBA${MOD_EXT} -mba %t.ll -S -o %t0.ll
// RUN: FileCheck %s < %t0.ll
// RUN: clang %t0.ll -o %t0
// RUN: %t0 -42 42
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[]) {
  if(argc != 3)
    return 1;
  int a = atoi(argv[1]),
      b = atoi(argv[2]);
// CHECK: and
  return a + b;
}
