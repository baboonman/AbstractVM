#include "Reader.hpp"

Reader::Reader() : _errorFlag(false), _verbose(false)
{
}

Reader::Reader(bool verbose) : _errorFlag(false), _verbose(verbose)
{
}

Reader::~Reader()
{
}

Reader::Reader(const Reader & rhs)
{
	*this = rhs;
}

Reader&							Reader::operator=(const Reader & rhs)
{
	this->_errorFlag = false;
	this->_verbose = rhs.isVerbose();
	return (*this);
}

bool							Reader::fail(void) const
{
	return (this->_errorFlag);
}

bool							Reader::isVerbose(void) const
{
	return (this->_verbose);
}

void							Reader::setVerbose(bool verbose)
{
	this->_verbose = verbose;
}

std::vector<Grammar::t_ins>		Reader::createProgram(const std::string & inputFile)
{
	std::ifstream				ifs(inputFile);
	std::stringstream			ss;
	std::vector<Grammar::t_ins>	program;

	if (ifs.good()) {
		ss << ifs.rdbuf();
		if (!(ss.good())) {
			std::cout << "Fail to read input." << std::endl;
			this->_errorFlag = true;
		}
	}
	else {
		std::cout << "Fail to open given file." << std::endl;
		this->_errorFlag = true;
	}
	
	if (!(this->_errorFlag)) {
		program = this->_lexPars(ss.str());
	}

	ifs.close();
	return (program);
}

std::vector<Grammar::t_ins>		Reader::createProgram(void)
{
	std::vector<Grammar::t_ins>	program;
	std::string					input;
	std::string					str;
	bool						eof;


	while (std::cin || eof) {
		getline(std::cin, str);
		if (this->_checkEOF(str))
			eof = true;
		input += str;
		input += "\n";
	}
	if (!eof) {
		this->_errorFlag = true;
		std::cout << "Input must be terminated by ';;'." << std::endl;
	}
	if (!(this->_errorFlag)) {
		program = this->_lexPars(input);
	}
	return (program);
}

bool							Reader::_checkEOF(std::string & line)
{
	std::size_t					pos;

	if (line == ";;") {
		line = "";
		return (true);
	}
	pos = line.find(";;");
	if (pos != std::string::npos) {
		line = line.substr(0, pos);
		return (true);
	}
	return (false);
}

std::vector<Grammar::t_ins>		Reader::_lexPars(const std::string & str)
{
	Lexer						lex;
	Parser						pars;
	std::vector<Grammar::t_ins>	program;
	std::vector<Token>			tokens;

	tokens = lex.tokenize(str);
	program = pars.parseTokens(tokens);
	
	if (this->_verbose) {
		std::cout << "-----   Lexer   -----" << std::endl;
		for (auto tok : tokens) {
			std::cout << tok << std::endl;
		}
		std::cout << "-----  Parser  -----" << std::endl;
		for (auto ins : program) {
			Grammar::printInstruction(ins);
		}
	}
	if (lex.hasError()) {
		std::cout << lex.getErrorLog();
		this->_errorFlag = true;
	}
	if (pars.hasError()) {
		std::cout << pars.getErrorLog();
		this->_errorFlag = true;
	}
	return (program);
}
