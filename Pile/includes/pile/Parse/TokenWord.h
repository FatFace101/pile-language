#ifndef PILE_TOKEN_WORD_H
#define PILE_TOKEN_WORD_H

#include "pile/Parse/Tokenizer.h"
#include "pile/Parse/ASTNode.h"
namespace pile
{
	namespace tokenword {
		class TokenWord {
		public:
			TokenWord();
			virtual ast::ASTNode* parse() = 0;
		};

		class TokenWordBinop : TokenWord {
		public:
			enum Binop {
				binop_add,
				binop_sub,
				binop_mul,
				binop_div,
				binop_shl,
				binop_shr,
			};

			TokenWordBinop(Binop op);
			ast::ASTNode* parse();
		};

		class TokenWordAssign : TokenWord {
		public:
			TokenWordAssign();
			ast::ASTNode* parse();
		};

		class TokenWordConstUInt : TokenWord {
		public:
			TokenWordConstUInt(uint64_t value);
		};

		class TokenWordConstInt : TokenWord {
		public:
			TokenWordConstInt(int64_t value);
		};

		class TokenWordConstFloat : TokenWord {
		public:
			TokenWordConstFloat(double value);
		};

	}
}

#endif
