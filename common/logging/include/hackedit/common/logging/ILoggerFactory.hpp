#pragma once

#include <hackedit/common/HackEditNamespace.hpp>
#include <hackedit/common/logging/Exports.hpp>
#include <string>
#include <memory>

BEGIN_HACKEDIT_NAMESPACE2(Common, Logging)

class ILogger;

class HE_COMMON_LOGGING_EXPORT ILoggerFactory
{
public:
    virtual ~ILoggerFactory();
    virtual std::shared_ptr<ILogger> logger(const std::string& name) = 0;

};

END_HACKEDIT_NAMESPACE2
