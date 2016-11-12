#include <hackedit/common/logging/LoggingManager.hpp>

USE_HE_LOGGING_NAMESPACE

std::unique_ptr<ILoggerFactory> LoggingManager::_factory = nullptr;

void LoggingManager::initialize(std::unique_ptr<ILoggerFactory> factory) {
    _factory = std::move(factory);
}

void LoggingManager::shutdown() {
    _factory = nullptr;
}

std::shared_ptr<ILogger> LoggingManager::logger(const std::string &name) {
    if(_factory != nullptr)
        return _factory->logger(name);
    return nullptr;
}
