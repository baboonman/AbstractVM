#include "StackSizeError.hpp"

StackSizeError::StackSizeError(const std::string & instruction, int line) 
	: ExecutionException("call of " + instruction + " on line " + std::to_string(line) + " with not enough elements on stack")
{
}
