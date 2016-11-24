#ifndef ILLEGALOPERATION_HPP
# define ILLEGALOPERATION_HPP

# include "ExecutionException.hpp"

class		IllegalOperation : public ExecutionException
{
	public:
		IllegalOperation(const std::string & instruction, int line);
};

#endif
