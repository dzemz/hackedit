#include <hackedit/common/logging/LoggingManager.hpp>
#include <QMessageLogContext>
#include <QString>
#include <map>

USE_HACKEDIT_NAMESPACE2(Common, Logging)

std::unique_ptr<ILoggerFactory> LoggingManager::_factory = nullptr;


void messageHandler(QtMsgType type, const QMessageLogContext& context, const QString& message) {
    ILoggerPtr logger = LoggingManager::logger("Qt");
    // QtCriticalMsg, QtFatalMsg, QtSystemMsg = QtCriticalMsg
    std::map<int, LogLevel> toLogLevel = {
        {QtDebugMsg, LogLevel::Debug},
        {QtInfoMsg, LogLevel::Info},
        {QtWarningMsg, LogLevel::Warning},
        {QtCriticalMsg, LogLevel::Error},
        {QtFatalMsg, LogLevel::Fatal}
    };
    logger->log(message.toStdString(), toLogLevel[type], context.file, context.line);
}


void LoggingManager::initialize(std::unique_ptr<ILoggerFactory> factory, bool installQtMessageHandler) {
    _factory = std::move(factory);
    if(installQtMessageHandler) {
        qInstallMessageHandler(messageHandler);
    }
}

void LoggingManager::shutdown() {
    _factory = nullptr;
}

std::shared_ptr<ILogger> LoggingManager::logger(const std::string &name) {
    if(_factory != nullptr)
        return _factory->logger(name);
    return nullptr;
}
