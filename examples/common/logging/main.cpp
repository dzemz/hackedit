#include <hackedit/common/logging/LoggingManager.hpp>
#include <hackedit/common/logging/log4cplus/Log4CplusLoggerFactory.hpp>

using namespace HackEdit::Common::Logging;

class Foo
{
public:
    Foo(): _logger(LoggingManager::logger("Foo")) {
        LOG_INFO(_logger, "Foo created");
    }

    void bar() {
        LOG_INFO(_logger, "Performing bar()");
    }

private:
    ILoggerPtr _logger;
};

int main(int, char *[]) {
    LoggingManager::initialize(Log4CplusLoggerFactory::fileConfig("example-log-config.ini"));

    // root logger
    auto logger = LoggingManager::logger();
    LOG_TRACE(logger, "this trace will not be logged");
    LOG_DEBUG(logger, "debug" << " message");
    LOG_INFO(logger, "information message");
    LOG_WARN(logger, "warning");
    LOG_ERROR(logger, "error #" << 404);
    LOG_FATAL(logger, "fatal");

    // MemoryCheck logger
    auto memCheckLogger = LoggingManager::logger("MemoryCheck");
    LOG_TRACE(memCheckLogger, "Mem check trace should be logged");

    // DatabaseOperations logger
    auto dbLogger = LoggingManager::logger("DatabaseOperations");
    LOG_WARN(dbLogger, "Db warning message should not be logged");
    LOG_ERROR(dbLogger, "Db error message should be logged");

    Foo foo;
    foo.bar();

    LoggingManager::shutdown();

    return 0;
}
