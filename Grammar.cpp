#include "Grammar.hpp"

bool			Grammar::isInstruction(const std::string & str)
{
	return (insMap.count(str) == 1);
}

bool			Grammar::isOperandType(const std::string & str)
{
	return (opTypeMap.count(str) == 1);
}

void			Grammar::printInstruction(const t_ins & ins)
{
	std::cout << "ins opcode " << opInsMap.at(ins.opcode); 
	if (ins.operand == nullptr)
		std::cout << std::endl;
	else
		std::cout << " with operand " << ins.operand->toString() << std::endl;
}
