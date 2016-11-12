#pragma once

#include <hackedit/common/logging/Macros.hpp>
#include <hackedit/common/logging/ILogger.hpp>
#include <hackedit/common/logging/ILoggerFactory.hpp>
#include <hackedit/common/logging/LoggingMacros.hpp>

#include <memory>
#include <string>

BEGIN_HE_LOGGING_NAMESPACE

HE_COMMON_LOGGING_EXPORT typedef std::shared_ptr<ILogger> ILoggerPtr;

class HE_COMMON_LOGGING_EXPORT LoggingManager
{
public:
    LoggingManager(std::unique_ptr<ILoggerFactory> factory);
    ILoggerPtr logger(const std::string& name="");

private:
    std::shared_ptr<ILoggerFactory> _factory;
};

END_HE_LOGGING_NAMESPACE
