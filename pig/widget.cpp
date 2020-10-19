#include "widget.h"
#include "ui_widget.h"
#include<QDialog>
#include<QAction>
#include<QMessageBox>
#include<QPushButton>
#include<string.h>
#include<QString>
#include<QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    s.show();
    ui->setupUi(this);
    ui->timer->setText(QString("<center><h1>养殖第%1天</h1></center>").arg(0));
    connect(&s,SIGNAL(mysinals()),this,SLOT(deal()));
    connect(&c,SIGNAL(mysignal(int,int,int)),this,SLOT(thebuy(int,int,int)));
    connect(ui->stys,&QPushButton::released,
            [=]()
    {
        QString styss=ui->lineEdit->text();
        if(styss.length()!=0)
        {
        QByteArray stysss=styss.toUtf8();
        int st=int(stysss.at(0))-48;
        if(styss.length()!=1)
        st=st*10+int(stysss.at(1))-48;
        ui->textEdit->append(QString("<h1>第%1天时：</h1>").arg(time));
        ui->output->append(QString("<h1>该猪圈黑猪数量：%1</h1>").arg(stys[st].blacknum));
        ui->output->append(QString("<h1>该猪圈小花猪数量：%1</h1>").arg(stys[st].tabbynum));
        ui->output->append(QString("<h1>该猪圈大白花猪数量：%1</h1>").arg(stys[st].spottednum));
        }
        else
        ui->textEdit->append(QString("请输入所要查询的猪圈"));
    });//查询猪圈
    connect(ui->pig,&QPushButton::released,
            [=]()
    {
        QString styss=ui->lineEdit->text();
        QString pigss=ui->lineEdit_2->text();
        if(styss.length()!=0&&pigss.length()!=0)
        {
        QByteArray stysss=styss.toUtf8();
        int st=int(stysss.at(0))-48;
        if(styss.length()!=1)
        st=st*10+int(stysss.at(1))-48;
        QByteArray pigsss=pigss.toUtf8();
        int pi=int(pigsss.at(0))-48;
        ui->textEdit->append(QString("<h1>第%1天时：</h1>").arg(time));
        ui->textEdit->append(QString("<h1>该猪种类：%1</h1>").arg(stys[st].pigs[pi].colur));
        ui->textEdit->append(QString("<h1>该猪重量：%1</h1>").arg(stys[st].pigs[pi].weight));
        ui->textEdit->append(QString("<h1>该猪饲养时间：%1</h1>").arg(stys[st].pigs[pi].time));
        }
        else
        {
            if(styss.length()==0)
            ui->textEdit->append(QString("请输入所要查询的猪圈"));
            if(pigss.length()==0)
            ui->textEdit->append(QString("请输入所要查询的猪"));
        }
    });//查询猪圈的某头猪
    connect(ui->black,&QPushButton::clicked,
            [=]()
    {
        ui->textEdit->clear();
        int blackhave=0;
        int timeh[13]={0};
        int weighth[12]={0};
        for(int i=50;i<100;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(stys[i].pigs[j].time!=0)
                {
                    if(stys[i].pigs[j].time<360)
                    timeh[stys[i].pigs[j].time/30]++;
                    else
                    timeh[12]++;

                }
                if(stys[i].pigs[j].weight!=0)
                {
                    if(stys[i].pigs[j].weight<75)
                    weighth[int(stys[i].pigs[j].weight/5)-4]++;
                    else
                    weighth[11]++;
                }
            }
            blackhave+=stys[i].blacknum;
        }
        ui->textEdit->append(QString("<h1>第%1天时：</h1>").arg(time));
        ui->textEdit->append(QString("<h1>黑猪头数：%1</h1>").arg(blackhave));
        for(int i=0;i<12;i++)
            if(timeh[i]!=0)
            ui->textEdit->append(QString("<h1>饲养时间在%1-%2天的有：%3</h1>").arg(i*30).arg(30*(i+1)).arg(timeh[i]));
        if(timeh[12]!=0)
        ui->textEdit->append(QString("<h1>饲养时间在一年以上的有：%1</h1>").arg(timeh[12]));
        for(int i=0;i<11;i++)
            {
            if(weighth[i]!=0)
            ui->textEdit->append(QString("<h1>体重在%1-%2Kg的有：%3</h1>").arg(20+5*i).arg(25+5*i).arg(weighth[i]));
            }
        if(weighth[11]!=0)
        ui->textEdit->append(QString("<h1>体重大于75Kg有：%1</h1>").arg(weighth[11]));
    });//查询黑猪
    connect(ui->tabby,&QPushButton::clicked,
            [=]()
    {
        ui->textEdit->clear();
        int tabbyhave=0;
        int timeh[13]={0};
        int weighth[12]={0};
        for(int i=0;i<50;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(stys[i].pigs[j].time!=0&&stys[i].pigs[j].colur==tabby)
                {
                    if(stys[i].pigs[j].time<360)
                    timeh[stys[i].pigs[j].time/30]++;
                    else
                    timeh[12]++;

                }
                if(stys[i].pigs[j].weight!=0&&stys[i].pigs[j].colur==tabby)
                {
                    if(stys[i].pigs[j].weight<75)
                    weighth[int(stys[i].pigs[j].weight/5)-4]++;
                    else
                    weighth[11]++;
                }
            }
            tabbyhave+=stys[i].tabbynum;
        }
        ui->textEdit->append(QString("<h1>第%1天时：</h1>").arg(time));
        ui->textEdit->append(QString("<h1>小花猪头数：%1</h1>").arg(tabbyhave));
        for(int i=0;i<12;i++)
            if(timeh[i]!=0)
            ui->textEdit->append(QString("<h1>饲养时间在%1-%2天的有：%3</h1>").arg(i*30).arg(30*(i+1)).arg(timeh[i]));
        if(timeh[12]!=0)
        ui->textEdit->append(QString("<h1>饲养时间在一年以上的有：%1</h1>").arg(timeh[12]));
        for(int i=0;i<11;i++)
            if(weighth[i]!=0)
            ui->textEdit->append(QString("<h1>体重在%1-%2Kg的有：%3</h1>").arg(20+5*i).arg(25+5*i).arg(weighth[i]));
        if(weighth[11]!=0)
        ui->textEdit->append(QString("<h1>体重大于75Kg有：%1</h1>").arg(weighth[11]));
    });//查询小花猪
    connect(ui->spotted,&QPushButton::clicked,
            [=]()
    {
        ui->textEdit->clear();
        int spottedhave=0;
        int timeh[13]={0};
        int weighth[12]={0};
        for(int i=0;i<50;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(stys[i].pigs[j].time!=0&&stys[i].pigs[j].colur==spotted)
                {
                    if(stys[i].pigs[j].time<360)
                    timeh[stys[i].pigs[j].time/30]++;
                    else
                    timeh[12]++;

                }
                if(stys[i].pigs[j].weight!=0&&stys[i].pigs[j].colur==spotted)
                {
                    if(stys[i].pigs[j].weight<75)
                    weighth[int(stys[i].pigs[j].weight/5)-4]++;
                    else
                    weighth[11]++;
                }
            }
            spottedhave+=stys[i].spottednum;
        }
        ui->textEdit->append(QString("<h1>第%1天时：</h1>").arg(time));
        ui->textEdit->append(QString("<h1>大白花猪头数：%1</h1>").arg(spottedhave));
        for(int i=0;i<12;i++)
            if(timeh[i]!=0)
            ui->textEdit->append(QString("<h1>饲养时间在%1-%2天的有：%3</h1>").arg(i*30).arg(30*(i+1)).arg(timeh[i]));
        if(timeh[12]!=0)
        ui->textEdit->append(QString("<h1>饲养时间在一年以上的有：%1</h1>").arg(timeh[12]));
        for(int i=0;i<11;i++)
            if(weighth[i]!=0)
            ui->textEdit->append(QString("<h1>体重在%1-%2Kg的有：%3</h1>").arg(20+5*i).arg(25+5*i).arg(weighth[i]));
        if(weighth[11]!=0)
        ui->textEdit->append(QString("<h1>体重大于75Kg有：%1</h1>").arg(weighth[11]));
    });//查询大白花猪
}

