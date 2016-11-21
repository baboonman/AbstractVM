#ifndef EXECUTIONEXCEPTION_HPP
# define EXECUTIONEXCEPTION_HPP

# include <string>
# include <stdexcept>

class		ExecutionException : public std::runtime_error
{
	public:
		ExecutionException(const std::string & error);
};

#endif
