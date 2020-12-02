#ifndef APPLICATIONLOADER_H
#define APPLICATIONLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtQml>
#include <QCryptographicHash>
#include "applicationslibrary.h"

class ApplicationLoader : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString applicationName READ applicationName WRITE setApplicationName NOTIFY applicationNameChanged)
    Q_PROPERTY(QString currentOperation READ currentOperation WRITE setCurrentOperation NOTIFY currentOperationChanged)
    Q_PROPERTY(QString processedFile READ processedFile WRITE setProcessedFile NOTIFY processedFileChanged)

    QML_ELEMENT

private:
    QString m_ApplicationName;
    QString m_ApplicationIndetifier;
    QString m_CurrentOperation;
    QString m_ProcessedFile;
    QNetworkAccessManager* m_NetworkManager;
    ApplicationsLibrary* m_ApplicationLibrary;
    QNetworkReply* m_HashNetworkReply;

public:
    explicit ApplicationLoader(QObject *parent = nullptr);

    QString applicationName();
    void setApplicationName(QString& applicationName);

    QString currentOperation();
    void setCurrentOperation(QString& currentOperation);

    QString processedFile();
    void setProcessedFile(QString& processedFile);

    void downloadFile(QNetworkReply *reply);
    void downloadHash();

    Q_INVOKABLE void loadApplication();

private:
    QByteArray getCheckSum(const QString &fileName);
    void restartApplication();

signals:
    void applicationNameChanged();
    void currentOperationChanged();
    void processedFileChanged();

public slots:

};

#endif // APPLICATIONLOADER_H
