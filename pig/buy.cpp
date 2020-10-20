#include "buy.h"
#include<QPushButton>
#include<QTextEdit>
#include<QLabel>
#include<QDebug>
#include<string.h>
#include<QString>
#include<QPainter>

buy::buy(QWidget *parent) : QWidget(parent)
{
        resize(700,700);
        b.setParent(this);
        b.setText("OK");
        b.move(300,500);
        QTextEdit *p1=new QTextEdit(this);
        QTextEdit *p2=new QTextEdit(this);
        QTextEdit *p3=new QTextEdit(this);
        p1->move(400,200);
        p2->move(400,300);
        p3->move(400,400);
        p1->resize(100,50);
        p2->resize(100,50);
        p3->resize(100,50);

        QLabel *t1=new QLabel(this);
        QLabel *t2=new QLabel(this);
        QLabel *t3=new QLabel(this);
        t1->setText("购买黑猪头数:");
        t2->setText("购买小花猪头数:");
        t3->setText("购买大花白猪头数:");
        t1->move(200,200);
        t2->move(200,300);
        t3->move(200,400);
        t1->resize(100,50);
        t2->resize(100,50);
        t3->resize(100,50);
        connect(&b,&QPushButton::clicked,
                [=]()
        {
        int black1=0;
        int litt1=0;
        int white1=0;
        QString litt0;
        QString white0;
        QString black0;
        black0=p1->toPlainText();
        litt0=p2->toPlainText();
        white0=p3->toPlainText();
        QByteArray litt=litt0.toUtf8();
        QByteArray white=white0.toUtf8();
        QByteArray black=black0.toUtf8();
        if(black0.length()!=0)
        for(int i=0;i<black0.length();i++)
        {
            black1=black1*10+int(black.at(i))-48;
        }
        if(litt0.length())
        for(int i=0;i<litt0.length();i++)
        {
            litt1=litt1*10+int(litt.at(i))-48;
        }
        if(white0.length())
        for(int i=0;i<white0.length();i++)
        {
            white1=white1*10+white.at(i)-48;
        }
        p1->clear();
        p2->clear();
        p3->clear();
        this->hide();
        emit mysignal(black1,litt1,white1);
        });

}
void buy::paintEvent(QPaintEvent *Event)
{
    QPainter p(this);
    p.drawPixmap(0,0,width(),height(),QPixmap("../source/timgs.gif"));
}
