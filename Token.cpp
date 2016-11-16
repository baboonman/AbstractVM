#include "Token.hpp"

Token::Token(void)
{
}

Token::Token(const Token & rhs)
{
	*this = rhs;
}

Token::Token(Type type, std::string value) : _type(type), _value(value)
{
}

Token::~Token(void)
{
}

Token&   					Token::operator=(const Token & rhs)
{
	this->_type = rhs.getType();
	this->_value = rhs.getValue();
	return *this;
}

Token::Type					Token::getType(void)
{
	return (this->_type);
}

std::string					Token::getTypeToString(void)
{
	switch (this->_type) {
		case INST    : return "INST";
		case OPTYPE  : return "OPTYPE";
		case OPINT   : return "OPINT";
		case OPFLOAT : return "OPFLOAT";
		case UNKNOWN : return "UNKNOWN";
	}
}

std::string					Token::getValue(void)
{
	return (this->_value);
}
