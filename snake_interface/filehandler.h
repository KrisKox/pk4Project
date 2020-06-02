#ifndef FILEHANDLER_H
#define FILEHANDLER_H
#include <QString>
#include "QCoreApplication"


class FileHandler
{
public:
    FileHandler();
    void saveToFile(int score, QString nick);
    QString getNicksFromFile();
    QString filename;
    // C://Users//Vobis//Desktop//Studia sem. 4//PK4//Qt//snake_interface//
};

#endif // FILEHANDLER_H
