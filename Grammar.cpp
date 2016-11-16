#include "Grammar.hpp"

bool			Grammar::isInstruction(const std::string & str)
{
	return (std::find(instructions.begin(), instructions.end(), str) != instructions.end());
}

bool			Grammar::isOperandType(const std::string & str)
{
	return (std::find(operandType.begin(), operandType.end(), str) != operandType.end());
}
