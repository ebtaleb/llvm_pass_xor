This is a LLVM pass that transforms variable assignments to the 0 constant (int x = 0) into an exclusive or operation on that variable ( x ^ x ).

Written with LLVM and Clang 3.8 svn.

To run it : put your LLVM object tree in $PATH (or export it into the script)  and run `./run.sh`

