#ifndef PARSER_HPP
# define PARSER_HPP

# include <OperandFactory.hpp>
# include <Token.hpp>

class							Parser
{
	public:
		typedef struct			s_ins
		{
			int					opcode;
			const IOperand *	operand;
		}						t_ins;

								Parser(void);
								Parser(const Parser & rhs);
		virtual 				~Parser(void);
		Parser&					operator=(const Parser & rhs);

		std::vector<t_ins>		parseTokens(std::vector<Token>);

	private:
		OperandFactory			factory;

};


#endif
