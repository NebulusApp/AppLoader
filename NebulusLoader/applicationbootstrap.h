#ifndef APPLICATIONBOOTSTRAP_H
#define APPLICATIONBOOTSTRAP_H

#include "applicationslibrary.h"

class ApplicationBootstrap
{
private:
    ApplicationsLibrary* m_ApplicationsLibrary;

public:
    ApplicationBootstrap();
    ~ApplicationBootstrap();

    bool checkIfNeedInstallApplication() noexcept;
    QString applicationPath() noexcept;
};

#endif // APPLICATIONBOOTSTRAP_H
