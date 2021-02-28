#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "secondwindow.h"
#include "loginscreen.h"

using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    SecondWindow   *m_SecondWindow;
    LoginScreen    *m_LoginScreen;
    const QString   m_WelcomeMessage;
    QString         m_UsableString;

};
#endif // MAINWINDOW_H
