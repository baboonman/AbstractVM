#ifndef ASSERTFAILURE_HPP
# define ASSERTFAILURE_HPP

# include "ExecutionException.hpp"

class			AssertFailure : public ExecutionException
{
	public:
		AssertFailure();
};

#endif
