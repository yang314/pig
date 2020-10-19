#include "thewidget.h"
#include<QPushButton>
#include<QMessageBox>
#include<QPainter>
thewidget::thewidget(QWidget *parent) : QWidget(parent)
{
    b1.setParent(this);
    b2.setParent(this);

    b2.setText("退出");
    resize(700,700);
    b1.move(300,426);
    b2.move(400,500);
    connect(&b2,&QPushButton::clicked,this,&thewidget::close);
    connect(&b1,&QPushButton::clicked,
    [=]()
    {
      emit mysinals();
    });
}
void thewidget::paintEvent(QPaintEvent *Event)
{
    QPainter p(this);
    p.drawPixmap(0,0,width(),height(),QPixmap("../source/begin.jpg"));
}
