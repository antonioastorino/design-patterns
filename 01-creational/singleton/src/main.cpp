#include <print>

class LoggerOldSchool
{
private:
    static LoggerOldSchool* __instance;
    LoggerOldSchool(void);

public:
    static LoggerOldSchool* getInstance(void);
    void sayHello(void);
};

LoggerOldSchool::LoggerOldSchool(void)
{
}

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

/* Mayers singleton version
The Meyers Singleton is a real object. It has a constructor, it can hold instance state in normal member variables, it can be passed around as a reference, and it has a controlled lifetime -it's constructed on first use and destroyed when the program exits.
*/
class Logger
{
private:
    // Default constructor: private to restrict instantiation to within the class only (singleton pattern)
    Logger() = default;

public:
    // Copy constructor: deleted to prevent copying the singleton instance
    Logger(const Logger&) = delete;

    // Copy assignment operator: deleted to prevent copy-assignment of the singleton instance
    Logger& operator=(const Logger&) = delete;

    // Move constructor: deleted to prevent moving the singleton instance
    Logger(Logger&&) = delete;

    // Move assignment operator: deleted to prevent move-assignment of the singleton instance
    Logger& operator=(Logger&&) = delete;

    static Logger& getInstance(void);
    void sayHello(void);
};

Logger& Logger::getInstance(void)
{
    static Logger instance = Logger();
    return instance;
}

void Logger::sayHello(void)
{
    std::print("Hello from Mayers Singleton logger");
}

int main(void)
{
    LoggerOldSchool* loggerOldSchool_p = LoggerOldSchool::getInstance();
    Logger& logger                     = Logger::getInstance();

    loggerOldSchool_p->sayHello();
    logger.sayHello();
    return 0;
}
