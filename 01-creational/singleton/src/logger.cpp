#include "../include/logger.hpp"

Logger& Logger::getInstance()
{
    static Logger instance;
    return instance;
}

void Logger::setLogLevel(LogLevel level)
{
    this->__currentThreshold.store(level, std::memory_order_relaxed);
}

std::string_view Logger::__toLabel(LogLevel level)
{
    switch (level)
    {
    case LogLevel::ERROR  : return "ERROR";
    case LogLevel::WARNING: return "WARN";
    case LogLevel::INFO   : return "INFO";
    case LogLevel::DEBUG  : return "DEBUG";
    case LogLevel::TRACE  : return "TRACE";
    default               : return "UNKNOWN";
    }
}

void Logger::sayHello(void)
{
    std::print("Hello from Mayers Singleton logger\n");
}
