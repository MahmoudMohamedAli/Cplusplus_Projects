#pragma once

#include "logger.h"

#include <assert.h>
#include <thread>


int main()
{
	Logger::EnableFileOutput();
	Logger::SetPriority(LogPriority::TracePriority);
	LOG_TRACE("Hello %s", "World");
	const char* name = "User";
	LOG_INFO("Hello %s", name);

	LOG_CRITICAL("OH NO!", name);

	LOG_WARN("Hello %d %d", 15, 28);
	
	return 0;
}