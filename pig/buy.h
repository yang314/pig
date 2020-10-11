#ifndef BUY_H
#define BUY_H

#include <QWidget>
#include<QPushButton>



class buy : public QWidget
{
    Q_OBJECT
public:
    explicit buy(QWidget *parent = nullptr);

signals:
    void mysignal(int, int, int );

private:
    QPushButton b;

public slots:
};

#endif // BUY_H
