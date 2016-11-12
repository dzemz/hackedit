#pragma once

#include <gmock/gmock.h>
#include <hackedit/common/logging/ILoggerFactory.hpp>

USE_HACKEDIT_NAMESPACE2(Common, Logging)

class MockILoggerFactory: public ILoggerFactory
{
public:
    MOCK_METHOD1(logger, std::shared_ptr<ILogger>(const std::string&));
};
