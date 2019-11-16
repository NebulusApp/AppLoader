#include <QtCore>
#include "qmlfileprocessor.h"

QmlFileProcessor::QmlFileProcessor(QObject *parent) : QObject(parent),
    m_ApplicationFolder("")
{

}

void QmlFileProcessor::ProcessFile(QString &filePath)
{
    QFile nebulusFile(filePath);
    if (!nebulusFile.open(QIODevice::ReadOnly | QIODevice::Text)) return;

    QString fileName = nebulusFile.fileName().replace(".neb", ".qml");

    emit startProcessed(fileName, m_OutputFolder);

    QFile qmlFile(m_ApplicationFolder + fileName);
    if (!qmlFile.open(QIODevice::WriteOnly | QIODevice::Text)) return;

    QTextStream in(&nebulusFile);
    QTextStream out(&qmlFile);
    while (!in.atEnd()) {
        QString line = in.readLine();

        //remove custom imports (for security reasons)
        if (line.startsWith("import ", Qt::CaseInsensitive)) continue;

        if (line.startsWith("nebulus ", Qt::CaseInsensitive)) {
            out << "import QtQuick 2.12\n";
            out << "import Nebulus 1.0\n";
            continue;
        }

        if (line.startsWith("includes ", Qt::CaseInsensitive)) {
            auto includes = line.replace("includes ", "").split(",");

            foreach (QString includeModule, includes) {
                QString moduleName = includeModule.trimmed().toLower();
                if (moduleName == "layouts") {
                    out << "import QtQuick.Layouts 1.12\n";
                } else if (moduleName == "controls") {
                    out << "import QtQuick.Controls 2.12\n";
                } else if (moduleName == "dialogs") {
                    out << "import QtQuick.Dialogs 1.2\n";
                } else if (moduleName == "particles") {
                    out << "import QtQuick.Particles 2.12\n";
                } else if (moduleName == "localStorage") {
                    out << "import QtQuick.LocalStorage 2.12\n";
                } else if (moduleName == "window") {
                    out << "import QtQuick.Window 2.12\n";
                }

            }
            continue;
        }

        out << line << "\n";
    }

    nebulusFile.close();
    qmlFile.close();
}

void QmlFileProcessor::ProcessFolder(const QString &applicationFolder, const QString &outputFolder)
{
    m_ApplicationFolder = applicationFolder;
    m_OutputFolder = outputFolder;

    QDir directory(m_ApplicationFolder);
    QStringList nebulusFiles = directory.entryList(QStringList() << "*.*",QDir::Files);
    foreach(QString filename, nebulusFiles) {
        if (filename.contains(".neb")) {
            ProcessFile(filename);
        } else {
            //TODO: Copy file
        }
    }
}
