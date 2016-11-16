#ifndef TOKEN_HPP
# define TOKEN_HPP

# include <string>

class						Token
{
	public:
		enum class Type		{INST, OPTYPE, OPINT, OPFLOAT, DELIM, COMMENT, EOI, UNKNOWN};
		
							Token(void);
							Token(const Token & rhs);
							Token(Type type, std::string str);
		virtual 			~Token(void);
		Token&				operator=(const Token & rhs);

		Type				getType(void) const;
		std::string			getValue(void) const;
		std::string			getTypeToString(void) const;

	private:
		Type				_type;
		std::string			_value;
		
};

#endif
