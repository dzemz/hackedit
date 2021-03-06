#pragma once

#include <gmock/gmock.h>
#include <hackedit/common/logging/ILogger.hpp>

USE_HACKEDIT_NAMESPACE2(Common, Logging)

class MockILogger: public ILogger
{
public:
    MOCK_METHOD4(log, void(const std::string&, LogLevel, const char*, int));
};