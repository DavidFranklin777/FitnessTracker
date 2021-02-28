#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    // restricting the lineEdit_weight to accept only integers between 0-500
    ui->lineEdit_weight->setValidator(new QIntValidator(0,500,this));

}

SecondWindow::~SecondWindow()
{
    delete ui;
}

void SecondWindow::on_pushButton_startTracking_clicked()
{
    bool ok;                   // variable for indicating the status of string to double conversion
    QString userWeight;
    double userWeight_double;
    QDate   date;

    userWeight = ui->lineEdit_weight->text();
    date       = ui->dateEdit->date();

    userWeight_double = userWeight.toDouble(&ok);

    //if data is valid, send it to the data controller
    if (true == ok)
    {
        DataController *dataControl = new DataController();
        dataControl->saveData(m_Username, date, userWeight_double);
    }

    else
    {
        std::cout << "Invalid data. Please check" << std::endl;
    }

}

void SecondWindow::on_dateEdit_userDateChanged(const QDate &date)
{

}

void SecondWindow::fetchUsername(QString &username)
{
    m_Username = username;
}
