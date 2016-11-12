#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
#ifdef QML_LOCAL_IMPORT_DIR
    qDebug() << QML_LOCAL_IMPORT_DIR;
    engine.addImportPath(QML_LOCAL_IMPORT_DIR);
#endif
    engine.load(QUrl("qrc:///main.qml"));

    return app.exec();
}
