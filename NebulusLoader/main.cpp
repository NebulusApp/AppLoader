#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>

#include "qmlfileprocessor.h"
#include "applicationloader.h"
#include "applicationslibrary.h"

//if run without an argument then show available applications and settings page
void runNormal(QUrl& url) {
    //register inner toolset for work with applications data and setup
    qmlRegisterType<QmlFileProcessor>("Nebulus", 1, 0, "QmlFileProcessor");
    qmlRegisterType<ApplicationLoader>("Nebulus", 1, 0, "ApplicationLoader");

    url.setUrl(QStringLiteral("qrc:/main.qml"));
}

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QCoreApplication::setOrganizationName("EmptyFlow");
    QCoreApplication::setOrganizationDomain("emptyflow.com");
    QCoreApplication::setApplicationName("NebulusPlatform");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QUrl url;
    if (argc == 1) {
        runNormal(url);
    } else {
        auto argument = QString(argv[1]);
        if (argument.startsWith("https://")) {
            runNormal(url);
            engine.rootContext()->setContextProperty("addressForApplicationProject", QDateTime::currentDateTime());
        } else {
            //if run with an argument, then run the application by the appId
            auto applicationLibrary = new ApplicationsLibrary();
            applicationLibrary->setApplicationIdentifier(argument);
            auto applicationPath = applicationLibrary->applicationPath();

            QDir::addSearchPath("res", applicationPath);
            engine.addImportPath(applicationPath);

            url.setUrl(QStringLiteral("res:main.qml"));
        }
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
