#ifndef APPLICATIONSLIBRARY_H
#define APPLICATIONSLIBRARY_H

#include <QObject>
#include <qqml.h>

class ApplicationsLibrary : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString applicationPath READ applicationPath NOTIFY applicationPathChanged)
private:
    QString m_ApplicationIdentifier;
    QString m_ApplicationPath;

public:
    explicit ApplicationsLibrary(QObject *parent = nullptr);

    void setApplicationIdentifier(const QString& applicationIdentifier);

    QString applicationPath() const { return m_ApplicationPath; }

signals:
    void applicationPathChanged();

};

#endif // APPLICATIONSLIBRARY_H
