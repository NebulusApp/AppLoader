#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "qmlfileprocessor.h"
#include "applicationloader.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<QmlFileProcessor>("Nebulus", 1, 0, "QmlFileProcessor");
    qmlRegisterType<ApplicationLoader>("Nebulus", 1, 0, "ApplicationLoader");

    QQmlApplicationEngine engine;

    /*QDir::addSearchPath("res", "D:/romanus/testqml");

    engine.addImportPath("D:/romanus/testqml");

    const QUrl url(QStringLiteral("res:main.qml"));*/

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl) QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection
    );
    engine.load(url);

    return app.exec();
}
