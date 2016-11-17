#include <cstdint>
//#include "Operand.hpp"
#include "OperandFactory.hpp"

IOperand const *	addOp(IOperand const * lhs, IOperand const * rhs)
{
	if (lhs->getType() >= rhs->getType())
		return *lhs + *rhs;
	else
		return *rhs + *lhs;
}

IOperand const *	divOp(IOperand const * lhs, IOperand const * rhs)
{
	if (lhs->getType() >= rhs->getType())
		return *lhs / *rhs;
	else
	{
		IOperand const * tmp = new Operand<float>(lhs->toString(), rhs->getType());
		IOperand const *res = *tmp / *rhs;
		delete tmp;
		return res;
	}
	return nullptr;	
}

std::string			getTypeStr(eOperandType type)
{
	return std::to_string(static_cast<int>(type));
}

int					main()
{
	OperandFactory	fact;
//	IOperand		*op1 = new Operand<int32_t>("10", eOperandType::Int32);
	const IOperand	*op2 = new Operand<float>("3.0", eOperandType::Float);

	const IOperand	*op1 = fact.createOperand(eOperandType::Int32, "10");

	IOperand const		*res;

	std::cout << "Op1 " << op1->toString() << " type: " << std::to_string(static_cast<int>(op1->getType())) << std::endl;
	std::cout << "Op2 " << op2->toString() << " type: " << std::to_string(static_cast<int>(op2->getType())) << std::endl;

//	res = *op1 - *op2;
//	res = *op1 + *op2;
//	res = addOp(op1, op2);
//	res = addOp(op2, op1);

//	res = *op1 / *op2;
	res = divOp(op1, op2);

	std::cout << "Res " << res->toString() << " type: " << getTypeStr(res->getType()) << std::endl;

	return (0);
}
