#ifndef PARSER_HPP
# define PARSER_HPP

# include <vector>
# include "OperandFactory.hpp"
# include "Grammar.hpp"
# include "Token.hpp"
# include "OverflowError.hpp"

class							Parser
{
	public:
								Parser(void);
								Parser(const Parser & rhs);
		virtual 				~Parser(void);
		Parser&					operator=(const Parser & rhs);

		std::vector<Grammar::t_ins>		parseTokens(std::vector<Token>);

		bool						hasError(void) const;
		const std::string &			getErrorLog(void) const;

	private:
		bool						_nextToken(Token & token, std::size_t & i,
										const std::vector<Token> &tokens, std::size_t len, int line);
		void						_addError(std::string const & error, int line);
		void						_addError(const OverflowError &e, int line);

		OperandFactory				_factory;
		bool						_hasError;
		std::string					_errorLog;

};


#endif
