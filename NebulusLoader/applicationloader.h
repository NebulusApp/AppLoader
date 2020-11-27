#ifndef APPLICATIONLOADER_H
#define APPLICATIONLOADER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class ApplicationLoader : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString applicationName READ applicationName WRITE setApplicationName NOTIFY applicationNameChanged)
    Q_PROPERTY(QString currentOperation READ currentOperation WRITE setCurrentOperation NOTIFY currentOperationChanged)
    Q_PROPERTY(QString processedFile READ processedFile WRITE setProcessedFile NOTIFY processedFileChanged)

private:
    QString m_ApplicationName;
    QString m_CurrentOperation;
    QString m_ProcessedFile;
    QNetworkAccessManager* m_NetworkManager;

public:
    explicit ApplicationLoader(QObject *parent = nullptr);

    QString applicationName();
    void setApplicationName(QString& applicationName);

    QString currentOperation();
    void setCurrentOperation(QString& currentOperation);

    QString processedFile();
    void setProcessedFile(QString& processedFile);

    void downloadFile(QNetworkReply *reply);

    Q_INVOKABLE void loadApplication(QString& path);

signals:
    void applicationNameChanged();
    void currentOperationChanged();
    void processedFileChanged();

public slots:

};

#endif // APPLICATIONLOADER_H
