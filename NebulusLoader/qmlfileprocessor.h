#ifndef QMLFILEPROCESSOR_H
#define QMLFILEPROCESSOR_H

#include <QObject>

class QmlFileProcessor : public QObject
{
    Q_OBJECT
private:
    QString m_ApplicationFolder;
    QString m_OutputFolder;

    void ProcessFile(QString & filePath);

public:
    explicit QmlFileProcessor(QObject *parent = nullptr);

    void ProcessFolder(const QString & applicationFolder, const QString & outputFolder);

signals:
    void startProcessed(const QString & fileName, const QString & filePath);

public slots:
};

#endif // QMLFILEPROCESSOR_H
