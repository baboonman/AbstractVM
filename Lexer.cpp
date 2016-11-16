#include "Lexer.hpp"

Lexer::Lexer(void)
{
	std::vector<Token>		tokens;

	tokens = this->_tokenize("push int8(32)");
	for (auto tok : tokens)
	{
		std::cout << "token of type " << 
	}
}

Lexer::Lexer(const Lexer & rhs)
{
	*this = rhs;
}

Lexer&						Lexer::operator=(const Lexer & rhs)
{
}


void						split(const std::string &s)
{
	std::stringstream ss;
	ss.str(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
}

std::vector<Token>			Lexer::_tokenize(const std::string & str)
{
	std::stringstream ss;
	std::string token;
	
	ss.str(s);
	while (std::getLine(ss, token, ' '))
	{
		if (!token.isEmpty())
		{
			switch 
		}
	}
}
