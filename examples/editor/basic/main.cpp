#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QDebug>

#include <hackedit/common/logging/LoggingManager.hpp>
#include <hackedit/common/logging/log4cplus/Log4CplusLoggerFactory.hpp>

using namespace HackEdit::Common::Logging;

int main(int argc, char *argv[]) {
    // init logging system with a basic log4cplus config
    LoggingManager::initialize(std::make_unique<Log4CplusLoggerFactory>());

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQuickStyle::setStyle("Material");

#ifdef QML_LOCAL_IMPORT_DIR
    qDebug() << QML_LOCAL_IMPORT_DIR;
    engine.addImportPath(QML_LOCAL_IMPORT_DIR);
#endif
    engine.load(QUrl("qrc:///main.qml"));

    // run qt application main event loop
    int retVal = app.exec();

    // explicit shutdown of the logging system is required
    LoggingManager::shutdown();

    return retVal;
}
