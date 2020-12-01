#include <QNetworkReply>
#include "applicationloader.h"

ApplicationLoader::ApplicationLoader(QObject *parent) :
    QObject(parent),
    m_ApplicationName(""),
    m_CurrentOperation(""),
    m_ProcessedFile(""),
    m_ApplicationLibrary(new ApplicationsLibrary())
{
    auto arguments = QCoreApplication::arguments();
    if (arguments.count() > 1) {

    }

    m_NetworkManager = new QNetworkAccessManager();
    connect(m_NetworkManager, &QNetworkAccessManager::finished, this, &ApplicationLoader::downloadFile);
}

QString ApplicationLoader::applicationName()
{
    return m_ApplicationName;
}

void ApplicationLoader::setApplicationName(QString &applicationName)
{
    if (m_ApplicationName == applicationName) return;

    m_ApplicationName = applicationName;
    emit applicationNameChanged();
}

QString ApplicationLoader::currentOperation()
{
    return m_CurrentOperation;
}

void ApplicationLoader::setCurrentOperation(QString &currentOperation)
{
    if (m_CurrentOperation == currentOperation) return;

    m_CurrentOperation = currentOperation;
    emit currentOperationChanged();
}

QString ApplicationLoader::processedFile()
{
    return m_ProcessedFile;
}

void ApplicationLoader::setProcessedFile(QString &processedFile)
{
    if (m_ProcessedFile == processedFile) return;

    m_ProcessedFile = processedFile;
    emit processedFileChanged();
}

void ApplicationLoader::downloadFile(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::TimeoutError) return;
    if (reply->error() == QNetworkReply::ProtocolFailure) return;
    if (reply->error() == QNetworkReply::HostNotFoundError) return;


    //TODO: save to local file
}

void ApplicationLoader::downloadHash()
{
    auto serverChecksum = m_HashNetworkReply->readAll();
    auto applicationPath = m_ApplicationLibrary->applicationPath();
    auto localChecksum = getCheckSum(applicationPath);

    if (serverChecksum == localChecksum) {
        //TODO: restart application with
        return;
    }

    //TODO: forbid http, allow only https!
    QNetworkRequest request("http://" + m_ApplicationName + "/application.nebulus");
    m_NetworkManager->get(request);
}

void ApplicationLoader::loadApplication()
{
    //m_ApplicationLibrary->setApplicationIdentifier(ApplicationLoader::applicationIdentifier);

    if (m_ApplicationLibrary->applicationInLibrary()) {
        QNetworkRequest hashRequest("http://" + m_ApplicationName + "/application.hash");
        m_HashNetworkReply = m_NetworkManager->get(hashRequest);

        connect(m_HashNetworkReply, &QNetworkReply::finished, this, &ApplicationLoader::downloadHash);
    } else {

    }
}

QByteArray ApplicationLoader::getCheckSum(const QString &fileName)
{
    QFile f(fileName);
    if (f.open(QFile::ReadOnly)) {
        QCryptographicHash hash(QCryptographicHash::Algorithm::Md5);
        if (hash.addData(&f)) return hash.result();
    }
    return QByteArray();
}

void ApplicationLoader::restartApplication()
{
    auto arguments = QCoreApplication::arguments();
    QProcess::startDetached(arguments[0], arguments);
    QCoreApplication::exit(0);
}
