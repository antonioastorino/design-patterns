/* Mayers singleton version
The Meyers Singleton is a real object. It has a constructor, it can hold instance state in normal member variables, it can be passed around as a reference, and it has a controlled lifetime -it's constructed on first use and destroyed when the program exits.
*/

enum class LogLevel : int
{
    NO_LOGS = -1,
    ERROR   = 0,
    WARNING = 1,
    INFO    = 2,
    DEBUG   = 3,
    TRACE   = 4
};

class Logger
{
public:
    // Singleton: No copying or moving
    Logger(const Logger&)            = delete;
    Logger& operator=(const Logger&) = delete;
    static Logger& getInstance();
    void sayHello(void);
    void setLogLevel(LogLevel level);

    // Templates must stay in the header
    template <typename... Args>
    void log(LogLevel level, std::format_string<Args...> fmt, Args&&... args, const std::source_location location = std::source_location::current())
    {
        if (std::to_underlying(level) <= std::to_underlying(this->__currentThreshold.load(std::memory_order_relaxed)))
        {
            auto lock = std::scoped_lock(this->__mtx);

            std::print("[{}] {}:{}: ", this->__toLabel(level), location.file_name(), location.line());
            std::vprint_unicode(fmt.get(), std::make_format_args(args...));
            std::print("\n");
        }
    }

private:
    Logger() = default;
    std::mutex __mtx;
    std::atomic<LogLevel> __currentThreshold{LogLevel::INFO};
    std::string_view __toLabel(LogLevel level);
};
