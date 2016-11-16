#include "Lexer.hpp"

Lexer::Lexer(void)
{
}

Lexer::Lexer(const Lexer & rhs)
{
	*this = rhs;
}

Lexer::~Lexer(void)
{
}

Lexer&						Lexer::operator=(const Lexer & rhs)
{
	(void)rhs;
	return *this;
}

std::vector<Token>			Lexer::tokenize(const std::string & str)
{
	std::vector<Token>		tokens;
	std::stringstream		ss;
	std::string				token;
	std::string				s;
	Token::Type				tok_type;

	s = this->_processString(str);
	ss.str(s);
	while (std::getline(ss, token, ' '))
	{
		if (!token.empty())
		{
			tok_type = this->_identifyToken(token);
			tokens.push_back(Token(tok_type, token));
		}
	}
	return (tokens);
}

Token::Type					Lexer::_identifyToken(const std::string &str)
{
	int						fp;

	if (Grammar::isInstruction(str))
	{
		return Token::Type::INST;
	}
	if (Grammar::isOperandType(str))
	{
		return Token::Type::OPTYPE;
	}
	if (!(str.compare("\n")))
	{
		return Token::Type::DELIM;
	}
	fp = this->_isNum(str);
	if (fp == 0)
	{
		return Token::Type::OPINT;
	}
	if (fp == 1)
	{
		return Token::Type::OPFLOAT;
	}
	return Token::Type::UNKNOWN;
}

int						Lexer::_isNum(const std::string &str)
{
	int						p = 0;

	for (auto c : str)
	{
		if (c == '.' && p == 0)
			p = 1;
		else if (c == '.')
			return -1;
		else if (c < 48 || c > 57)
			return -1;
	}
	return p;
}

std::string					Lexer::_removeDups(const std::string & str)
{
	std::string				nstr = str;
	std::string::size_type i, j;

	j = 0;
	for (i = 0 ; i != str.length();)
	{
		nstr[j] = str[i];
		if (nstr[j] != '\n' || (str[i] != str[i + 1]))
			j++;
		i++;
	}
	nstr.resize(j);
	return (nstr);
}

std::string					Lexer::_processString(const std::string & str)
{
	std::string				nstr;
	std::string				searchFor = "\n";
	std::string				replaceWith = " \n ";

	nstr = this->_removeDups(str);
	for (std::string::size_type i = 0 ; (i = nstr.find(searchFor, i)) != std::string::npos ; )
	{
		nstr.replace(i, searchFor.length(), replaceWith);
		i += replaceWith.length();
	}
	std::replace(nstr.begin(), nstr.end(), '(', ' ');
	std::replace(nstr.begin(), nstr.end(), ')', ' ');
	std::replace(nstr.begin(), nstr.end(), '\t', ' ');
	return (nstr);
}
