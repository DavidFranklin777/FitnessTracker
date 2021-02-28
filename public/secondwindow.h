#ifndef SECONDWINDOW_H
#define SECONDWINDOW_H

#include <QDialog>
#include <loginscreen.h>
#include "DataController.h"

namespace Ui {
class SecondWindow;
}

class SecondWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SecondWindow(QWidget *parent = nullptr);
    ~SecondWindow();
    void fetchUsername(QString &username);

private slots:
    void on_pushButton_startTracking_clicked();

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_pushButton_getData_clicked();

private:
    Ui::SecondWindow *ui;
    QString m_Username;
};

#endif // SECONDWINDOW_H
