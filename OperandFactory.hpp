#ifndef OPERANDFACTORY_HPP
# define OPERANDFACTORY_HPP

# include <string>
# include "Operand.hpp"


class OperandFactory
{
	public:
		typedef IOperand const * (OperandFactory::*FN)(std::string const &) const;

							OperandFactory(void);

		IOperand const		*createOperand(eOperandType type, std::string const & value) const;

	private:
		IOperand const 		*_createInt8(std::string const & value) const;
		IOperand const 		*_createInt16(std::string const & value) const;
		IOperand const 		*_createInt32(std::string const & value) const;
		IOperand const 		*_createFloat(std::string const & value) const;
		IOperand const 		*_createDouble(std::string const & value) const;

		static FN			_fnArray[5];
		

};

#endif
