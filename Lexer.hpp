#ifndef LEXER_HPP
# define LEXER_HPP

# include <string>
# include <vector>
# include <iostream>
# include <sstream>
# include <algorithm>
# include "Grammar.hpp"
# include "Token.hpp"

class						Lexer
{
	public:
							Lexer(void);
							Lexer(const Lexer & rhs);
		virtual 			~Lexer(void);
		Lexer&				operator=(const Lexer & rhs);

		std::vector<Token>	tokenize(const std::string & str);

	private:
		Token::Type			_identifyToken(const std::string &str);
		std::string			_processString(const std::string & str);
		std::string			_removeDups(const std::string & str);
		int					_isNum(const std::string & str);


};

#endif
