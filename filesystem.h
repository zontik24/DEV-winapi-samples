#include <QDir>
#include <QFile>
#include <QStringList>
#include <QDebug>
#include <QString>
#include <windows.h>


class FileSystem
{
public:

    QStringList findFiles(QString directoryPath, QString pattern)
    {
        QStringList filter(pattern);
        QDir directory(directoryPath);
        QStringList list = directory.entryList(filter);
        return list;

    }

    QString findFirstFile(QString directoryPath, QString pattern)
    {
        return this->findFiles(directoryPath, pattern).first();
    }

    static bool createDirectory(QString path)
    {
       LPCWSTR convertedPath = (const wchar_t*) path.utf16();
       CreateDirectory(convertedPath, NULL);
    }

    static bool removeDirectory(QString path)
    {
        QDir dir(path);
        if(dir.exists()) {
            dir.removeRecursively();
            return true;
        }
        return false;
    }

    static bool moveFile(QString pathFrom, QString pathTo)
    {
        LPCWSTR pathFromConverted= (const wchar_t*) pathFrom.utf16();
        LPCWSTR pathToConverted = (const wchar_t*) pathTo.utf16();
        MoveFile(pathFromConverted, pathToConverted);
    }

    static bool deleteFile(QString pathToFile)
    {
        QFile(pathToFile).remove();
    }
};
