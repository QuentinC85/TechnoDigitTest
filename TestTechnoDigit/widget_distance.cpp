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
            this->setText("");
            msg = "";
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
        msg.append(k->text());
        this->setText(msg);
    }
}
