#include "Lexer.hpp"
#include "Parser.hpp"
#include "VMachine.hpp"

# include <fstream>

void		print_ins(Grammar::t_ins ins)
{
	static const std::unordered_map<int, std::string> mm = {
							{0, "push"},
							{1, "pop"},
							{2, "dump"},
							{3, "assert"},
							{4, "add"},
							{5, "sub"},
							{6, "mul"},
							{7, "div"},
							{8, "mod"},
							{9, "print"},
							{10, "exit"}};
	
	std::cout << "ins opcode " << mm.at(ins.opcode); 
	if (ins.operand == nullptr)
		std::cout << std::endl;
	else
		std::cout << " with operand " << ins.operand->toString() << std::endl;
}

int			main(void)
{
	Lexer	lex;
	Parser	pars;
	VMachine	machina;

	std::vector<Token>				tokens;
	std::vector<Grammar::t_ins>		program;

	std::ifstream t("file3.avm");
	std::stringstream buffer;
	buffer << t.rdbuf();

	tokens = lex.tokenize(buffer.str());
	program = pars.parseTokens(tokens);

	std::cout << "Lexer" << std::endl;
	for (auto tok : tokens)
	{
		std::cout << "token of type " << tok.getTypeToString() << ": " << tok.getValue() << std::endl;
	}
	std::cout << "Parser" << std::endl;
	for (auto ins : program)
	{
		print_ins(ins);
	}
	std::cout << "Execution" << std::endl;
	machina.execute(program);
	return (0);
}
