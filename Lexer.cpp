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
	std::vector<Token>			tokens;
	std::string					token;
	Token::Type					tok_type;
	std::vector<std::string>	split;
	int							line = 1;

	split = this->_processString(str);
	for (auto token : split)
	{
		if (!token.empty())
		{
			if (token == "\n")
				line++;
			tok_type = this->_identifyToken(token);
			if (tok_type == Token::Type::UNKNOWN)
				this->_addError("Unkown token: " + token, line);
			else
				tokens.push_back(Token(tok_type, token));
		}
	}
	return (tokens);
}

Token::Type					Lexer::_identifyToken(const std::string &str)
{
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
	if (this->_isNum(str) > -1)
	{
		return Token::Type::OPSCAL;
	}
	return Token::Type::UNKNOWN;
}

int						Lexer::_isNum(const std::string &str)
{
	int						p = 0;
	bool					start = true;

	for (auto c : str)
	{
		if (c == '.' && p == 0 && !start)
			p = 1;
		else if (!start && c == '-')
			return -2;
		else if ((c < 48 || c > 57) && c != '-')
			return -1;
		start = false;
	}
	return p;
}

void						Lexer::_processComment(const std::string & str, std::vector<std::string> & array, int &i, int len)
{
	if (i < len && str[i] == ';') {
		i++;
		if (i < len && str[i] == ';')
			array.push_back(";;");
		else {
			while (i < len && str[i] != '\n')
				i++;
		}
	}
}

void						Lexer::_processContent(const std::string & str, std::vector<std::string> & array, int &i, int len)
{
	std::string					tmp;

	while (i < len && (std::isalnum(str[i]) || str[i] == '.' || str[i] == '-'))
	{
		tmp += str[i++];
	}
	if (tmp.length() > 0)
		array.push_back(tmp);
}

void						Lexer::_processWhitespaces(const std::string & str, int &i, int len)
{
	while (i < len && (str[i] == ' ' || str[i] == '\t'))
		i++;
}

std::vector<std::string>		Lexer::_processString(const std::string & str)
{
	std::vector<std::string>	array;
	int							i = 0;
	int							len = str.length();
	int							parenthesis = 0;
	int							line = 1;

	while (i < len)
	{
		this->_processWhitespaces(str, i, len);
		this->_processContent(str, array, i, len);
		this->_processComment(str, array, i, len);
		if (i < len && str[i] == '(')
			parenthesis++;
		else if (i < len && str[i] == ')')
			parenthesis--;
		if (i < len && str[i] == '\n') {
			if (parenthesis != 0) {
				this->_addError("Non-matching parenthesis.", line);
			}
			parenthesis = 0;
			line++;
			array.push_back("\n");
		}
		i++;
	}
	return array;
}

bool						Lexer::hasError(void) const
{
	return (this->_hasError);
}

const std::string &			Lexer::getErrorLog(void) const
{
	return (this->_errorLog);
}

void						Lexer::_addError(std::string const & error, int line)
{
	if (!this->_hasError)
		this->_hasError = true;
	this->_errorLog += "\033[33mLexical error\033[0m on line " + std::to_string(line) + ": ";
	this->_errorLog += error;
	this->_errorLog += "\n";
}
