#include "Reader.hpp"

Reader::Reader()
{
}

std::vector<Grammar::t_ins>		createProgram(const std::string & inputFile)
{
	std::ifstream				ifs(inputFile);
	std::stringstream			ss;
	bool						allgood = false;

	if (ifs.good()) {
		ss << ifs.rdbuf();
		if (ss.good())
			allgood = true;
		else
			std::cout << "Fail to read" << std::endl;
	}
	else {
		std::cout << "Fail to open" << std::endl;
	}
	
	if (allgood) {
		this->_lexPars():
	}

	ifs.close();
}

std::vector<Grammar::t_ins>		createProgram()
{
}

std::vector<Grammar::t_ins>		lexPars(const std::string & str)
{
	Lexer						lex;
	Parser						pars;
	std::vector<Grammar::t_ins>	program;

	tokens = lex.tokenize(buffer.str());
	program = pars.parseTokens(tokens);
	
	std::cout << "Lexer" << std::endl;
	for (auto tok : tokens)
		std::cout << tok << std::endl;
	}
	std::cout << "Parser" << std::endl;
	for (auto ins : program)
	{
		Grammar::printInstruction(ins);
	}
	if (lex.hasError())
		std::cout << lex.getErrorLog();
	if (pars.hasError())
		std::cout << pars.getErrorLog();
	
	return (program);
}
