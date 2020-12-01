#include "applicationbootstrap.h"
#include <QCoreApplication>

ApplicationBootstrap::ApplicationBootstrap() : m_ApplicationsLibrary(new ApplicationsLibrary())
{ 
    auto arguments = QCoreApplication::arguments();
    if (arguments.count() == 1) throw std::invalid_argument("Application identifier not specified as second parameter!");

    auto applicationIdentifier = arguments[1];
    m_ApplicationsLibrary->setApplicationIdentifier(applicationIdentifier);
}

ApplicationBootstrap::~ApplicationBootstrap()
{
    delete m_ApplicationsLibrary;
}

bool ApplicationBootstrap::checkIfNeedInstallApplication() noexcept
{
    return m_ApplicationsLibrary->applicationInLibrary();
}

QString ApplicationBootstrap::applicationPath() noexcept
{
    return m_ApplicationsLibrary->applicationPath();
}
