#pragma once

#include <hackedit/common/logging/ILogger.hpp>
#include <log4cplus/logger.h>

BEGIN_HE_LOGGING_NAMESPACE

class HE_COMMON_LOGGING_EXPORT Log4CplusLogger: public ILogger
{
public:
    Log4CplusLogger(const log4cplus::Logger& logger);
    void log(const std::string& message, LogLevel level, const char* file, int line) override;

private:
    log4cplus::Logger _logger;
};

END_HE_LOGGING_NAMESPACE
