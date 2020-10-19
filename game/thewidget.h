#ifndef THEWIDGET_H
#define THEWIDGET_H

#include <QWidget>

class theWidget : public QWidget
{
    Q_OBJECT

public:
    theWidget(QWidget *parent = 0);
    ~theWidget();
};

#endif // THEWIDGET_H
