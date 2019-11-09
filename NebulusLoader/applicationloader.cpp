#include "applicationloader.h"

ApplicationLoader::ApplicationLoader(QObject *parent) :
    QObject(parent),
    m_ApplicationName(""),
    m_CurrentOperation(""),
    m_ProcessedFile("")
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
