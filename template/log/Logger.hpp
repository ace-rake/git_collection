#ifndef LOGGER_HPP
# define LOGGER_HPP
# include <iostream>
# include <fstream>
# include <chrono>
# include <ctime>
# include "colors.h"
// Custom class: Logger
class    Logger
{
	public:
		// Constructor
		Logger();

		// Copy assignment operator overload
		Logger& operator = (const Logger& other);

		// Destructor
		~Logger(void);

		void	log(std::string log);
		void	error(std::string log);

	protected:
		;

	private:
		std::ofstream* _log;
};

std::string getCurrentTime();

#endif