Widget::~Widget()
{
    delete ui;
}
void Widget::timerEvent(QTimerEvent *event)
{
    static int sec=1;
    ui->timer->setText(QString("<center><h1>养殖第%1天</h1></center>").arg(sec));
    time=sec;
    for(int i=0;i<100;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(stys[i].pigs[j].weight!=0)//查看该位置是否养殖了猪
                {
                stys[i].pigs[j].time++;
                double k=(1.2)*rand()/(RAND_MAX);//猪的体重随天数随机增加0-1.2Kg
                stys[i].pigs[j].weight+=k;
            }
        }
    }//猪每天体重增加
    if(sec%90==0)//三个月时进行卖出并买入
    {
        blacksale=0;
        tabbysale=0;
        spottedsale=0;
        sale=0;
        for(int i=50;i<100;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(stys[i].pigs[j].time>365&&stys[i].pigs[j].weight>75)
                {
                    blacksale+=stys[i].pigs[j].weight;
                    stys[i].number--;
                    stys[i].blacknum--;
                    stys[i].pigs[j].colur=empty;
                    stys[i].pigs[j].time=0;
                    stys[i].pigs[j].weight=0;
                }
            }
        }//记录卖出黑猪，并从猪圈中清除卖出猪数量
        for(int i=0;i<50;i++)
        {
            for(int j=0;j<10;j++)
            {
                if(stys[i].pigs[j].time>360&&stys[i].pigs[j].weight>75)
                {
                    if(stys[i].pigs[j].colur==tabby)
                    {
                        tabbysale+=stys[i].pigs[j].weight;
                        stys[i].tabbynum--;
                    }
                    else {
                        spottedsale+=stys[i].pigs[j].weight;
                        stys[i].spottednum--;
                    }
                    stys[i].pigs[j].colur=empty;
                    stys[i].pigs[j].time=0;
                    stys[i].pigs[j].weight=0;
                    stys[i].number--;
                }
            }
        }//记录卖出小花猪和大白花猪
        sale=2*15*blacksale+2*7*tabbysale+2*6*spottedsale;
        if(sale)
        ui->output->append(QString("<h1>第%1月卖出:</h1>").arg(sec/30));
        if(blacksale)
        ui->output->append(QString("<h1>卖出黑猪重量：%1</h1>").arg(blacksale));
        if(tabbysale)
        ui->output->append(QString("<h1>卖出小花猪重量：%1</h1>").arg(tabbysale));
        if(spottedsale)
        ui->output->append(QString("<h1>卖出大白花猪重量：%1</h1>").arg(spottedsale));
        if(sale)
        ui->output->append(QString("<h1>卖出总价钱：%1</h1>").arg(sale));
        int ques=QMessageBox::question(this,"购买猪崽","是否自己购买猪崽");//每三个月进购一批猪
        ui->output->append(QString("<h1>第%1月买入:</h1>").arg(sec/30));
        this->killTimer(timerid);//决定购买数时，计时器停止
        switch(ques)//询问玩家是自主选择购猪头数还是随机生成
        {
        case QMessageBox::Yes:
             c.show();
             //进入自主购买猪的输入窗口
             break;
        case QMessageBox::No:
             thebuy((12)*rand()/(RAND_MAX),(12)*rand()/(RAND_MAX),(12)*rand()/(RAND_MAX));//随机购买
             break;
             }
    }
    sec++;
}
void Widget::deal()
{
    //由开始游戏窗口切过来时的初次处理
    s.hide();
    this->show();
    int ques=QMessageBox::question(this,"购买猪崽","是否自己购买猪崽");
    ui->output->append(QString("<h1>第一次买入</h1>"));
    switch(ques)
    {
    case QMessageBox::Yes:
        c.show();
        break;
    case QMessageBox::No:
        thebuy((12)*rand()/(RAND_MAX),(12)*rand()/(RAND_MAX),(12)*rand()/(RAND_MAX));
        break;
    }
}
void Widget::thebuy(int black1,int litt1,int white1)//购买函数
{
    blacksave=0;
    for(int j=0;j<black1;)
    {
        if(blacksave==0)
        {
            blackmin=stys[50].number;//令第50个猪圈猪的数量为最小值
            blacksave=1;//最小猪数量为1
            for(int t=51;t<100;t++)
            {
                if(stys[t].number==blackmin)
                    blacksave++;
                if(stys[t].number<blackmin)
                {
                    blackmin=stys[t].number;
                    blacksave=1;
                }
            }
        }//遍历后50个猪圈，寻找猪圈养殖猪数量的最小值，并统计数量为最小值的个数
        if(blackmin==10)//如果最小值为10，说明猪圈已满，不可再买，否则可以继续进购
        {
            if(j!=0)
            ui->output->append(QString("<h1>因黑猪猪圈数量已满，此次仅成功买入黑猪数量:%1</h1>").arg(j));
            else
            ui->output->append(QString("黑猪数量已满不可再加"));
            break;
        }
        else
        {for(int i=50;i<100&&j<black1;i++)
            {
              if(stys[i].number==blackmin)//寻找猪数量等于最小值的猪圈，存进猪
              {
                  for(int k=0;k<10;k++)
                  {
                      if(stys[i].pigs[k].weight==0)//寻找该猪圈未存猪的位置
                      {
                         stys[i].pigs[k].colur=black;
                         stys[i].number++;
                         stys[i].blacknum++;
                         blacksave--;
                         stys[i].pigs[k].weight=20+(30)*rand()/(RAND_MAX);//体重随机初始化
                         j++;
                         break;
                       }
                  }
              }
              if(j==black1)//判断已购买数等于准备购买数，等于则输出买入，并退出循环，不等，则继续购买
              ui->output->append(QString("<h1>买入黑猪数量：%1</h1>").arg(black1));
              else if(blacksave==0)
                  break;//如果最小值个数为0，则重新寻找最小值并统计个数
            }
        }
    }
    for(int j=0;j<litt1;)
    {
        if(whitesave==0)
        {
            whitemin=stys[0].number;//令第0个猪圈猪的数量为最小值
            whitesave=1;//最小猪数量为1
            for(int t=1;t<50;t++)
            {
                if(stys[t].number==whitemin)
                    whitesave++;
                if(stys[t].number<whitemin)
                {
                   whitemin=stys[t].number;
                   whitesave=1;
                }
            }//遍历后50个猪圈，寻找最小值，并统计数量为最小值的个数
        }
        if(whitemin==10)
        {
            if(j!=0)
            ui->output->append(QString("<h1>因猪圈数量已满，此次仅成功买入小花猪数量:%1</h1>").arg(j));
            else
            ui->output->append(QString("小花猪数量已满不可再加"));
            break;
        }
        else
        for(int i=0;i<50&&j<litt1;i++)
        {
              if(stys[i].number==whitemin)//寻找猪数量等于最小值的猪圈
              {
                  for(int k=0;k<10;k++)
                  {
                      if(stys[i].pigs[k].weight==0)//寻找该猪圈未存猪的位置
                      {
                         stys[i].pigs[k].colur=tabby;
                         stys[i].number++;
                         stys[i].tabbynum++;
                         whitesave--;
                         stys[i].pigs[k].weight=20+(30)*rand()/(RAND_MAX);
                         j++;
                         break;
                       }
                  }
              }
              if(j==litt1)
              ui->output->append(QString("<h1>买入小花猪数量：%1</h1>").arg(litt1));
              else if(whitesave==0)
              break;//如果最小值个数为0，则重新寻找最小值并统计个数
         }
    }
    whitesave=0;//最小值赋0
    for(int j=0;j<white1;)
    {
        if(whitesave==0)
        {
            whitemin=stys[0].number;//令第0个猪圈猪的数量为最小值
            whitesave=1;//最小猪数量为1
            for(int t=1;t<50;t++)
            {
                if(stys[t].number==whitemin)
                    whitesave++;
                if(stys[t].number<whitemin)
                {
                   whitemin=stys[t].number;
                   whitesave=1;
                }
            }//遍历后50个猪圈，寻找最小值，并统计数量为最小值的个数
        }
        if(whitemin==10)
        {
            if(j!=0)
            ui->output->append(QString("<h1>因猪圈数量已满，此次仅成功买入大白花猪数量:%1</h1>").arg(j));
            else
            ui->output->append(QString("大白花猪数量已满不可再加"));
            break;
        }
        else
        for(int i=0;i<50&&j<white1;i++)
        {
              if(stys[i].number==whitemin)//寻找猪数量等于最小值的猪圈
              {
                  for(int k=0;k<10;k++)
                  {
                      if(stys[i].pigs[k].weight==0)//寻找该猪圈未存猪的位置
                      {
                         stys[i].pigs[k].colur=spotted;
                         stys[i].number++;
                         stys[i].spottednum++;
                         whitesave--;
                         stys[i].pigs[k].weight=20+(30)*rand()/(RAND_MAX);
                         j++;
                         break;
                       }
                  }
              }
              if(j==white1)
              ui->output->append(QString("<h1>买入大白花猪数量：%1</h1>").arg(white1));
              else if(whitesave==0)
              break;//如果最小值个数为0，则重新寻找最小值并统计个数
         }
    }
    whitesave=0;//最小值赋0
    timerid=this->startTimer(100);
}
void Widget::paintEvent(QPaintEvent *Event)
{
    QPainter p(this);
    p.drawPixmap(0,0,width(),height(),QPixmap("../source/u=2102183311,3313982260&fm=26&gp=0.jpg"));
}
