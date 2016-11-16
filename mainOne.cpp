#include "Operand.hpp"

int					main()
{
	IOperand		*op1 = new Operand("43", IOperand::Int32);
	IOperand		*op2 = new Operand("43.50", IOperand::Float);
	IOperand		*res;

	std::cout << "Op1 " << op1->toString() << " type: " << op1->getType() << std::endl;
	std::cout << "Op2 " << op2->toString() << " type: " << op2->getType() << std::endl;

	res = op1 * op2;

	std::cout << "Res " << res->toString() << " type: " << res->getType() << std::endl;

	return (0);
}
