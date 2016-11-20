#ifndef PARSER_HPP
# define PARSER_HPP

# include <vector>
# include "OperandFactory.hpp"
# include "Grammar.hpp"
# include "Token.hpp"

class							Parser
{
	public:
								Parser(void);
								Parser(const Parser & rhs);
		virtual 				~Parser(void);
		Parser&					operator=(const Parser & rhs);

		std::vector<Grammar::t_ins>		parseTokens(std::vector<Token>);

	private:
		OperandFactory			_factory;

};


#endif
