#ifndef APPLICATIONSLIBRARY_H
#define APPLICATIONSLIBRARY_H

#include <QObject>

class ApplicationsLibrary : public QObject
{
    Q_OBJECT

private:
    QString m_ApplicationIdentifier;

public:
    explicit ApplicationsLibrary(QObject *parent = nullptr);

    void setApplicationIdentifier(const QString& applicationIdentifier);

    QString getApplicationPath();

signals:

};

#endif // APPLICATIONSLIBRARY_H
