This is a LLVM out-of-tree pass that transforms variable assignments to the 0 constant (int x = 0) into an exclusive or operation on that variable ( x ^ x ).

Inspired by QuarkLab's tutorial on building an out-of-tree LLVM pass.
It can be found [here](http://blog.quarkslab.com/resources/2015-11-03-llvm-dev-meeting/tutorial.pdf).

Written with LLVM and Clang 3.8.

LLVM's Integrated Tester, lit is required to run the tests.
It can be installed with the following command: `pip install --user lit`

To run it : set the `LLVM_ROOT` variable to the path to your LLVM/Clang installation then run `cmake .` followed by `make check`.

