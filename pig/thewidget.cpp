#include "thewidget.h"
#include<QPushButton>
#include<QMessageBox>
thewidget::thewidget(QWidget *parent) : QWidget(parent)
{
    b1.setParent(this);
    b2.setParent(this);
    b1.setText("开始游戏");
    b2.setText("退出");
    resize(700,700);
    b1.move(200,500);
    b2.move(400,500);
    connect(&b2,&QPushButton::clicked,this,&thewidget::close);
    connect(&b1,&QPushButton::clicked,
    [=]()
    {
      emit mysinals();

    });
}
