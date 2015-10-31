#ifndef VMEXCEPTION_HPP
# define VMEXCEPTION_HPP

# include <exception>
# include <string>

class							VMException : std::exception
{
	public:
								VMException(int line, std::string error);
		virtual const char *	what() const noexcept;

	private:
		int						_line;
		std::string				_error;
};

#endif
