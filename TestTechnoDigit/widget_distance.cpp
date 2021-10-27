#include "widget_distance.h"

Widget_Distance::Widget_Distance(QWidget *parent)
    : QLabel(parent)
{

}

bool Widget_Distance::event(QEvent *myEvent)
{
    switch(myEvent->type())
    {
        case(QEvent::MouseButtonRelease):
        {
            msg = "";
            this->setText("");
            m_isReadOnly = true;
            grabKeyboard();
            break;
        }
        case(QEvent::Leave):
        {
            m_isReadOnly = false;
            releaseKeyboard();
            emit(WriteEvent());
            break;
        }
        default:
            break;
    }
    return QWidget::event(myEvent);
}

void Widget_Distance::keyPressEvent(QKeyEvent *k)
{
    if((k->key() == Qt::Key_Return) ||(k->key() == Qt::Key_Escape))
    {
        m_isReadOnly = false;
        releaseKeyboard();
        emit(WriteEvent());
    }
    else
    {
        bool ok;
        k->text().toInt(&ok);
        if(ok)
        {
            msg.append(k->text());
            write_msg(msg);
        }
        if(k->key() == Qt::Key_Period)
        {
            msg.append(k->text());
            write_msg(msg);
        }
    }
}

void Widget_Distance::write_msg(QString msg)
{
    this->msg = msg;
    this->setText(msg + " " + QString(QMetaEnum::fromType<unit>().key(m_index)));
}
