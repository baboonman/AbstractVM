#include "Lexer.hpp"

Lexer::Lexer(void) : _hasError(false)
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
	this->_hasError = rhs.hasError();
	this->_errorLog = rhs.getErrorLog();
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
			if (tok_type == Token::Type::UNKNOWN)
				this->_addError("Unkown token: " + token);
			else
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
	if (!(str.compare(";")))
	{
		return Token::Type::COMMENT;
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
		if (str[i] == '(' || str[i] == ')' || str[i] == '\t')
			nstr[j] = ' ';
		else
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
	std::vector<std::string>	array;
	std::string					tmp;
	int							i = 0;
	int							len = str.length();

	if (array.back() != "|ff")
		std::cout << "NO SEGV" << std::endl;
	while (i < len)
	{
		tmp.clear();
		while (i < len && (str[i] == ' ' || str[i] == '\t'))
			i++;
		if (i < len && std::isalnum(str[i])) {
			while (i < len && (std::isalnum(str[i]) || str[i] == '.'))
			{
				tmp += str[i++];
			}
			array.push_back(tmp);
		}
		if (i < len && str[i] == '\n' && array.back() != "\n") {
			array.push_back("\n");
		}
		if (i < len && str[i] == ';') {
			i++;
			if (i < len && str[i] == ';')
				array.push_back(";;");
			else {
				while (i < len && str[i] != '\n')
					i++;
			}
		}
		i++;
	}

	std::string res;
	for (auto i : array) {
		res += i + " ";
	}
	return res;
}
/*
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
	return (nstr);
}
*/
bool						Lexer::hasError(void) const
{
	return (this->_hasError);
}

const std::string &			Lexer::getErrorLog(void) const
{
	return (this->_errorLog);
}

void						Lexer::_addError(std::string const & error)
{
	if (!this->_hasError)
		this->_hasError = true;
	this->_errorLog += error;
	this->_errorLog += "\n";
}
