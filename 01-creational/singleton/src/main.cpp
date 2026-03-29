#include <print>
#include <string_view>
#include <source_location>
#include <mutex>
#include <format>
#include <atomic>
#include "logger.cpp"

class LoggerOldSchool
{
private:
    static LoggerOldSchool* __instance;
    LoggerOldSchool(void) = default;

public:
    static LoggerOldSchool* getInstance(void);
    void sayHello(void);
};

LoggerOldSchool* LoggerOldSchool::__instance = nullptr;
LoggerOldSchool* LoggerOldSchool::getInstance(void)
{
    if (LoggerOldSchool::__instance == nullptr)
    {
        LoggerOldSchool::__instance = new LoggerOldSchool();
    }
    return LoggerOldSchool::__instance;
}
void LoggerOldSchool::sayHello(void)
{
    std::print("Hello from old-school logger\n");
}

int main(void)
{

    LoggerOldSchool* loggerOldSchool_p = LoggerOldSchool::getInstance();
    loggerOldSchool_p->sayHello();

    Logger& logger = Logger::getInstance();
    logger.sayHello();

    // Disable all logs
    logger.setLogLevel(LogLevel::NO_LOGS);
    logger.log(LogLevel::ERROR, "This will NOT print.");

    // Enable only Errors and Warnings
    logger.setLogLevel(LogLevel::WARNING);
    logger.log(LogLevel::ERROR, "Critical Failure!"); // Prints
    logger.log(LogLevel::INFO, "System start.");      // Ignored

    logger.log(LogLevel::ERROR, "Basic log ERROR");

    logger.setLogLevel(LogLevel::TRACE);
    logger.log(LogLevel::INFO, "This should be printed");
    logger.log(LogLevel::TRACE, "This should be printed");
    return 0;
}
