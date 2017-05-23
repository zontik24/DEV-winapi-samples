#include <QDir>
#include <QFileInfoList>
#include <QFileInfo>
#include <QStringList>
#include <QDebug>
#include <QStorageInfo>
#include <QString>
#include <windows.h>


//new comment for test commit

class DriveSystem
{
public:
    static void getLocalDrivers()
    {
       QStringList drivesInfoList;
       QStringList alphabet;
       alphabet << "a"<<"b"<<"c"<<"d"<<"e"<<"f"<<"g"<<"h"<<"i"<<"j"<<"k"<<"l"<<"m"<<"n"<<"o"<<"p"<<"q"<<"r"<<"s"<<"t"<<"u"<<"v"<<"w"<<"x"<<"y"<<"z";
       QFileInfoList drives = QDir::drives();

       foreach(const QFileInfo &drive, drives)
       {
            drivesInfoList.append(drive.absoluteFilePath());
       }

       for(int i=0; i<drivesInfoList.size(); i++)
       {
           for(int j=0; j<alphabet.size(); j++)
           {
                if(alphabet[j].toUpper() == (QString)drivesInfoList[i][0])
                {
                    qDebug() << drivesInfoList[i][0];
                }
           }
       }
    }

    static double getDiskFreeSpace(QString diskLetter)
    {
       QStorageInfo storage = (QStorageInfo)(diskLetter.toUpper()+":\\");
       return storage.bytesAvailable();
    }

};

