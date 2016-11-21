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

Token::Type					Token::getType(void) const
{
	return (this->_type);
}

std::string					Token::getTypeToString(void) const
{
	switch (this->_type) {
		case Type::INST    : return "INST";
		case Type::OPTYPE  : return "OPTYPE";
		case Type::OPINT   : return "OPINT";
		case Type::OPFLOAT : return "OPFLOAT";
		case Type::OPSCAL  : return "OPSCAL";
		case Type::DELIM   : return "DELIM";
		case Type::COMMENT : return "COMMENT";
		case Type::EOI     : return "EOI";
		case Type::UNKNOWN : return "UNKNOWN";
	}
}

std::string					Token::getValue(void) const
{
	return (this->_value);
}
