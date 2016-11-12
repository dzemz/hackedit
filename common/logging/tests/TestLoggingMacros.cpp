#include "mocks/MockILogger.hpp"
#include <hackedit/common/logging/LoggingMacros.hpp>
#include <hackedit/common/logging/ILogger.hpp>
#include <gtest/gtest.h>
#include <memory>

USE_HACKEDIT_NAMESPACE2(Common, Logging)
using testing::Return;
using ::testing::_;

class TestLoggingMacros: public testing::Test {

};

TEST_F(TestLoggingMacros, LogMacros_With_Nullptr_DoesNotCrash)
{
    std::shared_ptr<ILogger> logger = nullptr;
    LOG_TRACE(logger, "blabla");
    LOG_DEBUG(logger, "blabla");
    LOG_INFO(logger, "blabla");
    LOG_WARN(logger, "blabla");
    LOG_ERROR(logger, "blabla");
    LOG_FATAL(logger, "blabla");
}

TEST_F(TestLoggingMacros, LOG_TRACE)
{
    auto logger = std::make_shared<MockILogger>();
    EXPECT_CALL(*logger.get(), log("blabla", LogLevel::Trace, _, _));
    LOG_TRACE(logger, "blabla");
}

TEST_F(TestLoggingMacros, LOG_DEBUG)
{
    auto logger = std::make_shared<MockILogger>();
    EXPECT_CALL(*logger.get(), log("blabla", LogLevel::Debug, _, _));
    LOG_DEBUG(logger, "blabla");
}

TEST_F(TestLoggingMacros, LOG_INFO)
{
    auto logger = std::make_shared<MockILogger>();
    EXPECT_CALL(*logger.get(), log("blabla", LogLevel::Info, _, _));
    LOG_INFO(logger, "blabla");
}

TEST_F(TestLoggingMacros, LOG_WARN)
{
    auto logger = std::make_shared<MockILogger>();
    EXPECT_CALL(*logger.get(), log("blabla", LogLevel::Warning, _, _));
    LOG_WARN(logger, "blabla");
}

TEST_F(TestLoggingMacros, LOG_ERROR)
{
    auto logger = std::make_shared<MockILogger>();
    EXPECT_CALL(*logger.get(), log("blabla", LogLevel::Error, _, _));
    LOG_ERROR(logger, "blabla");
}

TEST_F(TestLoggingMacros, LOG_FATAL)
{
    auto logger = std::make_shared<MockILogger>();
    EXPECT_CALL(*logger.get(), log("blabla", LogLevel::Fatal, _, _));
    LOG_FATAL(logger, "blabla");
}
