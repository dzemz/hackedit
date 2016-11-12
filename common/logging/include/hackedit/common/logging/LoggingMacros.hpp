#pragma once

#include <sstream>

BEGIN_HE_LOGGING_NAMESPACE

#define LOG(logger, logEvent, logLevel) \
    if(logger != nullptr) {\
        std::stringstream ss; \
        ss << logEvent; \
        logger->log(ss.str(), logLevel, __FILE__, __LINE__); \
    }

#define LOG_TRACE(logger, logEvent) \
    LOG(logger, logEvent, LogLevel::Trace)

#define LOG_DEBUG(logger, logEvent) \
    LOG(logger, logEvent, LogLevel::Debug)

#define LOG_INFO(logger, logEvent) \
    LOG(logger, logEvent, LogLevel::Info)

#define LOG_WARN(logger, logEvent) \
    LOG(logger, logEvent, LogLevel::Warning)

#define LOG_ERROR(logger, logEvent) \
    LOG(logger, logEvent, LogLevel::Error)

#define LOG_FATAL(logger, logEvent) \
    LOG(logger, logEvent, LogLevel::Fatal)

END_HE_LOGGING_NAMESPACE