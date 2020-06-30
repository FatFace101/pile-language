#include "pile/Parse/ASTBuilder.h"




using namespace pile;
using namespace ast;

ASTBuilder::ASTBuilder(std::istream* input, unsigned int token_length) : 
lastToken (Tokenizer::token_space),
tokenizer(new Tokenizer(input, token_length))
{};

ASTBuilder::ASTBuilder(Tokenizer* input) : 
lastToken(Tokenizer::token_space),
tokenizer(input)
{}


bool ASTBuilder::nextToken() {
	if (tokenizer->isEof()) {
		return false;
	}
	lastToken = tokenizer->getNextToken();
};

ASTNode* ASTBuilder::getNextLine() {

	return nullptr;
};



