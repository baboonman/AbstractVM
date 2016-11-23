#include "Parser.hpp"

Parser::Parser(void) : _factory(), _hasError(false)
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
	this->_hasError = rhs.hasError();
	this->_errorLog = rhs.getErrorLog();
	return *this;
}

bool		Parser::hasError(void) const
{
	return this->_hasError;
}

const std::string &				Parser::getErrorLog(void) const
{
	return this->_errorLog;
}

bool							Parser::_nextToken(Token & token, std::size_t & i,
									const std::vector<Token> &tokens, std::size_t len, int line)
{
	i++;
	if (i == len) {
		this->_addError("premature end of input.", line);
		return (false);
	}
	token = tokens[i];
	return (true);
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
	int							line = 1;
	bool						onNewLine = true;

	do {
		token = tokens[i];
		if (token.getType() == Token::Type::DELIM) {
			onNewLine = true;
			line++;
		}
		else if (token.getType() == Token::Type::INST && onNewLine)
		{
			onNewLine = false;
			info = Grammar::insMap.at(token.getValue());
			new_ins.opcode = info.opcode;
			if (info.hasParam)
			{
				if (this->_nextToken(token, i, tokens, token_size, line))
				{
					if (token.getType() == Token::Type::OPTYPE)
					{
						arg_type = Grammar::opTypeMap.at(token.getValue());
						if (this->_nextToken(token, i, tokens, token_size, line))
						{
							if (token.getType() == Token::Type::OPSCAL)
							{
								try {
									new_ins.operand = this->_factory.createOperand(arg_type, token.getValue());
									program.push_back(new_ins);
								} catch (OverflowError &e) {
									this->_addError(e, line);
								}
							}
							else
							{
								this->_addError("instruction expects paramater.", line);
								i--;
							}
						}
					}
					else
					{
						this->_addError("instruction expects a type.", line);
						i--;
					}
				}
			}
			else
			{
				new_ins.operand = nullptr;
				program.push_back(new_ins);
			}
		}
		else 
		{
			this->_addError("stray token: " + token.getValue(), line);
		}
		i++;
	} while (i < token_size);
	return program;
}

void						Parser::_addError(std::string const & error, int line)
{
	if (!this->_hasError)
		this->_hasError = true;
	this->_errorLog += "\033[33mSyntax error\033[0m on line " + std::to_string(line) + ": ";
	this->_errorLog += error;
	this->_errorLog += "\n";
}

void						Parser::_addError(const OverflowError & e, int line)
{
	if (!this->_hasError)
		this->_hasError = true;
	this->_errorLog += "\033[35mOver/Underflow error\033[0m on line " + std::to_string(line) + ": ";
	this->_errorLog += e.what();
	this->_errorLog += "\n";
}
