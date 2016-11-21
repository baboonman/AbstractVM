#include "Grammar.hpp"

bool			Grammar::isInstruction(const std::string & str)
{
	return (insMap.count(str) == 1);
}

bool			Grammar::isOperandType(const std::string & str)
{
	return (opTypeMap.count(str) == 1);
}
