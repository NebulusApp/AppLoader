#include "applicationslibrary.h"

ApplicationsLibrary::ApplicationsLibrary(QObject *parent) : QObject(parent), m_ApplicationIdentifier("")
{

}

void ApplicationsLibrary::setApplicationIdentifier(const QString &applicationIdentifier)
{
    m_ApplicationIdentifier = applicationIdentifier;
}

QString ApplicationsLibrary::getApplicationPath()
{
    return "";
}
