#ifndef READER_HPP
# define READER_HPP

# include "Lexer.hpp"
# include "Parser.hpp"
# include <fstream>

class									Reader
{
	public:
										Reader();
		std::vector<Grammar::t_ins>		createProgram(const std::string & inputFile);
		std::vector<Grammar::t_ins>		createProgram();

	private:
		std::vector<Grammar::t_ins>		lexPars();
};


#endif
