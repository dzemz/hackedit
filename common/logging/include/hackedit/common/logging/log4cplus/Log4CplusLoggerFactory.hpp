#pragma once

#include <hackedit/common/logging/ILoggerFactory.hpp>

namespace log4cplus {
	class Initializer;
}

BEGIN_HACKEDIT_NAMESPACE2(Common, Logging)

/**
 * @brief The Log4CplusLoggerFactory class creates ILogger instances using the Log4CplusLogger implementation.
 */
class HE_COMMON_LOGGING_EXPORT Log4CplusLoggerFactory: public ILoggerFactory
{
public:
    /**
     * @brief Creates a property based configuration from a config file.
     * @param configFilePath Path of the config file. If path is empty, a default basic config will be used.
     */
    Log4CplusLoggerFactory(const std::string& configFilePath="");
	~Log4CplusLoggerFactory();
    /**
     * @brief Creates an ILogger instance that you can use with a logging macro.
     * @param name Name of the logger.
     * @return The created logger instance.
     */
    std::shared_ptr<ILogger> logger(const std::string &name="") override;

    static std::unique_ptr<ILoggerFactory> basicConfig();
    static std::unique_ptr<ILoggerFactory> fileConfig(const std::string& configFilePath);
private:
	std::unique_ptr<log4cplus::Initializer> _initializer;
};

END_HACKEDIT_NAMESPACE2
