#pragma once

#include <stdio.h>
#include <mutex>
#include <ctime>

// ANSI escape codes for colors
#define RESET   "\033[0m"
#define BLACK   "\033[40m"
#define RED     "\033[41m" //error
#define GREEN   "\033[42m" //debug
#define YELLOW  "\033[43m" //info                                                 
#define BLUE    "\033[44m"
#define MAGENTA "\033[45m" //critical
#define CYAN    "\033[46m" //warn
#define WHITE   "\033[47m" //Trace

enum class LogPriority
{
	TracePriority, DebugPriority, InfoPriority, WarnPriority, ErrorPriority, CriticalPriority
};

class Logger
{
private:
	LogPriority priority = LogPriority::TracePriority;
	std::mutex log_mutex;
	const char* filepath = 0;
	FILE* file = 0;

public:
	static void SetPriority(LogPriority new_priority)
	{
		get_instance().priority = new_priority;
	}

	static void EnableFileOutput()
	{
		Logger& logger_instance = get_instance();
		logger_instance.filepath = "log.txt";
		logger_instance.enable_file_output();
	}

	static void EnableFileOutput(const char* new_filepath)
	{
		Logger& logger_instance = get_instance();
		logger_instance.filepath = new_filepath;
		logger_instance.enable_file_output();
	}

	template<typename... Args>
	static void Trace(const char* message, Args... args)
	{
		get_instance().log("[Trace]\t", LogPriority::TracePriority,message, WHITE, args...);
	}

	template<typename... Args>
	static void Debug(const char* message, Args... args)
	{
		get_instance().log("[Debug]\t", LogPriority::DebugPriority, message, GREEN,args...);
	}

	template<typename... Args>
	static void Info(const char* message, Args... args)
	{
		get_instance().log("[Info]\t", LogPriority::InfoPriority, message, YELLOW,args...);
	}

	template<typename... Args>
	static void Warn(const char* message, Args... args)
	{
		get_instance().log("[Warn]\t", LogPriority::WarnPriority, message, CYAN,args...);
	}

	template<typename... Args>
	static void Error(const char* message, Args... args)
	{
		get_instance().log("[Error]\t", LogPriority::ErrorPriority, message, RED,args...);
	}

	template<typename... Args>
	static void Critical(const char* message, Args... args)
	{
		get_instance().log("[Critical]\t", LogPriority::CriticalPriority, message, MAGENTA,args...);
	}



	template<typename... Args>
	static void Trace(int line, const char* source_file, const char* message, Args... args)
	{
		get_instance().log(line, source_file, "[Trace]\t", LogPriority::TracePriority, message, WHITE,args...);
	}

	template<typename... Args>
	static void Debug(int line, const char* source_file, const char* message, Args... args)
	{
		get_instance().log(line, source_file, "[Debug]\t", LogPriority::DebugPriority, message, GREEN,args...);
	}

	template<typename... Args>
	static void Info(int line, const char* source_file, const char* message, Args... args)
	{
		get_instance().log(line, source_file, "[Info]\t", LogPriority::InfoPriority, message, YELLOW,args...);
	}

	template<typename... Args>
	static void Warn(int line, const char* source_file, const char* message, Args... args)
	{
		get_instance().log(line, source_file, "[Warn]\t", LogPriority::WarnPriority, message, CYAN,args...);
	}

	template<typename... Args>
	static void Error(int line, const char* source_file, const char* message, Args... args)
	{
		get_instance().log(line, source_file, "[Error]\t", LogPriority::ErrorPriority, message, RED,args...);
	}

	template<typename... Args>
	static void Critical(int line, const char* source_file, const char* message, Args... args)
	{
		get_instance().log(line, source_file, "[Critical]\t", LogPriority::CriticalPriority, message, MAGENTA,args...);
	}

private:
	Logger() {}

	Logger(const Logger&) = delete;
	Logger& operator= (const Logger&) = delete;

	~Logger()
	{
		free_file();
	}

	static Logger& get_instance()
	{
		static Logger logger;
		return logger;
	}

	template<typename... Args>
	void log(const char* message_priority_str, LogPriority message_priority, const char* message,const char*  color ,Args... args)
	{
		if (priority <= message_priority)
		{
			std::time_t current_time = std::time(0);
			std::tm* timestamp = std::localtime(&current_time);
			char buffer[80];
			strftime(buffer, 80, "%c", timestamp);

			std::scoped_lock lock(log_mutex);
			printf("%s %s\t",color ,buffer);
			printf(message_priority_str);
			printf(message, args...);
			printf("%s\n",RESET); // Reset color after logging

			if (file)
			{
				fprintf(file, "%s\t", buffer);
				fprintf(file, message_priority_str);
				fprintf(file, message, args...);
				fprintf(file, "\n");
			}

		}
	}

	template<typename... Args>
	void log(int line_number, const char* source_file, const char* message_priority_str, LogPriority message_priority, const char* message, const char* color ,Args... args)
	{
		if (priority <= message_priority)
		{
			std::time_t current_time = std::time(0);
			std::tm* timestamp = std::localtime(&current_time);
			char buffer[80];
			strftime(buffer, 80, "%c", timestamp);

			std::scoped_lock lock(log_mutex); 
			printf("%s %s\t", color, buffer);
			printf(message_priority_str);
			printf(message, args...);
			printf(" on line %d in %s", line_number, source_file);
			printf("%s\n",RESET); // Reset color after logging

			if (file)
			{
				fprintf(file, "%s\t", buffer);
				fprintf(file, message_priority_str);
				fprintf(file, message, args...);
				fprintf(file, " on line %d in %s", line_number, source_file);
				fprintf(file, "\n");
			}
			//printf(RESET); // Reset color after logging
			//printf("%s\n", RESET); // Reset color after logging
		}
	}

	bool enable_file_output()
	{
		free_file();

		file = std::fopen(filepath, "a");

		if (file == 0)
		{
			return false;
		}

		return true;
	}

	void free_file()
	{
		if (file)
		{
			fclose(file);
			file = 0;
		}
	}
};


#define LOG_TRACE(Message, ...) (Logger::Trace(__LINE__, __FILE__, Message, __VA_ARGS__))
#define LOG_DEBUG(Message, ...) (Logger::Debug(__LINE__, __FILE__, Message, __VA_ARGS__))
#define LOG_INFO(Message, ...) (Logger::Info(__LINE__, __FILE__, Message, __VA_ARGS__))
#define LOG_WARN(Message, ...) (Logger::Warn(__LINE__, __FILE__, Message, __VA_ARGS__))
#define LOG_ERROR(Message, ...) (Logger::Error(__LINE__, __FILE__, Message, __VA_ARGS__))
#define LOG_CRITICAL(Message, ...) (Logger::Critical(__LINE__, __FILE__, Message, __VA_ARGS__))