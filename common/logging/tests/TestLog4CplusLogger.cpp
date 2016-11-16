#include <gtest/gtest.h>
#include <hackedit/common/logging/LogLevel.hpp>
#include <hackedit/common/logging/ILogger.hpp>
#include <hackedit/common/logging/log4cplus/Log4CplusLoggerFactory.hpp>
#include <hackedit/common/Cpp14Support.hpp>
#include <QDebug>
#include <hackedit/common/logging/LoggingManager.hpp>

USE_HACKEDIT_NAMESPACE2(Common, Logging)

class TestLog4CplusLogger: public testing::Test {
public:
    static void SetUpTestCase() {
        LoggingManager::initialize(Log4CplusLoggerFactory::basicConfig(), true);
    }
};


TEST_F(TestLog4CplusLogger, BasicConfig_TRACE_NoDisplay_OnStdout_IntegrationTest) {
    auto logger = LoggingManager::logger();
    testing::internal::CaptureStdout();
    logger->log("A message", LogLevel::Trace, __FILE__, __LINE__);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
}

TEST_F(TestLog4CplusLogger, BasicConfig_DEBUG_Display_OnStdout_IntegrationTest) {
    auto logger = LoggingManager::logger();
    testing::internal::CaptureStdout();
    logger->log("A message", LogLevel::Debug, __FILE__, __LINE__);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "DEBUG - A message\n");
}

TEST_F(TestLog4CplusLogger, BasicConfig_INFO_Display_OnStdout_IntegrationTest) {
    auto logger = LoggingManager::logger();
    testing::internal::CaptureStdout();
    logger->log("A message", LogLevel::Info, __FILE__, __LINE__);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "INFO - A message\n");
}

TEST_F(TestLog4CplusLogger, BasicConfig_WARNING_Display_OnStdout_IntegrationTest) {
    auto logger = LoggingManager::logger();
    testing::internal::CaptureStdout();
    logger->log("A message", LogLevel::Warning, __FILE__, __LINE__);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "WARN - A message\n");
}

TEST_F(TestLog4CplusLogger, BasicConfig_ERROR_Display_OnStdout_IntegrationTest) {
    auto logger = LoggingManager::logger();
    testing::internal::CaptureStdout();
    logger->log("A message", LogLevel::Error, __FILE__, __LINE__);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "ERROR - A message\n");
}

TEST_F(TestLog4CplusLogger, BasicConfig_FATAL_Display_OnStdout_IntegrationTest) {
    auto logger = LoggingManager::logger();
    testing::internal::CaptureStdout();
    logger->log("A message", LogLevel::Fatal, __FILE__, __LINE__);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "FATAL - A message\n");
}

TEST_F(TestLog4CplusLogger, qWarning_Display_OnStdout_IntegrationTest) {
    auto logger = LoggingManager::logger();
    testing::internal::CaptureStdout();
    qWarning() << "test";
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "WARN - test\n");
}
