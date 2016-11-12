#include <hackedit/common/logging/LoggingManager.hpp>

USE_HE_LOGGING_NAMESPACE


LoggingManager::LoggingManager(std::unique_ptr<ILoggerFactory> factory): _factory(std::move(factory)) {

}

std::shared_ptr<ILogger> LoggingManager::logger(const std::string &name) {
    if(_factory != nullptr)
        return _factory->logger(name);
    return nullptr;
}
