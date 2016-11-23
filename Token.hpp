#ifndef TOKEN_HPP
# define TOKEN_HPP

# include <string>
# include <iostream>

class							Token
{
	public:
		enum class Type			{INST, OPTYPE, OPSCAL, DELIM, COMMENT, EOI, UNKNOWN};
		
								Token(void);
								Token(const Token & rhs);
								Token(Type type, std::string str);
		virtual 				~Token(void);
		Token&					operator=(const Token & rhs);
		friend std::ostream&	operator<<(std::ostream& os, const Token & obj);

		Type					getType(void) const;
		std::string				getValue(void) const;

	private:
		std::string				_getTypeToString(void) const;
		Type					_type;
		std::string				_value;
		
};

#endif
