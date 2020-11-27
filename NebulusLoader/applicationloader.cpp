#include <QNetworkReply>
#include "applicationloader.h"

ApplicationLoader::ApplicationLoader(QObject *parent) :
    QObject(parent),
    m_ApplicationName(""),
    m_CurrentOperation(""),
    m_ProcessedFile(""),
    m_NetworkManager()
{
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

}

void ApplicationLoader::loadApplication(QString &path)
{
    QNetworkRequest request;
    request.setUrl(path);
    m_NetworkManager->get(request);
}
