#ifndef THEWIDGET_H
#define THEWIDGET_H

#include <QWidget>
#include<QPushButton>
#include<QDialog>

class thewidget : public QWidget
{
    Q_OBJECT
public:
    explicit thewidget(QWidget *parent = nullptr);
private:
    QPushButton b1;
public:

protected:
    void paintEvent(QPaintEvent *Event);

signals:
    void mysinals();

public slots:
};

#endif // THEWIDGET_H
