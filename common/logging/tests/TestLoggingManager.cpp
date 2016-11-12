#include "mocks/MockILogger.hpp"
#include "mocks/MockILoggerFactory.hpp"
#include <hackedit/common/logging/LoggingManager.hpp>
#include <hackedit/common/Cpp14Support.hpp>
#include <gtest/gtest.h>

USE_HACKEDIT_NAMESPACE2(Common, Logging)
using testing::Return;

class TestLoggingManager: public testing::Test {

};

TEST_F(TestLoggingManager, LoggersAreNullsIfNoFactorySet)
{
    LoggingManager::initialize(nullptr);
    auto myLogger = LoggingManager::logger();
    EXPECT_EQ(myLogger, nullptr);
}

TEST_F(TestLoggingManager, LoggerFactory_logger_IsCalled)
{
    auto loggerFactory = std::make_unique<MockILoggerFactory>();
    auto logger = std::make_shared<MockILogger>();
    EXPECT_CALL(*loggerFactory.get(), logger("test")).WillOnce(Return(logger));

    LoggingManager::initialize(std::move(loggerFactory));
    auto myLogger = LoggingManager::logger("test");
    LoggingManager::shutdown();
}
