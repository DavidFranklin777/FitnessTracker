#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <unistd.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_SecondWindow(new SecondWindow())
    , m_LoginScreen (new LoginScreen())
    , m_WelcomeMessage("Welcome to fit tracker")
    , m_UsableString("...")
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

    hide();
    //m_SecondWindow->show();
    m_LoginScreen->show();



   // m_SecondWindow.setModal(true);
   // m_SecondWindow.exec();
   //ui->label
}
