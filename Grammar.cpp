#include "Grammar.hpp"

bool			Grammar::isInstruction(const std::string & str)
{
	return (insMap.count(str) == 1);
}

bool			Grammar::isOperandType(const std::string & str)
{
	return (opTypeMap.count(str) == 1);
}

std::string		Grammar::typeToStr(const eOperandType & opType)
{
	return (typeToStrMap.at(static_cast<int>(opType)));
}

void			Grammar::printInstruction(const t_ins & ins)
{
	std::cout << "ins opcode " << opInsMap.at(ins.opcode); 
	if (ins.operand != nullptr)
		std::cout << " with operand " << ins.operand->toString();
	std::cout << " on line " << ins.line << std::endl;
}
