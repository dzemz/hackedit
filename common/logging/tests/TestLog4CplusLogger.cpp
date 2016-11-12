#include <gtest/gtest.h>
#include <hackedit/common/logging/LogLevel.hpp>
#include <hackedit/common/logging/ILogger.hpp>
#include <hackedit/common/logging/log4cplus/Log4CplusLoggerFactory.hpp>
#include <hackedit/common/Cpp14Support.hpp>

USE_HACKEDIT_NAMESPACE2(Common, Logging)

class TestLog4CplusLogger: public testing::Test {
public:
    static void SetUpTestCase() {
        factory = std::move(Log4CplusLoggerFactory::basicConfig());
    }
    static void TearDownTestCase() {
        factory = nullptr;
    }

protected:
    static std::unique_ptr<ILoggerFactory> factory;
};

std::unique_ptr<ILoggerFactory> TestLog4CplusLogger::factory = nullptr;


TEST_F(TestLog4CplusLogger, BasicConfig_TRACE_NoDisplay_OnStdout) {
    auto logger = factory->logger();
    testing::internal::CaptureStdout();
    logger->log("A message", LogLevel::Trace, __FILE__, __LINE__);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "");
}

TEST_F(TestLog4CplusLogger, BasicConfig_DEBUG_Display_OnStdout) {
    auto logger = factory->logger();
    testing::internal::CaptureStdout();
    logger->log("A message", LogLevel::Debug, __FILE__, __LINE__);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "DEBUG - A message\n");
}

TEST_F(TestLog4CplusLogger, BasicConfig_INFO_Display_OnStdout) {
    auto logger = factory->logger();
    testing::internal::CaptureStdout();
    logger->log("A message", LogLevel::Info, __FILE__, __LINE__);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "INFO - A message\n");
}

TEST_F(TestLog4CplusLogger, BasicConfig_WARNING_Display_OnStdout) {
    auto logger = factory->logger();
    testing::internal::CaptureStdout();
    logger->log("A message", LogLevel::Warning, __FILE__, __LINE__);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "WARN - A message\n");
}

TEST_F(TestLog4CplusLogger, BasicConfig_ERROR_Display_OnStdout) {
    auto logger = factory->logger();
    testing::internal::CaptureStdout();
    logger->log("A message", LogLevel::Error, __FILE__, __LINE__);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "ERROR - A message\n");
}

TEST_F(TestLog4CplusLogger, BasicConfig_FATAL_Display_OnStdout) {
    auto logger = factory->logger();
    testing::internal::CaptureStdout();
    logger->log("A message", LogLevel::Fatal, __FILE__, __LINE__);
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "FATAL - A message\n");
}
