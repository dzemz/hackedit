#pragma once

#include <hackedit/common/logging/Exports.hpp>
#include <hackedit/common/logging/ILogger.hpp>
#include <hackedit/common/logging/ILoggerFactory.hpp>
#include <hackedit/common/logging/LoggingMacros.hpp>
#include <hackedit/common/Cpp14Support.hpp>

#include <memory>
#include <string>

BEGIN_HE_LOGGING_NAMESPACE

HE_COMMON_LOGGING_EXPORT typedef std::shared_ptr<ILogger> ILoggerPtr;

class HE_COMMON_LOGGING_EXPORT LoggingManager
{
public:
    static void initialize(std::unique_ptr<ILoggerFactory> factory);
    static void shutdown();
    static ILoggerPtr logger(const std::string& name="");

private:
    static std::unique_ptr<ILoggerFactory> _factory;
};

END_HE_LOGGING_NAMESPACE
