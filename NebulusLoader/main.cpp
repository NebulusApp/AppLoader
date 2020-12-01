#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDir>

#include "applicationbootstrap.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QCoreApplication::setOrganizationName("EmptyFlow");
    QCoreApplication::setOrganizationDomain("emptyflow.com");
    QCoreApplication::setApplicationName("NebulusPlatform");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    QUrl url;
    url.setUrl(QStringLiteral("qrc:/main.qml"));
    if (argc > 1 && QString(argv[1]) == "update") {
        //run application by identifier
        try {
            auto applicationBootstrap = new ApplicationBootstrap();

            auto needInstall = applicationBootstrap->checkIfNeedInstallApplication();
            if (!needInstall) url.setUrl(applicationBootstrap->applicationPath());

            delete applicationBootstrap;
        }  catch (const std::invalid_argument& e) {
            qCritical() << "Argument incorect";
            QCoreApplication::exit(2);
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
