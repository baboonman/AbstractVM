#include "Parser.hpp"

Parser::Parser(void) : _factory()
{
}

Parser::Parser(const Parser &rhs)
{
	*this = rhs;
}

Parser::~Parser(void)
{
}

Parser    &Parser::operator=(const Parser &rhs)
{
	(void)rhs;
	return *this;
}

void					Parser::addIns(std::vector<t_ins>::iterator pos)

std::vector<t_ins>		Parser::parseToken(std::vector<Token> tokens)
{
	Token::Type			lastType = Token::Type::DELIM;
	bool				start = true;
	t_ins				new_ins;
	bool				ins_in_progress = false;
	bool				waitingForParam = false;

	for (auto it : tokens)
	{

		if (start || lastType == Token::Type::DELIM)
		{
			// check for instructions
			if (it.getType() != Token::Type::INS)
				//errror
			else
			{
				ins_info = insMap.at(it.getValue());
				new_ins.opcode = ins_info.opcode;
				waitingForParam = ins_info.hasParam;
			}
		}
		if (lastType == )
		lastType

	}
}
std::vector<t_ins>		Parser::parseToken(std::vector<Token> tokens)
{
	int					i = 0;
	std::string			current_ins;
	std::vector<t_ins>	program;
	t_ins				new_ins;
	t_ins_info			info;
	Token				token;

	do {
		token = tokens[i];
		if (token.getType() == Token::Type::INST)
		{
			info = insMap.at(token.getValue);
			new_ins.opcode = info.opcode;
			i++;
			if (info.hasParam)
			{
				token = tokens[i];
				if (token.getType() == Token::Type::OPINT || token.getType() == Token::Type::OPFLOAT)
				{
					new_ins.operand = this->_factory.createOperand();
				}
			}

		}
	} while (i < Token.size() || )
}
