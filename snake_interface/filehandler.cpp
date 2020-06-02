#include "filehandler.h"
#include "QTextStream"
#include <cstdlib>
#include "QFile"
#include "vector"

FileHandler::FileHandler()
{
    filename = "Data.txt";
}

void FileHandler::saveToFile(int userScore, QString userNick)
{
    //kontener
    QVector<int> scores;
    QVector<QString> nicks;
    int index = 0;
    //odczyt
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite))
    {
        //odczytaj
        QTextStream in(&file);
        while (!in.atEnd() && index<5) {
            QString nick = in.readLine();
            QString score = in.readLine();
            scores.push_back(score.toInt());
            nicks.push_back(nick);
            index++;
        }

        //dopisz
        scores.push_back(userScore);
        nicks.push_back(userNick);
        //segreguj
        for(int i=0;i<scores.size();i++){
            for(int j=1;j<scores.size()-i;j++){ //pętla wewnętrzna
                if(scores[j-1]<scores[j]){
                    //zamiana miejscami
                    std::swap(scores[j-1], scores[j]);
                    std::swap(nicks[j-1], nicks[j]);
                }
            }
        }
        file.close();

        //wpisz
        file.open(QFile::WriteOnly|QFile::Truncate);
        QTextStream stream(&file);

        QVector<int>::iterator scoresIterator;
        QVector<QString>::iterator nicksIterator = nicks.begin();
        for (scoresIterator = scores.begin(); scoresIterator != scores.end(); ++scoresIterator){
            stream << *nicksIterator;
            stream << '\n';
            stream << *scoresIterator;
            stream << '\n';
            nicksIterator++;
        }
    }
    file.close();

}

QString FileHandler::getNicksFromFile()
{
    int indeks = 0;
    QString result;
    QFile file(filename);
    QString init = "Najlepsze wyniki: \n";
    if (file.open(QIODevice::ReadWrite))
    {
        QTextStream in(&file);
        while (!in.atEnd() && indeks<5) {
            QString nickLine = in.readLine();
            QString wynikLine = in.readLine();
            result += " " + QString::number(indeks +1) + ". User:   " + nickLine  + ", score:   " + wynikLine
                                + QString::fromStdString(" \n")+ QString::fromStdString(" \n");
            indeks++;
        }
    }
    return result;
}
