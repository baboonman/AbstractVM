#ifndef STACKSIZEERROR_HPP
# define STACKSIZEERROR_HPP

# include "ExecutionException.hpp"

class		StackSizeError : public ExecutionException 
{
	public:
		StackSizeError(const std::string & instruction, int line);
};

#endif
