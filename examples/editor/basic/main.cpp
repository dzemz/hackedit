#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QDebug>

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQuickStyle::setStyle("Material");

#ifdef QML_LOCAL_IMPORT_DIR
    qDebug() << QML_LOCAL_IMPORT_DIR;
    engine.addImportPath(QML_LOCAL_IMPORT_DIR);
#endif
    engine.load(QUrl("qrc:///main.qml"));

    return app.exec();
}
