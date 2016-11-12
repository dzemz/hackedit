#pragma once

#include <hackedit/common/logging/ILoggerFactory.hpp>

namespace log4cplus {
	class Initializer;
}

BEGIN_HE_LOGGING_NAMESPACE

/**
 * @brief The Log4CplusLoggerFactory class creates ILogger instances using the Log4CplusLogger implementation.
 */
class HE_COMMON_LOGGING_EXPORT Log4CplusLoggerFactory: public ILoggerFactory
{
public:
    /**
     * @brief Creates a basic log4cplus configuration.
     */
    Log4CplusLoggerFactory();
    /**
     * @brief Creates a property based configuration from a config file.
     * @param configFilePath Path of the config file.
     */
    Log4CplusLoggerFactory(const std::string& configFilePath);
	~Log4CplusLoggerFactory();
    /**
     * @brief Creates an ILogger instance that you can use with a logging macro.
     * @param name Name of the logger.
     * @return The created logger instance.
     */
    std::shared_ptr<ILogger> logger(const std::string &name="") override;
private:
	std::unique_ptr<log4cplus::Initializer> _initializer;
};

END_HE_LOGGING_NAMESPACE
