#pragma once

#include <hackedit/common/logging/Macros.hpp>
#include <hackedit/common/logging/LogLevel.hpp>
#include <sstream>
#include <string>

BEGIN_HE_LOGGING_NAMESPACE

class HE_COMMON_LOGGING_EXPORT ILogger
{
public:
    virtual ~ILogger();
    virtual void log(const std::string& logEvent, LogLevel level, const char* file, int line) = 0;
};

END_HE_LOGGING_NAMESPACE
