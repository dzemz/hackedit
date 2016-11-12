#include <hackedit/common/Cpp14Support.hpp>
#include <hackedit/common/logging/log4cplus/Log4CplusLoggerFactory.hpp>
#include "LogsCplusLogger.hpp"
#include <log4cplus/configurator.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/initializer.h>

USE_HE_LOGGING_NAMESPACE

Log4CplusLoggerFactory::Log4CplusLoggerFactory(const std::string &configFilePath):
		_initializer(std::make_unique<log4cplus::Initializer>()) {
    if(configFilePath.empty())
        log4cplus::BasicConfigurator::doConfigure();
    else
        log4cplus::PropertyConfigurator::doConfigure(configFilePath);
}

Log4CplusLoggerFactory::~Log4CplusLoggerFactory() = default;

std::shared_ptr<ILogger> Log4CplusLoggerFactory::logger(const std::string &name) {
    return std::make_unique<Log4CplusLogger>(log4cplus::Logger::getInstance(name));
}
