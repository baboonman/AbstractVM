#ifndef VMACHINE_HPP
# define VMACHINE_HPP


class						VMachine
{
	public:
							VMachine();
							VMachine(VMachine const & rhs);
		virtual				~VMachine();

		void				executeFile();
		void				executeFd();
		VMachine &			operator=(VMachine const & rhs);

	private:
		void				executeLine(int lineNb, std::string line);

	private:
		std::stack			_opStack
}


#endif
