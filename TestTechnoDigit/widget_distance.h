#ifndef WIDGET_DISTANCE_H
#define WIDGET_DISTANCE_H

#include <iostream>
#include <QLabel>
#include <QtCore>
#include <QEvent>
#include <QKeyEvent>

class Widget_Distance : public QLabel
{
    Q_OBJECT

public:
    Widget_Distance(QWidget *parent = nullptr);
    void SetIndex(int index){m_index = index;};
    void write_msg(QString msg);

    bool m_isReadOnly = false;
    QString msg;

    enum class unit
    {
        m,
        mm,
        km,
        ft,
        in
    };
    Q_ENUM(unit);

private:
    int m_index = 0;

signals:
    void WriteEvent();

protected:
    bool event(QEvent *myEvent);
    void keyPressEvent(QKeyEvent *k);

};

#endif // WIDGET_DISTANCE_H
