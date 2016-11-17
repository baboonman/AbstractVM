#include "Operand.hpp"
#include <cstdint>

std::string			getTypeStr(IOperand::eOperandType type)
{
	return std::to_string(static_cast<int>(type));
}

int					main()
{
	IOperand		*op1 = new Operand<int32_t>("43", IOperand::eOperandType::Int32);
	IOperand		*op2 = new Operand<float>("43.50", IOperand::eOperandType::Float);
	IOperand const		*res;

	std::cout << "Op1 " << op1->toString() << " type: " << std::to_string(static_cast<int>(op1->getType())) << std::endl;
	std::cout << "Op2 " << op2->toString() << " type: " << std::to_string(static_cast<int>(op2->getType())) << std::endl;

	res = *op2 + *op1;

	std::cout << "Res " << res->toString() << " type: " << getTypeStr(res->getType()) << std::endl;

	return (0);
}
