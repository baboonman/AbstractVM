#include "OverflowError.hpp"

OverflowError::OverflowError(const std::string & error, const std::string & str) : overflow_error(error + str)
{
}
