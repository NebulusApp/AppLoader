#include "applicationloader.h"

ApplicationLoader::ApplicationLoader(QObject *parent) :
    QObject(parent),
    m_ApplicationName(""),
    m_CurrentOperation(""),
    m_ProcessedFile(""),
    m_NetworkManager()
{

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

void ApplicationLoader::loadApplication(QString &path)
{
    QNetworkRequest request;
    request.setUrl(path);
    auto _reply = m_NetworkManager->get(request);
    /*connect(_reply, SIGNAL(error(QNetworkReply::NetworkError)),
                this, SLOT(error(QNetworkReply::NetworkError)));
    connect(_reply, SIGNAL(downloadProgress(qint64, qint64)),
                this, SLOT(updateProgress(qint64, qint64)));
    connect(_reply, SIGNAL(finished()),
                this, SLOT(finished()));*/
}
