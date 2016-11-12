#pragma once

#include <hackedit/common/HackEditNamespace.hpp>
#include <hackedit/common/logging/Exports.hpp>
#include <hackedit/common/logging/LogLevel.hpp>
#include <sstream>
#include <string>

BEGIN_HACKEDIT_NAMESPACE2(Common, Logging)

class HE_COMMON_LOGGING_EXPORT ILogger
{
public:
    virtual ~ILogger();
    virtual void log(const std::string& logEvent, LogLevel level, const char* file, int line) = 0;
};

END_HACKEDIT_NAMESPACE2
