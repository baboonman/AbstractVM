#ifndef OVERFLOWERROR_HPP
# define OVERFLOWERROR_HPP

# include <stdexcept>
# include <string>

class				OverflowError : public std::overflow_error
{
	public:
		OverflowError(const std::string & error, const std::string & str);
};

#endif
