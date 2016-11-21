#include "ExecutionException.hpp"

ExecutionException::ExecutionException(const std::string & error) : runtime_error(error)
{
}
