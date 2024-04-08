#include "Logger.hpp"
int    main(void)
{
	Logger logger;
	logger.log("test");
	logger.error("error");
	logger.log("rest");
}
