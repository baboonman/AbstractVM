#include "VMException.hpp"

VMException::VMException(int line, std::string error) : _line(line), _error(error)
{
}

const char *					VMException::what() const noexcept
{
	this->_error = "Error! Line: " + _line + ". " + this->_error;
	return (this->_error.c_str());
}
