#define DEBUG_TYPE "xor"
#include "llvm/Support/Debug.h"

#include "llvm/ADT/Statistic.h"
STATISTIC(XORCount, "The # of substituted instructions");

#include "llvm/Pass.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Function.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"


using namespace llvm;

namespace {

    class XOR : public BasicBlockPass {

        public:
            static char ID;
            XOR() : BasicBlockPass(ID) {}

            bool doInitialization(Module &M) override {
                return false;
            }

            bool runOnBasicBlock(BasicBlock &BB) override {
                bool modified = false;

                for (auto IIT = BB.begin(), IE = BB.end(); IIT != IE; ++IIT) {
                    Instruction &Inst = *IIT;
                    auto *BinOp = dyn_cast<BinaryOperator>(&Inst);
                    if (!BinOp)
                        continue;

                    unsigned Opcode = BinOp->getOpcode();
                    if (Opcode != Instruction::Add || !BinOp->getType()->isIntegerTy())
                        continue;

                    IRBuilder<> Builder(BinOp);

                    Value *NewValue = Builder.CreateAdd(
                            Builder.CreateXor(BinOp->getOperand(0),
                                BinOp->getOperand(1)),
                            Builder.CreateMul(
                                ConstantInt::get(BinOp->getType(), 2),
                                Builder.CreateAnd(
                                    BinOp->getOperand(0),
                                    BinOp->getOperand(1)))
                            );

                    DEBUG(dbgs() << *BinOp << " -> " << *NewValue << "\n");

                    ReplaceInstWithValue(BB.getInstList(), IIT, NewValue);
                    modified = true;

                    ++XORCount;
                }
            return modified;
        }
    };
}

char XOR::ID = 0;
static RegisterPass<XOR>
X(  "xor",  // the option name -> -xor
    "0 Constant to XOR Substitution", // option description
    true, // true as we don't modify the CFG
    false // true if we're writing an analysis
 );

/* clang pass registration (optional)
*/
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"

static void
registerClangPass(const PassManagerBuilder &, legacy::PassManagerBase &PM) {
    PM.add(new XOR());
}

// Note the registration point, clang offers several insertion points where you
// can insert your pass.
static RegisterStandardPasses RegisterClangPass
(PassManagerBuilder::EP_EarlyAsPossible, registerClangPass);
