#pragma once

#include <gmock/gmock.h>
#include <hackedit/common/logging/ILoggerFactory.hpp>

using namespace hackedit::common::logging;

class MockILoggerFactory: public ILoggerFactory
{
public:
    MOCK_METHOD1(logger, std::shared_ptr<ILogger>(const std::string&));
};
