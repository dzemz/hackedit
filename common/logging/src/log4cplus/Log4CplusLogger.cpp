#include "LogsCplusLogger.hpp"
#include <log4cplus/loggingmacros.h>

USE_HACKEDIT_NAMESPACE2(Common, Logging)

Log4CplusLogger::Log4CplusLogger(const log4cplus::Logger &logger):
        _logger(logger) {

}

void Log4CplusLogger::log(const std::string &message, LogLevel level, const char* file, int line) {
    int logLevel = log4cplus::DEBUG_LOG_LEVEL;

    switch(level)
    {
        case LogLevel::Trace:
            logLevel = log4cplus::TRACE_LOG_LEVEL;
            break;
        case LogLevel::Debug:
            logLevel = log4cplus::DEBUG_LOG_LEVEL;
            break;
        case LogLevel::Info:
            logLevel = log4cplus::INFO_LOG_LEVEL;
            break;
        case LogLevel::Warning:
            logLevel = log4cplus::WARN_LOG_LEVEL;
            break;
        case LogLevel::Error:
            logLevel = log4cplus::ERROR_LOG_LEVEL;
            break;
        case LogLevel::Fatal:
            logLevel = log4cplus::FATAL_LOG_LEVEL;
            break;
    }
    if(_logger.isEnabledFor(logLevel))
        log4cplus::detail::macro_forced_log(_logger, logLevel, message, file, line, 0);
}
