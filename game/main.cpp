#include "thewidget.h"
#include <QApplication>
#include<QTextStream>
enum colour{black=1,tabby,spotted};
struct pig{
    colour colur;
    double weight;
    int time=0;
};
struct sty{
    int number=0;
    int blacknum=0;
    int tabbynum=0;
    int spottednum=0;
    pig pigs[10];
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextStream qin(stdin);
    QTextStream qout(stdout);
    sty stys[100];
    int alternum=0;
    int add;
    qin>>add;

    theWidget w;
    w.show();

    return a.exec();
}
