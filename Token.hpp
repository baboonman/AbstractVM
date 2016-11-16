#ifndef TOKEN_HPP
# define TOKEN_HPP

# include <std::string>

class						Token
{
	public:
		enum class Type		{INST, OPTYPE, OPVALUE, UNKNOWN}
		
							Token(void);
							Token(const Token & rhs);
							Token(Type type, std::string str)
		virtual 			~Token(void);
		Token&				operator=(const Token & rhs);

		Type				getType(void);
		std::string			getValue(void);
		std::string			getTypeToString(void);

	private:
		Type				_type;
		std::string			_value;
		
};

#endif
