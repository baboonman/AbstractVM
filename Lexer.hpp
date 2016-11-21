#ifndef LEXER_HPP
# define LEXER_HPP

# include <string>
# include <vector>
# include <iostream>
# include <sstream>
# include <cctype>
# include <algorithm>
# include "Grammar.hpp"
# include "Token.hpp"

class								Lexer
{
	public:
									Lexer(void);
									Lexer(const Lexer & rhs);
		virtual						~Lexer(void);
		Lexer&						operator=(const Lexer & rhs);

		std::vector<Token>			tokenize(const std::string & str);

		bool						hasError(void) const;
		const std::string &			getErrorLog(void) const;

	private:
		Token::Type					_identifyToken(const std::string &str);
		std::vector<std::string>	_processString(const std::string & str);
		void						_processComment(const std::string & str, std::vector<std::string> & array, int &i, int len);
		void						_processContent(const std::string & str, std::vector<std::string> & array, int &i, int len);
		void						_processWhitespaces(const std::string & str, int &i, int len);
		int							_isNum(const std::string & str);
		void						_addError(std::string const & error, int line);

		bool						_hasError;
		std::string					_errorLog;

};

#endif
