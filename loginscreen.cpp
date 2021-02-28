#include "loginscreen.h"
#include "ui_loginscreen.h"
#include "secondwindow.h"
#include <QPixmap>

LoginScreen::LoginScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginScreen)
{
    ui->setupUi(this);
    QPixmap pix("D:/Softwares/Practice/QtGui/fitnesstrackerlogo");
    ui->lable_logo->setPixmap(pix.scaled(100,100,Qt::KeepAspectRatio));
}

LoginScreen::~LoginScreen()
{
    delete ui;
}


void LoginScreen::on_pushButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

//    if((("David" == username) || ("Rahul" == username))
//            &&
//            ("root" == password))
//    {
//        SecondWindow *secondWindow = new SecondWindow();
//        hide();
//        secondWindow->show();
//    }

//    else
//    {
//        QString errorMessage = "Username or password incorrect. Please try again";
//        ui->label_errorMessage->setText(errorMessage);
//    }

    SecondWindow *secondWindow = new SecondWindow();
    hide();
    secondWindow->fetchUsername(username);
    secondWindow->show();
}
