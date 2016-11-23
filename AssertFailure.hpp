#ifndef ASSERTFAILURE_HPP
# define ASSERTFAILURE_HPP

# include "ExecutionException.hpp"

class			AssertFailure : public ExecutionException
{
	public:
		AssertFailure(int line);
		AssertFailure(const std::string & cause, int line);
};

#endif
