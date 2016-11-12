#include "mocks/MockILogger.hpp"
#include "mocks/MockILoggerFactory.hpp"
#include <hackedit/common/logging/LoggingManager.hpp>
#include <hackedit/common/utils/Cpp14Support.hpp>
#include <gtest/gtest.h>

using namespace hackedit::common::logging;
using testing::Return;

class TestLoggingManager: public testing::Test {

};

TEST_F(TestLoggingManager, LoggersAreNullsIfNoFactorySet)
{
    LoggingManager loggingManager(nullptr);
    auto myLogger = loggingManager.logger();
    EXPECT_EQ(myLogger, nullptr);
}

TEST_F(TestLoggingManager, LoggerFactory_logger_IsCalled)
{
    auto loggerFactory = std::make_unique<MockILoggerFactory>();
    auto logger = std::make_shared<MockILogger>();
    EXPECT_CALL(*loggerFactory.get(), logger("test")).WillOnce(Return(logger));

    LoggingManager loggingManager(std::move(loggerFactory));
    auto myLogger = loggingManager.logger("test");
}
