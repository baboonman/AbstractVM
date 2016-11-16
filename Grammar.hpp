#ifndef GRAMMAR_HPP
# define GRAMMAR_HPP

# include <string>
# include <vector>
# include <iostream>

namespace Grammar
{
	static const std::vector<std::string>	instructions = {"push", "pop", "dump", "assert", "add", "sub", "mul", "div", "mod", "print", "exit"};

	static const std::vector<std::string>	operandType = {"int8", "int16", "int32", "float", "double"};

	bool									isInstruction(const std::string & str);
	bool									isOperandType(const std::string & str);
}

#endif
