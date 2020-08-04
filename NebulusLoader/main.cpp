#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>

#include "qmlfileprocessor.h"
#include "applicationloader.h"
#include "applicationslibrary.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QUrl url;
    if (argc == 1) {
        //if run without an argument then show available applications and settings page

        //register inner toolset for work with applications data and setup
        qmlRegisterType<QmlFileProcessor>("Nebulus", 1, 0, "QmlFileProcessor");
        qmlRegisterType<ApplicationLoader>("Nebulus", 1, 0, "ApplicationLoader");

        url.setUrl(QStringLiteral("qrc:/main.qml"));
    } else {
        //if run with an argument, then run the application by the appId
        auto applicationLibrary = new ApplicationsLibrary();
        applicationLibrary->setApplicationIdentifier(argv[1]);
        auto applicationPath = applicationLibrary->getApplicationPath();

        QDir::addSearchPath("res", applicationPath);
        engine.addImportPath(applicationPath);

        url.setUrl(QStringLiteral("res:main.qml"));
    }

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
