#include <istream>
#include <stdlib.h>
#ifndef PILE_TOKENIZER_H
#define PILE_TOKENIZER_H

namespace pile {

	class Tokenizer {
	public:
		enum Keyword {
			keyword_if = 0,
			keyword_else = 1,
			keyword_while = 2,
			keyword_for = 3,
			keyword_do = 4,
			keyword_break = 5,
			keyword_return = 6,
			keyword_none = -1
		};
		enum Token {
			token_space = -1,
			token_comment = -2,
			token_semicolon = -3,
			token_keyword = -4,
			token_id = -5,
			token_const_dec = -6,
			token_const_hex = -7,
			token_const_str = -8,
			token_eof = -9,
			token_error = -10
		};
		int len;
		Tokenizer(std::istream* input, unsigned int strLen);
		~Tokenizer();
		Tokenizer() = delete;
		bool isEof();
		int getNextToken();
		uint64_t getInt();
		unsigned int getTokenLength();
		char* getString();
		Keyword getLastKeyword();
	private:
		char* lastString;
		uint64_t lastInt;
		char lastChar;
		Keyword lastKeyword;
		unsigned int strLength;
		bool eof;
		std::istream* stream;
		unsigned int tokLength;

		bool nextChar();	
	};


}; //end namespace pile

#endif