#include "OperandFactory.hpp"


OperandFactory::FN OperandFactory::_fnArray[5] = { &OperandFactory::_createInt8,
												   &OperandFactory::_createInt16,
												   &OperandFactory::_createInt32,
												   &OperandFactory::_createFloat,
												   &OperandFactory::_createDouble };

OperandFactory::OperandFactory(void)
{
}

IOperand const		*OperandFactory::createOperand(eOperandType type, std::string const & str) const
{
	if (static_cast<int>(type) >= 5)
		return (nullptr);
	return (  ((this)->*(_fnArray[static_cast<int>(type)]))(str)  );
}

IOperand const		*OperandFactory::_createInt8(std::string const & value) const
{
	return (new Operand<int8_t>(value, eOperandType::Int8));
}

IOperand const		*OperandFactory::_createInt16(std::string const & value) const
{
	return (new Operand<int16_t>(value, eOperandType::Int16));
}

IOperand const		*OperandFactory::_createInt32(std::string const & value) const
{
	return (new Operand<int32_t>(value, eOperandType::Int32));
}

IOperand const		*OperandFactory::_createFloat(std::string const & value) const
{
	return (new Operand<float>(value, eOperandType::Float));
}

IOperand const		*OperandFactory::_createDouble(std::string const & value) const
{
	return (new Operand<double>(value, eOperandType::Double));
}
