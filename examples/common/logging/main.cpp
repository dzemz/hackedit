#include <hackedit/common/logging/LoggingManager.hpp>
#include <hackedit/common/logging/log4cplus/Log4CplusLoggerFactory.hpp>
#include <log4cplus/initializer.h>
#include <hackedit/common/utils/Cpp14Support.hpp>

using namespace hackedit::common::logging;

class Foo
{
public:
    Foo(const std::shared_ptr<LoggingManager>& loggingManager): 
            _logger(loggingManager->logger("Foo")) {
        LOG_INFO(_logger, "Foo created");
    }

    void bar() {
        LOG_INFO(_logger, "Performing bar()");
    }

private:
    ILoggerPtr _logger;
};

int main(int, char *[]) {
    auto loggerFactory = std::make_unique<Log4CplusLoggerFactory>("example-log-config.ini");
	auto loggingManager = std::make_shared<LoggingManager>(std::move(loggerFactory));

    // root logger
    auto logger = loggingManager->logger();
    LOG_TRACE(logger, "this trace will not be logged");
    LOG_DEBUG(logger, "debug" << " message");
    LOG_INFO(logger, "information message");
    LOG_WARN(logger, "warning");
    LOG_ERROR(logger, "error #" << 404);
    LOG_FATAL(logger, "fatal");

    // MemoryCheck logger
    auto memCheckLogger = loggingManager->logger("MemoryCheck");
    LOG_TRACE(memCheckLogger, "Mem check trace should be logged");

    // DatabaseOperations logger
    auto dbLogger = loggingManager->logger("DatabaseOperations");
    LOG_WARN(dbLogger, "Db warning message should not be logged");
    LOG_ERROR(dbLogger, "Db error message should be logged");

    Foo foo(loggingManager);
    foo.bar();

    return 0;
}
