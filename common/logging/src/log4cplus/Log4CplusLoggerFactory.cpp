#include <hackedit/common/Cpp14Support.hpp>
#include <hackedit/common/logging/log4cplus/Log4CplusLoggerFactory.hpp>
#include "LogsCplusLogger.hpp"
#include <log4cplus/configurator.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/initializer.h>
#include <log4cplus/helpers/property.h>

#include <iostream>

USE_HACKEDIT_NAMESPACE2(Common, Logging)


class BasicConfigurator: public log4cplus::PropertyConfigurator
{
public:
    BasicConfigurator(): log4cplus::PropertyConfigurator("") {
        properties.setProperty("rootLogger",
                               "DEBUG, STDOUT");
        properties.setProperty("appender.STDOUT",
                               "log4cplus::ConsoleAppender");
        properties.setProperty("appender.STDOUT.ImmediateFlush", "true");
    }

    static void doConfigure() {
        BasicConfigurator configurator;
        configurator.configure();
    }
};


Log4CplusLoggerFactory::Log4CplusLoggerFactory(const std::string &configFilePath):
		_initializer(std::make_unique<log4cplus::Initializer>()) {
    if(configFilePath.empty())
        BasicConfigurator::doConfigure();
    else
        log4cplus::PropertyConfigurator::doConfigure(configFilePath);
}

Log4CplusLoggerFactory::~Log4CplusLoggerFactory() = default;

std::shared_ptr<ILogger> Log4CplusLoggerFactory::logger(const std::string &name) {
    return std::make_unique<Log4CplusLogger>(log4cplus::Logger::getInstance(name));
}

std::unique_ptr<ILoggerFactory> Log4CplusLoggerFactory::basicConfig()
{
    return std::make_unique<Log4CplusLoggerFactory>();
}

std::unique_ptr<ILoggerFactory> Log4CplusLoggerFactory::fileConfig(const std::string &configFilePath)
{
    return std::make_unique<Log4CplusLoggerFactory>(configFilePath);
}
