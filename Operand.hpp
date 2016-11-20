#ifndef OPERAND_HPP
# define OPERAND_HPP

# include <iostream>
# include <sstream>
# include "IOperand.hpp"

template<class T>
class								Operand : public IOperand
{
	public:
									Operand(std::string op, eOperandType type);

		eOperandType				getType( void ) const;
		int							getPrecision( void ) const;
		std::string const &			toString( void ) const;
		T							getOp() const;

		IOperand const *			operator+(IOperand const & rhs) const;
		IOperand const *			operator-(IOperand const & rhs) const;
		IOperand const *			operator*(IOperand const & rhs) const;
		IOperand const *			operator/(IOperand const & rhs) const;
		IOperand const *			operator%(IOperand const & rhs) const;

	private:
		T							_toT(std::string s) const;
		T							_ft_mod(T a, T b) const;

		T							_op;
		std::string					_op_str;
		eOperandType				_type;
};

template<class T>
Operand<T>::Operand(std::string op, eOperandType type) : _op_str(op), _type(type)
{
	this->_op = this->_toT(op);
}

template<class T>
int									Operand<T>::getPrecision( void ) const
{
	int								precision;

	precision = static_cast<int>(this->_type);
	return (precision);
}

template<class T>
eOperandType						Operand<T>::getType( void ) const
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
T									Operand<T>::_toT(std::string s) const
{
	T								op;

	if (!(std::istringstream(s) >> op))
		op = 0;
	return (op);
}

template<class T>
T									Operand<T>::_ft_mod(T a, T b) const
{
	while (a > b)
		a = a - b;
	return (a);
}

template<class T>
IOperand const *					Operand<T>::operator+(IOperand const & rhs) const
{
	T								val;

	val = this->_op + this->_toT(rhs.toString());
	return new Operand(std::to_string(val), this->getType());
}

template<class T>
IOperand const *					Operand<T>::operator-(IOperand const & rhs) const
{
	T								val;
	
	val = this->_op - this->_toT(rhs.toString());
	return new Operand(std::to_string(val), this->_type);
}

template<class T>
IOperand const *					Operand<T>::operator*(IOperand const & rhs) const
{
	T								val;

	val = this->_op * this->_toT(rhs.toString());
	return new Operand(std::to_string(val), this->_type);
}

template<class T>
IOperand const *					Operand<T>::operator/(IOperand const & rhs) const
{
	T								val;

	val = this->_op / this->_toT(rhs.toString());
	return new Operand(std::to_string(val), this->_type);
}

template<class T>
IOperand const *					Operand<T>::operator%(IOperand const & rhs) const
{
	T								val;

	val = this->_ft_mod(this->_op, this->_toT(rhs.toString()));
	return new Operand(std::to_string(val), this->_type);
}

#endif