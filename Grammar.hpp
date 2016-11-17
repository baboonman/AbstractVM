#ifndef GRAMMAR_HPP
# define GRAMMAR_HPP

# include <string>
# include <vector>
# include <unordered_map>
# include <iostream>

namespace Grammar
{
	typedef struct		s_ins_info
	{
		int				opcode;
		bool			hasParam;
	}					t_ins_info;

	static const std::vector<std::string>	instructions = {"push", "pop", "dump", "assert", "add", "sub", "mul", "div", "mod", "print", "exit"};

	static const std::vector<std::string>	operandType = {"int8", "int16", "int32", "float", "double"};

	static const std::unordered_map<std::string, t_ins_info>		insMap = {
							{"push", {0, true}},
							{"pop", {1, false}},
							{"dump", {2, false}},
							{"assert", {3, true}},
							{"add", {4, false}},
							{"sub", {5, false}},
							{"mul", {6, false}},
							{"div", {7, false}},
							{"mod", {8, false}},
							{"print", {9, false}},
							{"exit", {10, false}}};

	bool									isInstruction(const std::string & str);
	bool									isOperandType(const std::string & str);
}

#endif
