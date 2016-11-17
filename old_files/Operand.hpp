#ifndef OPERAND_HPP
# define OPERAND_HPP

# include <iostream>
# include <sstream>
# include "IOperand.hpp"

template<class T>
class								Operand : public IOperand
{
	public:
									Operand(std::string op, IOperand::eOperandType type);
		T							toT(std::string s) const;
		T							ft_mod(T a, T b);

		IOperand::eOperandType		getType( void ) const;
		int							getPrecision( void ) const;
		std::string const &			toString( void ) const;
		T							getOp() const;

		IOperand const *			operator+(IOperand const & rhs) const;
		IOperand const *			operator-(IOperand const & rhs) const;
		IOperand const *			operator*(IOperand const & rhs) const;

	private:
		T							_op;
		std::string					_op_str;
		IOperand::eOperandType		_type;
};

template<class T>
Operand<T>::Operand(std::string op, IOperand::eOperandType type) : _op_str(op), _type(type)
{
	this->_op = this->toT(op);
}

template<class T>
int									Operand<T>::getPrecision( void ) const
{
	int								precision;

	precision = static_cast<int>(this->_type);
	return (precision);
}

template<class T>
IOperand::eOperandType				Operand<T>::getType( void ) const
{
	return (this->_type);
}

template<class T>
T									Operand<T>::getOp() const
{
	return (this->_op);
}

template<class T>
std::string	const &					Operand<T>::toString( void ) const
{
	return (this->_op_str);
}

template<class T>
T									Operand<T>::toT(std::string s) const
{
	T								op;

	if (!(std::istringstream(s) >> op))
		op = 0;
	return (op);
}

template<class T>
IOperand const *					Operand<T>::operator+(IOperand const & rhs) const
{
	T								val;
	IOperand::eOperandType			opType;

	if (this->_type >= rhs.getType())
		opType = this->_type;
	else
		opType = rhs.getType();
	val = this->_op + this->toT(rhs.toString());
	return new Operand(std::to_string(val), opType);
}

template<class T>
IOperand const *					Operand<T>::operator-(IOperand const & rhs) const
{
	T								val;
	IOperand::eOperandType			opType;

	if (this->_type >= rhs.getType())
		opType = this->_type;
	else
		opType = rhs.getType();
	val = this->_op - this->toT(rhs.toString());
	return new Operand(std::to_string(val), opType);
}

template<class T>
IOperand const *					Operand<T>::operator*(IOperand const & rhs) const
{
	T								val;
	IOperand::eOperandType			opType;

	if (this->_type >= rhs.getType())
		opType = this->_type;
	else
		opType = rhs.getType();
	val = this->_op * this->toT(rhs.toString());
	return new Operand(std::to_string(val), opType);
}

/*
template<class T>
IOperand const *					Operand<T>::operator/(IOperand const & rhs)
{
	T								val;
	IOperand::eOperandType			opType;

	if (this->_type >= rhs.getType())
		opType = this->_type;
	else
		opType = rhs.getType();
	val = this->_op / rhs._op;
	return new Operand(this->_toString(val), opType);
}

template<class T>
T									Operand<T>::ft_mod(T a, T b)
{
	while (a > b)
		a = a - b;
	return (a);
}

template<class T>
IOperand const *					Operand<T>::operator%(IOperand const & rhs)
{
	T								val;
	IOperand::eOperandType			opType;

	if (this->_type >= rhs.getType())
		opType = this->_type;
	else
		opType = rhs.getType();
	val = ft_mod(this->_op, rhs._op);
	return new Operand(this->_toString(val), opType);
}
*/

#endif
