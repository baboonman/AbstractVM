#ifndef READER_HPP
# define READER_HPP

# include "Lexer.hpp"
# include "Parser.hpp"
# include <fstream>
# include <iostream>

class									Reader
{
	public:
										Reader();
										Reader(bool verbose);
										Reader(const Reader & rhs);
		virtual							~Reader();
		Reader&							operator=(const Reader & rhs);
		std::vector<Grammar::t_ins>		createProgram(const std::string & inputFile);
		std::vector<Grammar::t_ins>		createProgram(void);
		bool							fail(void) const;
		bool							isVerbose(void) const;
		void							setVerbose(bool verbose);

	private:
		std::vector<Grammar::t_ins>		_lexPars(const std::string & str);
		bool							_checkEOF(std::string & line);
		bool							_errorFlag;
		bool							_verbose;
};


#endif
