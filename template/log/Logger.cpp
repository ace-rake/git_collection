#include "Logger.hpp"

// Constructor
Logger::Logger()
{
	this->_log = new std::ofstream("Log.txt", std::ios::app);
	*this->_log << std::endl << getCurrentTime() << "Start of log\n";
}

// Copy assignment operator overload
Logger& Logger::operator = (const Logger& other)
{
	std::cout << "Logger: copying object (assignement)\n";
	if (this != &other)
		_log = other._log;
	return (*this);
}

// Destructor
Logger::~Logger(void)
{
	*this->_log << std::endl << getCurrentTime() << "End of log\n\n";
	delete this->_log;
}

void	Logger::log(std::string log)
{
	*this->_log << BRIGHT_GREEN << std::endl << getCurrentTime() << log << RESET << std::endl;
}

void	Logger::error(std::string log)
{
	*this->_log << std::endl << BRIGHT_RED << getCurrentTime() << log << RESET << std::endl;
}

std::string getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t(now);
    std::string currentTime = std::ctime(&now_c);
    return currentTime;
}
