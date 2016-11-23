#include "AssertFailure.hpp"

AssertFailure::AssertFailure(int line)
	: ExecutionException("assert failed on line " + std::to_string(line))
{
}

AssertFailure::AssertFailure(const std::string & cause, int line)
	: ExecutionException("print assert failed " + cause + " on line " + std::to_string(line))
{
}
