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

OperandFactory VMachine::_factory;

VMachine::VMachine() : _hasExited(false)
{
}

VMachine::VMachine(const VMachine & rhs)
{
	*this = rhs;
}

VMachine::~VMachine()
{
	for (auto op : this->_stack) {
		delete op;
	}
	this->_stack.clear();
}

VMachine&				VMachine::operator=(const VMachine & rhs)
{
	return (copyThis(*this, rhs));
}

VMachine&				copyThis(VMachine & lhs, const VMachine & rhs)
{
	lhs._stack = rhs._stack;
	lhs._hasExited = rhs._hasExited;
	return (lhs);
}

int						VMachine::execute(std::vector<Grammar::t_ins> program)
{
	int					opcode;

	for (auto ins : program)
	{
		opcode = ins.opcode;
		try {
			((this)->*(_fnArray[opcode]))(ins);
		} catch (ExecutionException & e) {
			this->_printError(e.what());
			return (1);
		} catch (OverflowError & e) {
			this->_printError(e.what());
			return (1);
		}
	}
	if (!this->_hasExited)
		this->_printError("program not correctly terminated ; expecting exit as last instruction.");
	return (0);
}

void					VMachine::_printError(const std::string & error) const
{
	std::cout << "\033[31mExecution error\033[0m " << error << std::endl;
}

void					VMachine::_push(Grammar::t_ins const & ins)
{
	this->_stack.push_back(ins.operand);
}

void					VMachine::_pop(Grammar::t_ins const & ins)
{
	IOperand const		*stackOP;

	if (this->_stack.size() == 0)
		throw StackSizeError("pop", ins.line);
	stackOP = this->_stack.back();
	this->_stack.pop_back();
	delete stackOP;
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
		throw StackSizeError("assert", ins.line);
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
		throw AssertFailure(ins.line);
	delete insOP;
}

void					VMachine::_add(Grammar::t_ins const & ins)
{
	IOperand const		*lhs, *rhs, *res;

	if (this->_stack.size() < 2)
		throw StackSizeError("add", ins.line);
	rhs = this->_stack.back();
	this->_stack.pop_back();
	lhs = this->_stack.back();
	this->_stack.pop_back();
	if (lhs->getType() >= rhs->getType())
		res = *lhs + *rhs;
	else
		res = *rhs + *lhs;
	this->_stack.push_back(res);
	delete rhs;
	delete lhs;
}

void					VMachine::_sub(Grammar::t_ins const & ins)
{
	IOperand const		*lhs, *rhs, *res, *prom;

	if (this->_stack.size() < 2)
		throw StackSizeError("sub", ins.line);
	rhs = this->_stack.back();
	this->_stack.pop_back();
	lhs = this->_stack.back();
	this->_stack.pop_back();
	if (lhs->getType() >= rhs->getType())
		res = *lhs - *rhs;
	else {
		prom = this->_factory.createOperand(rhs->getType(), lhs->toString());
		res = *prom - *rhs;
		delete prom;
	}
	this->_stack.push_back(res);
	delete rhs;
	delete lhs;
}

void					VMachine::_mul(Grammar::t_ins const & ins)
{
	IOperand const		*lhs, *rhs, *res;

	if (this->_stack.size() < 2)
		throw StackSizeError("mul", ins.line);
	rhs = this->_stack.back();
	this->_stack.pop_back();
	lhs = this->_stack.back();
	this->_stack.pop_back();
	if (lhs->getType() >= rhs->getType())
		res = *lhs * *rhs;
	else
		res = *rhs * *lhs;
	this->_stack.push_back(res);
	delete rhs;
	delete lhs;
}

void					VMachine::_div(Grammar::t_ins const & ins)
{
	IOperand const		*lhs, *rhs, *res, *prom;

	if (this->_stack.size() < 2)
		throw StackSizeError("div", ins.line);
	rhs = this->_stack.back();
	this->_stack.pop_back();
	lhs = this->_stack.back();
	this->_stack.pop_back();
	if (rhs->toString() == "0")
		throw IllegalOperation("divide", ins.line);
	if (lhs->getType() >= rhs->getType())
		res = *lhs / *rhs;
	else {
		prom = this->_factory.createOperand(rhs->getType(), lhs->toString());
		res = *prom / *rhs;
		delete prom;
	}
	this->_stack.push_back(res);
	delete rhs;
	delete lhs;
}

void					VMachine::_mod(Grammar::t_ins const & ins)
{
	IOperand const		*lhs, *rhs, *res, *prom;

	if (this->_stack.size() < 2)
		throw StackSizeError("div", ins.line);
	rhs = this->_stack.back();
	this->_stack.pop_back();
	lhs = this->_stack.back();
	this->_stack.pop_back();
	if (rhs->toString() == "0")
		throw IllegalOperation("do modulo", ins.line);
	if (lhs->getType() >= rhs->getType())
		res = *lhs / *rhs;
	else {
		prom = this->_factory.createOperand(rhs->getType(), lhs->toString());
		res = *prom % *rhs;
		delete prom;
	}
	this->_stack.push_back(res);
	delete rhs;
	delete lhs;
}

void					VMachine::_print(Grammar::t_ins const & ins)
{
	IOperand const		*stackOP;
	eOperandType		opType;
	
	stackOP = this->_stack.back();
	opType = stackOP->getType();
	if (opType != eOperandType::Int8)
		throw AssertFailure("operand has type " + Grammar::typeToStr(opType), ins.line);
	std::cout << static_cast<int8_t>(std::stoi(stackOP->toString())) << std::endl;
}

void					VMachine::_exit(Grammar::t_ins const & ins)
{
	(void)ins;
	this->_hasExited = true;
}
