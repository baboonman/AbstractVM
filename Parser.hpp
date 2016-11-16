#ifndef PARSER_HPP
# define PARSER_HPP


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


};


#endif
