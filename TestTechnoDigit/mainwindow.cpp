#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_test = new test(ui);
    connect(ui->Button_Exit,SIGNAL(clicked()),this,SLOT(on_quitButton_clicked()));
    connect(ui->Button_Test,SIGNAL(clicked()),m_test,SLOT(button_test_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_quitButton_clicked()
{
    qApp->exit();
}


