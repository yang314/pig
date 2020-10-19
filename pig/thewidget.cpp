#include "thewidget.h"
#include<QPushButton>
#include<QMessageBox>
#include<QPainter>
#include<QSizePolicy>
thewidget::thewidget(QWidget *parent) : QWidget(parent)
{
    b1.setParent(this);
    b1.setFixedSize(250,50);
    b1.setFlat(true);
    resize(700,700);
    b1.move(225,520);
    connect(&b1,&QPushButton::clicked,
    [=]()
    {
      emit mysinals();
    });
}
void thewidget::paintEvent(QPaintEvent *Event)
{
    QPainter p(this);
    p.drawPixmap(0,0,width(),height(),QPixmap("../source/timgDV1F3K3Y.jpg"));
}
