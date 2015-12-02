; ModuleID = 'XOR_test.c'
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@.str = private unnamed_addr constant [17 x i8] c"quack equals %d\0A\00", align 1

; Function Attrs: nounwind uwtable
define i32 @main() #0 {
entry:
  %retval = alloca i32, align 4
  %var = alloca i32, align 4
  %foo = alloca i32, align 4
  %ifoo = alloca i32, align 4
  %bar = alloca i32, align 4
  %quack = alloca i32, align 4
  store i32 0, i32* %retval, align 4
  store i32 0, i32* %var, align 4
  store i32 0, i32* %foo, align 4
  store i32 0, i32* %ifoo, align 4
  store i32 0, i32* %bar, align 4
  store i32 0, i32* %quack, align 4
  store i32 0, i32* %quack, align 4
  %0 = load i32, i32* %quack, align 4
  %call = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([17 x i8], [17 x i8]* @.str, i32 0, i32 0), i32 %0)
  ret i32 0
}

declare i32 @printf(i8*, ...) #1

attributes #0 = { nounwind uwtable "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = !{!"clang version 3.8.0 (http://llvm.org/git/clang.git 0c05b8e2e52c8939ac101fa0009188a971d2a685) (http://llvm.org/git/llvm cf0403d373db0ec717f6f2678fc97dcb931ff114)"}
