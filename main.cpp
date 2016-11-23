#include "Reader.hpp"
#include "VMachine.hpp"

int									main(int ac, char **av)
{
	Reader							reader;
	VMachine						machine;
	std::vector<Grammar::t_ins>		program;
	std::string						input;
	std::string						option = "-v";

	if (ac == 2) {
		if (av[1] == option)
			reader.setVerbose(true);
		else
			input = av[1];
	}
	else if (ac == 3) {
		if (av[1] == option)
			reader.setVerbose(true);
		else {
			std::cout << "Unknown option " << av[1] << std::endl;
			return (1);
		}
		input = av[2];
	}
	else if (ac != 1) {
		std::cout << "Too many params." << std::endl;
		return (1);
	}

	if (input.length() == 0)
		program = reader.createProgram();
	else
		program = reader.createProgram(input);

	if (!(reader.fail())) {
		if (reader.isVerbose())
			std::cout << "----- Execution -----" << std::endl;
		machine.execute(program);
	}
	return (0);
}
