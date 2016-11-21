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

std::vector<Grammar::t_ins>		Parser::parseTokens(std::vector<Token> tokens)
{
	std::size_t					i = 0;
	std::vector<Grammar::t_ins>	program;
	Grammar::t_ins				new_ins;
	Grammar::t_ins_info			info;
	Token						token;
	auto						token_size = tokens.size();
	eOperandType				arg_type;

	do {
		token = tokens[i];
		if (token.getType() == Token::Type::INST)
		{
			info = Grammar::insMap.at(token.getValue());
			new_ins.opcode = info.opcode;
			i++;
			if (info.hasParam)
			{
				if (i == token_size)
					std::cout << "error expecting argument" << std::endl;
					// error
				token = tokens[i];
				if (token.getType() == Token::Type::OPTYPE)
				{
					arg_type = Grammar::opTypeMap.at(token.getValue());
					i++;
					if (i != token_size) {
						token = tokens[i];
					}
					else
						std::cout << "error expecting value" << std::endl;
					new_ins.operand = this->_factory.createOperand(arg_type, token.getValue());
					program.push_back(new_ins);
				}
			}
			else
			{
				new_ins.operand = nullptr;
				program.push_back(new_ins);
			}
		}
		i++;
	} while (i < token_size);
	return program;
}
