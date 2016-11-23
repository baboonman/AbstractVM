#include "Lexer.hpp"
#include "Parser.hpp"
#include "VMachine.hpp"

# include <fstream>

int			main(int ac, char **av)
{
	Lexer	lex;
	Parser	pars;
	VMachine	machina;
	std::string		input = "file.avm";

	std::vector<Token>				tokens;
	std::vector<Grammar::t_ins>		program;

	if (ac == 2)
	{
		input = av[1];
	}
	std::ifstream t(input);
	std::stringstream buffer;
	buffer << t.rdbuf();

	tokens = lex.tokenize(buffer.str());
	program = pars.parseTokens(tokens);

	std::cout << "Lexer" << std::endl;
	for (auto tok : tokens)
	{
		std::cout << tok << std::endl;
	}
	std::cout << "Parser" << std::endl;
	for (auto ins : program)
	{
		Grammar::printInstruction(ins);
	}
	if (lex.hasError())
		std::cout << lex.getErrorLog();
	if (pars.hasError())
		std::cout << pars.getErrorLog();
	if (!lex.hasError() && !pars.hasError()) {
		std::cout << "Execution" << std::endl;
		machina.execute(program);
	}
	return (0);
}

int			main(int ac, char *av)
{
	Reader	reader;
	VMachine	machina;

	if (ac == 2)
		input = av[1];
	else
		input = "file.avm";

	program = reader.createProgram(input);
	if (program.size() > 0) {
		`
	}
}
