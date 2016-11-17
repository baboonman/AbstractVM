#include "Lexer.hpp"

# include <fstream>

int			main(void)
{
	Lexer	lex;
	std::vector<Token>		tokens;

	std::ifstream t("file.avm");
	std::stringstream buffer;
	buffer << t.rdbuf();

	tokens = lex.tokenize(buffer.str());

	for (auto tok : tokens)
	{
		std::cout << "token of type " << tok.getTypeToString() << ": " << tok.getValue() << std::endl;
	}
	return (0);
}
