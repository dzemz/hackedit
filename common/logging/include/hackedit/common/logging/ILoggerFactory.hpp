#pragma once

#include <hackedit/common/logging/Macros.hpp>
#include <string>
#include <memory>

BEGIN_HE_LOGGING_NAMESPACE

class ILogger;

class HE_COMMON_LOGGING_EXPORT ILoggerFactory
{
public:
    virtual ~ILoggerFactory();
    virtual std::shared_ptr<ILogger> logger(const std::string& name) = 0;

};

END_HE_LOGGING_NAMESPACE
