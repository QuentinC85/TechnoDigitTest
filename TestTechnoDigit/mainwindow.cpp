#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_test = new test(ui);
    ui->Affichage_Distance->installEventFilter(this);
    this->SetupUnitMenu();
    setMouseTracking(false);
    last_index_unit = 0;
    connect(ui->MenuUnit,static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=](int index)
    {
        ui->Distance_Widget->SetIndex(index);
        Convert_menu_unit(index);
        last_index_unit = index;
        this->ui->Affichage_Distance->setText("The length is " + this->ui->Distance_Widget->text());
    });

    connect(ui->Button_Exit,SIGNAL(clicked()),this,SLOT(on_quitButton_clicked()));
    connect(ui->Button_Test,SIGNAL(clicked()),m_test,SLOT(button_test_clicked()));
    connect(ui->Distance_Widget, &Widget_Distance::WriteEvent,[=](){
        this->ui->Affichage_Distance->setText("The length is " + this->ui->Distance_Widget->text());
    });
    connect(ui->ResetButton,&QPushButton::clicked,[=](){
        ui->MenuUnit->setCurrentIndex(0);
        ui->Distance_Widget->setText("1 " + QString(QMetaEnum::fromType<unit>().key(0)));
        ui->Distance_Widget->msg = "1";
        this->ui->Affichage_Distance->setText("The length is " + this->ui->Distance_Widget->text());
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_quitButton_clicked()
{
    qApp->exit();
}


void MainWindow::SetupUnitMenu()
{
    QMetaEnum metaEnum = QMetaEnum::fromType<unit>();
    QStringList enumStrings;
    for(int i = 0; i < metaEnum.keyCount(); ++i)
    {
        enumStrings.append(metaEnum.key(i));
    }
    ui->MenuUnit->addItems(enumStrings);
}

bool MainWindow::eventFilter(QObject *sender, QEvent *event)
{
    if (sender == ui->Affichage_Distance)
    {
        if(event->type()== QEvent::MouseMove)
        {
            QMouseEvent* mouseevent = (QMouseEvent*)(event);
            double pos = mouseevent->windowPos().x();
            double result = ui->Distance_Widget->msg.toDouble()-50*pow(((last_pos_clicked - pos)/ui->centralwidget->width()),3);
            ui->Distance_Widget->write_msg(QString::number(result));
            emit(ui->Distance_Widget->WriteEvent());
        }
        if(event->type()==QEvent::MouseButtonPress)
        {
            QMouseEvent* mouseevent = (QMouseEvent*)(event);
            last_pos_clicked = mouseevent->windowPos().x();
        }
    }
    return QWidget::eventFilter(sender,event);
}





void MainWindow::Convert_menu_unit(int index)
{
    //refer to enum unit
    switch(index)
    {
    case(0):
    {
        switch(last_index_unit)
        {
        case(1):
        {
            ui->Distance_Widget->write_msg(QString::number((ui->Distance_Widget->msg.toDouble()*1000.0)));
            break;
        }
        case(2):
        {
            ui->Distance_Widget->write_msg(QString::number((ui->Distance_Widget->msg.toDouble()/1000.0)));
            break;
        }
        case(3):
        {
            ui->Distance_Widget->write_msg(QString::number((ui->Distance_Widget->msg.toDouble()/3.2808)));
            break;
        }
        case(4):
        {
            ui->Distance_Widget->write_msg(QString::number((ui->Distance_Widget->msg.toDouble()*0.0254)));
            break;
        }
        default:
            break;
        }
        break;
    }
    case(1):
    {
        switch(last_index_unit)
        {
        case(0):
        {
            ui->Distance_Widget->write_msg(QString::number((ui->Distance_Widget->msg.toDouble()/1000.0)));
            break;
        }
        case(2):
        {
            ui->Distance_Widget->write_msg(QString::number((ui->Distance_Widget->msg.toDouble()/1000000.0)));
            break;
        }
        case(3):
        {
            ui->Distance_Widget->write_msg(QString::number((ui->Distance_Widget->msg.toDouble()/(3.2808*1000.0))));
            break;
        }
        case(4):
        {
            ui->Distance_Widget->write_msg(QString::number(((ui->Distance_Widget->msg.toDouble()*0.0254)/1000.0)));
            break;
        }
        }
        break;
    }
    case(2):
    {
        switch(last_index_unit)
        {
        case(0):
        {
            ui->Distance_Widget->write_msg(QString::number((ui->Distance_Widget->msg.toDouble()*1000.0)));
            break;
        }
        case(1):
        {
            ui->Distance_Widget->write_msg(QString::number((ui->Distance_Widget->msg.toDouble()*1000000.0)));
            break;
        }
        case(3):
        {
            ui->Distance_Widget->write_msg(QString::number(((ui->Distance_Widget->msg.toDouble()/3.2808)*1000.0)));
            break;
        }
        case(4):
        {
            ui->Distance_Widget->write_msg(QString::number(((ui->Distance_Widget->msg.toDouble()*0.0254)*1000.0)));
            break;
        }
        }
        break;
    }
    case(3):
    {
        switch(last_index_unit)
        {
        case(0):
        {
            ui->Distance_Widget->write_msg(QString::number((ui->Distance_Widget->msg.toDouble()*3.2808)));
            break;
        }
        case(1):
        {
            ui->Distance_Widget->write_msg(QString::number(((ui->Distance_Widget->msg.toDouble()/3.2808)/1000)));
            break;
        }
        case(2):
        {
            ui->Distance_Widget->write_msg(QString::number(((ui->Distance_Widget->msg.toDouble()/3.2808)*1000)));
            break;
        }
        case(4):
        {
            ui->Distance_Widget->write_msg(QString::number((ui->Distance_Widget->msg.toDouble()/12)));
            break;
        }
        }
        break;
    }
    case(4):
    {
        switch(last_index_unit)
        {
        case(0):
        {
            ui->Distance_Widget->write_msg(QString::number((ui->Distance_Widget->msg.toDouble()/0.0254)));
            break;
        }
        case(1):
        {
            ui->Distance_Widget->write_msg(QString::number(((ui->Distance_Widget->msg.toDouble()/0.0254)/1000)));
            break;
        }
        case(2):
        {
            ui->Distance_Widget->write_msg(QString::number(((ui->Distance_Widget->msg.toDouble()/0.0254)*1000)));
            break;
        }
        case(3):
        {
            ui->Distance_Widget->write_msg(QString::number((ui->Distance_Widget->msg.toDouble()*12)));
            break;
        }
        }
        break;
    }
    }
}
