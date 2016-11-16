#ifndef LEXER_HPP
# define LEXER_HPP

# include <std::string>

class						Lexer
{
	public:
							Lexer(void);
							Lexer(const Lexer & rhs);
		virtual 			~Lexer(void);
		Lexer&				operator=(const Lexer & rhs);

	private:
		std::vector<Token>	_tokenize(const std::string & str);

};

#endif
