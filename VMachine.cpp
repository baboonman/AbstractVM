#include "VMachine.hpp"

VMachine::FN VMachine::_fnArray[] = { &VMachine::_push,
									  &VMachine::_pop,
									  &VMachine::_dump,
									  &VMachine::_assert,
									  &VMachine::_add,
									  &VMachine::_sub,
									  &VMachine::_mul,
									  &VMachine::_div,
									  &VMachine::_mod,
									  &VMachine::_print,
									  &VMachine::_exit };



VMachine::VMachine()
{
}

VMachine::VMachine(const VMachine & rhs)
{
	*this = rhs;
}

VMachine::~VMachine()
{
}

VMachine&				VMachine::operator=(const VMachine & rhs)
{
	(void)rhs;
	return (*this);
}

int						VMachine::execute(std::vector<Grammar::t_ins> program)
{
	int					opcode;

	for (auto ins : program)
	{
		opcode = ins.opcode;
		((this)->*(_fnArray[opcode]))(ins);
	}
	return (0);
}

void					VMachine::_push(Grammar::t_ins const & ins)
{
	if (ins.operand == nullptr)
		std::cout << "ERROR: " << "no param" << std::endl;
	this->_stack.push_back(ins.operand);
}

void					VMachine::_pop(Grammar::t_ins const & ins)
{
	(void)ins;
	this->_stack.pop_back();
}

void					VMachine::_dump(Grammar::t_ins const & ins)
{
	(void)ins;
	for (auto it = this->_stack.rbegin() ; it != this->_stack.rend() ; it++)
	{
		std::cout << (*it)->toString() << std::endl;
	}
}

void					VMachine::_assert(Grammar::t_ins const & ins)
{
	IOperand const		*insOP, *stackOP;

	if (this->_stack.size() < 1)
		std::cout << "ERROR: " << "not enough elem on statck" << std::endl;
	if (ins.operand == nullptr)
		std::cout << "ERROR: " << "no param" << std::endl;
	insOP = ins.operand;
	stackOP = this->_stack.back();
	if (insOP->getType() > stackOP->getType())
	{
		stackOP = this->_factory.createOperand(insOP->getType(), stackOP->toString());
	}
	else if (stackOP->getType() > insOP->getType())
	{
		insOP = this->_factory.createOperand(stackOP->getType(), insOP->toString());
	}

	if (insOP->toString() != stackOP->toString())
		std::cout << "ASSERT FAILED" << std::endl;
}

void					VMachine::_add(Grammar::t_ins const & ins)
{
	(void)ins;
	IOperand const		*lhs, *rhs, *res;

	if (this->_stack.size() < 2)
		std::cout << "ERROR: " << "not enough elem on stack" << std::endl;
	lhs = this->_stack.back();
	this->_stack.pop_back();
	rhs = this->_stack.back();
	this->_stack.pop_back();
	if (lhs->getType() >= rhs->getType())
		res = *lhs + *rhs;
	else
		res = *rhs + *lhs;
	this->_stack.push_back(res);
}

void					VMachine::_sub(Grammar::t_ins const & ins)
{
	(void)ins;
}

void					VMachine::_mul(Grammar::t_ins const & ins)
{
	(void)ins;
	IOperand const		*lhs, *rhs, *res;

	if (this->_stack.size() < 2)
		std::cout << "ERROR: " << "not enough elem on stack" << std::endl;
	lhs = this->_stack.back();
	this->_stack.pop_back();
	rhs = this->_stack.back();
	this->_stack.pop_back();
	if (lhs->getType() >= rhs->getType())
		res = *lhs * *rhs;
	else
		res = *rhs * *lhs;
	this->_stack.push_back(res);

}

void					VMachine::_div(Grammar::t_ins const & ins)
{
	(void)ins;
}

void					VMachine::_mod(Grammar::t_ins const & ins)
{
	(void)ins;
}

void					VMachine::_print(Grammar::t_ins const & ins)
{
	(void)ins;
}

void					VMachine::_exit(Grammar::t_ins const & ins)
{
	(void)ins;
}
