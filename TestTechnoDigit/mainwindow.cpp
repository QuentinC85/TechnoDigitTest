#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_test = new test(ui);
    this->SetupUnitMenu();
    last_index_unit = 0;
    connect(ui->MenuUnit,static_cast<void(QComboBox::*)(int)>(&QComboBox::currentIndexChanged),[=](int index)
    {
        switch(index)//si il y a changement d'unité convertir la valeur déjà rentré
        {
            case(0)://m
            {

            }
            case(1)://mm
            {

            }
            case(2)://km
            {

            }
            case(3)://ft
            {

            }
            case(4)://in
            {

            }
        }
        last_index_unit = index;
    });

    connect(ui->Button_Exit,SIGNAL(clicked()),this,SLOT(on_quitButton_clicked()));
    connect(ui->Button_Test,SIGNAL(clicked()),m_test,SLOT(button_test_clicked()));
    connect(ui->Distance_Widget, &Widget_Distance::WriteEvent,[=](){
        this->ui->Affichage_Distance->setText("The length is " + this->ui->Distance_Widget->text() + " " + QString(QMetaEnum::fromType<unit>().key(last_index_unit)));
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
