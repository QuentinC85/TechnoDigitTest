#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Button_Exit,SIGNAL(clicked()),this,SLOT(on_quitButton_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_quitButton_clicked()
{
    qApp->exit();
}


