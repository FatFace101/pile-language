#ifndef PILE_AST_BUILDER_H
#define PILE_AST_BUILDER_H

#include <fstream>
#include "pile/Parse/Tokenizer.h"
#include "pile/Parse/ASTNode.h"
namespace pile {
	class ASTBuilder {
	public:
		ASTBuilder() = delete;
		ASTBuilder(std::istream* input, unsigned int token_length);
		ASTBuilder(Tokenizer* input);
		ast::ASTNode* getNextLine();
	private:
		Tokenizer* tokenizer;
		int lastToken;
		bool nextToken();
	};


};



#endif