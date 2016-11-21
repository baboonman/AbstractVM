#include "StackSizeError.hpp"

StackSizeError::StackSizeError() : ExecutionException("Error on stack size: not enough elements.")
{
}
