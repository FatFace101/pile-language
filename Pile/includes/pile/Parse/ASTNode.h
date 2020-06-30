#ifndef PILE_AST_NODE_H
#define PILE_AST_NODE_H


#include "llvm/IR/Value.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Type.h"
#include "pile/Parse/ObjectType.h"

namespace pile {
namespace ast {

class ASTNode {

public:
	virtual llvm::Value* generateInstruction() = 0;
};

class ASTValue : ASTNode {
public:
	virtual bool isConst() = 0;
	virtual uint64_t getValue();
};
}
}
#endif