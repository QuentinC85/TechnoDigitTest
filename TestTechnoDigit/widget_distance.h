#ifndef WIDGET_DISTANCE_H
#define WIDGET_DISTANCE_H

#include <QLabel>
#include <iostream>
#include <QEvent>
#include <QKeyEvent>

class Widget_Distance : public QLabel
{
    Q_OBJECT

public:
    Widget_Distance(QWidget *parent = nullptr);

    bool m_isReadOnly = false;
    QString msg;

signals:
    void WriteEvent();

protected:
    bool event(QEvent *myEvent);
    void keyPressEvent(QKeyEvent *k);

};

#endif // WIDGET_DISTANCE_H
