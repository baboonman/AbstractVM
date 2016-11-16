#ifndef OPERAND_HPP
# define OPERAND_HPP

# include "IOperand.hpp"

template<class T>
class						Operand : public IOperand
{
	public:
							Operand(std::string op, IOperand::eOperandType type);
		T					toT(std::string s, IOperand::eOperandType type);
		T					ft_mod(T a, T b);

		IOperand::eOperandType	getType( void ) const;
		int						getPrecision( void );
		std::string const &		toString( void );

	private:
		T					_op;
		IOperand::eOperandType		_type;
};

template<class T>
Operand<T>::Operand(std::string op, IOperand::eOperandType type) : _type(type)
{
	this->_op = this->_toT(op);
}

/*
template<class T>
Operand<T>::~Operand() {}
*/

template<class T>
int							Operand<T>::getPrecision( void )
{
	int						precision;

	precision = this->_type;
	return (precision);
}

template<class T>
IOperand::eOperandType		Operand<T>::getType( void ) const
{
	return (this->_type);
}

template<class T>
std::string	const &			Operand<T>::toString( void )
{
	std::string				s;

	switch (this->_type)
	{
		case Int8:
		case Int16:
		case Int32:
			s = std::itoa(this->_op);
			break;
		case Float :
			s = std::ftoa(this->_op);
			break;
		case Double :
			s = std::dtoa(this->_op);
			break;
	}
	return (s);
}

/*
template<class T>
IOperand const *			Operand<T>::operator+(IOperand const & rhs)
{
	T						val;
	IOperand::eOperandType			opType;

	if (this->_type >= rhs.getType())
		opType = this->_type;
	else
		opType = rhs.getType();
	val = this->_op + rhs._op;
	return new Operand(this->_toString(val), opType);
}

template<class T>
IOperand const *			Operand<T>::operator-(IOperand const & rhs)
{
	T						val;
	IOperand::eOperandType			opType;

	if (this->_type >= rhs.getType)
		opType = this->_type;
	else
		opType = rhs.getType();
	val = this->_op - rhs._op;
	return new Operand(this->_toString(val), opType);
}

template<class T>
IOperand const *			Operand<T>::operator*(IOperand const & rhs)
{
	T						val;
	IOperand::eOperandType			opType;

	if (this->_type >= rhs.getType())
		opType = this->_type;
	else
		opType = rhs.getType();
	val = this->_op * rhs._op;
	return new Operand(this->_toString(val), opType);
}

template<class T>
IOperand const *			Operand<T>::operator/(IOperand const & rhs)
{
	T						val;
	IOperand::eOperandType			opType;

	if (this->_type >= rhs.getType())
		opType = this->_type;
	else
		opType = rhs.getType();
	val = this->_op / rhs._op;
	return new Operand(this->_toString(val), opType);
}

template<class T>
T							Operand<T>::ft_mod(T a, T b)
{
	while (a > b)
		a = a - b;
	return (a);
}

template<class T>
IOperand const *			Operand<T>::operator%(IOperand const & rhs)
{
	T						val;
	IOperand::eOperandType			opType;

	if (this->_type >= rhs.getType())
		opType = this->_type;
	else
		opType = rhs.getType();
	val = ft_mod(this->_op, rhs._op);
	return new Operand(this->_toString(val), opType);
}
*/
template<class T>
T							Operand<T>::toT(std::string s, eOperandType type)
{
	T						op;

	switch (type)
	{
		case Int8:
		case Int16:
		case Int32:
			op = std::atoi(s);
			break;
		case Float :
			op = std::atof(s);
			break;
		case Double :
			op = std::atod(s);
			break;
	}
	return (op);
}

#endif
