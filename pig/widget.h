#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QDialog>
#include<buy.h>
#include<thewidget.h>

namespace Ui {
class Widget;
}

enum colour{empty,black,tabby,spotted};
struct pig{
    colour colur=empty;
    double weight=0;
    int time=0;
};
struct sty{
    int number=0;
    int blacknum=0;//黑猪
    int tabbynum=0;//小花猪
    int spottednum=0;//大花白猪
    pig pigs[10];
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void sold();
public slots:
    void deal();
    void thebuy(int,int,int);
private:
    Ui::Widget *ui;
    int timerid;
    thewidget s;
    buy c;
public:
    int whitemin=0;
    int blackmin=0;
    int whitesave=0;
    int blacksave=0;
    sty stys[100];
    double blacksale=0;
    double tabbysale=0;
    double spottedsale=0;
    double sale=0;
    int time;
protected:
    void timerEvent(QTimerEvent *event);
     void paintEvent(QPaintEvent *Event);
};

#endif // WIDGET_H
