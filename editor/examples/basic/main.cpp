#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QDebug>
#include <QIcon>

#include <hackedit/common/logging/LoggingManager.hpp>
#include <hackedit/common/logging/log4cplus/Log4CplusLoggerFactory.hpp>

using namespace HackEdit::Common::Logging;

int main(int argc, char *argv[]) {
    // init logging system with a basic log4cplus config
    LoggingManager::initialize(Log4CplusLoggerFactory::basicConfig());

    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon::fromTheme("accessories-text-editor"));
    QQmlApplicationEngine engine;
    QQuickStyle::setStyle("Material");

#ifdef QML_IMPORT_PATH
    qDebug() << QML_IMPORT_PATH;
    engine.addImportPath(QML_IMPORT_PATH);
#endif
    engine.load(QUrl("qrc:///main.qml"));

    // run qt application main event loop
    int retVal = app.exec();

    // explicit shutdown of the logging system is required
    LoggingManager::shutdown();

    return retVal;
}
