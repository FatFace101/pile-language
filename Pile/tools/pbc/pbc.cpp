#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fstream>
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/WithColor.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"


#include "pile/Parse/Tokenizer.h"

using namespace llvm;
static cl::opt<std::string> InputFilename(cl::Positional, cl::desc("input filename"), cl::value_desc("filename"));


//---------------------
//        Tool
//---------------------

int main(int argc, char** argv)
{
	cl::ParseCommandLineOptions(argc, argv);
	if (InputFilename.empty())
	{
		llvm::WithColor::error() << "Input file must be specified.";
		return 0;
	}
	std::ifstream inf;
	inf.open(InputFilename);
	if (!inf) 
	{
		llvm::WithColor::error() << "Input file not found.";
		return 0;
	}
	
	pile::Tokenizer* tokenizer = new pile::Tokenizer(&inf, 1024);
	bool error = false;
	while (!error && !tokenizer->isEof()) 
	{
		int tok = tokenizer->getNextToken();
		if (tok >= 0) 
		{
			printf("Found operator %c\n", tok);
		}
		else 
		{
			switch (tok) 
			{
			case(pile::Tokenizer::token_error):
				error = true;
				break;
			case(pile::Tokenizer::token_const_dec):
				printf("Found decimal integer %llu\n", tokenizer->getInt());
				break;
			case(pile::Tokenizer::token_const_hex):
				printf("Found hex integer %llu\n", tokenizer->getInt());
				break;
			case(pile::Tokenizer::token_const_str): 
				printf("Found string \"");
				fwrite(tokenizer->getString(), sizeof(char), tokenizer->getTokenLength(), stdout);
				printf("\"\n");
				break;
			case(pile::Tokenizer::token_id):
				printf("Found identifier ");
				fwrite(tokenizer->getString(), sizeof(char), tokenizer->getTokenLength(), stdout);
				printf("\n");
				break;
			case(pile::Tokenizer::token_space):
				printf("Found space\n");
				break;
			case(pile::Tokenizer::token_eof):
				printf("EOF\n");
				break;
			case(pile::Tokenizer::token_comment):
				printf("Found comment\n");
				break;
			case(pile::Tokenizer::token_semicolon):
				printf("Semicolon\n");
				break;
			case(pile::Tokenizer::token_keyword):
				printf("Found keyword %i\n", tokenizer->getLastKeyword());
				break;
			default:
				printf("unknown\n");
			}
		}

	}


	delete tokenizer;

	inf.close();

	/*InitializeAllTargetInfos();
	InitializeAllTargets();
	InitializeAllTargetMCs();
	InitializeAllAsmParsers();
	InitializeAllAsmPrinters();*/

	llvm::LLVMContext* context;

	return 0;
}