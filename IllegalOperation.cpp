#include "IllegalOperation.hpp"

IllegalOperation::IllegalOperation(const std::string & instruction, int line)
	: ExecutionException("illegal operation ; trying to " + instruction + " by 0 on line " + std::to_string(line))
{
}
