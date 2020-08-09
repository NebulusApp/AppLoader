#include <QStandardPaths>
#include <QDir>
#include "applicationslibrary.h"

ApplicationsLibrary::ApplicationsLibrary(QObject *parent) : QObject(parent), m_ApplicationIdentifier(""), m_ApplicationPath("")
{

}

void ApplicationsLibrary::setApplicationIdentifier(const QString &applicationIdentifier)
{
    if (!m_ApplicationIdentifier.isEmpty()) return; //Set application identifier twice or more forbidden

    m_ApplicationIdentifier = applicationIdentifier;
    auto appLocation = QStandardPaths::writableLocation(QStandardPaths::AppLocalDataLocation) + "/" + applicationIdentifier;
    auto directory = QDir(appLocation);
    if (directory.exists()) {
        m_ApplicationPath = appLocation + "/";
        emit applicationPathChanged();
    }
}
