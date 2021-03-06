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

std::string					Token::getValue(void) const
{
	return (this->_value);
}

std::string					Token::_getTypeToString(void) const
{
	switch (this->_type) {
		case Type::INST    : return "INST";
		case Type::OPTYPE  : return "OPTYPE";
		case Type::OPSCAL  : return "OPSCAL";
		case Type::DELIM   : return "DELIM";
		case Type::COMMENT : return "COMMENT";
		case Type::EOI     : return "EOI";
		case Type::UNKNOWN : return "UNKNOWN";
	}
}

std::ostream& operator<<(std::ostream& os, const Token & obj)
{
	std::string				valueStr;

	if (obj.getType() != Token::Type::DELIM)
		valueStr = obj.getValue();
	else
		valueStr = "endl";
	os << "Token of type " << obj._getTypeToString() << " :\t" << valueStr;
	return (os);
}
