#ifndef APPLICATIONSLIBRARY_H
#define APPLICATIONSLIBRARY_H

#include <QObject>
#include <qqml.h>

class ApplicationsLibrary : public QObject
{
    Q_OBJECT

private:
    QString m_ApplicationIdentifier;
    QString m_ApplicationPath;
    QString m_ApplicationHash;
    bool m_ApplicationInLibrary;

public:
    explicit ApplicationsLibrary(QObject *parent = nullptr);

    void setApplicationIdentifier(const QString& applicationIdentifier);

    QString applicationIdentifier() const { return m_ApplicationIdentifier; }
    QString applicationPath() const { return m_ApplicationPath; }
    QString applicationHash() const { return m_ApplicationHash; }
    bool applicationInLibrary() const { return m_ApplicationInLibrary; }
};

#endif // APPLICATIONSLIBRARY_H
