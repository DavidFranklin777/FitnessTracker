#ifndef DISPLAYINFORMATION_H
#define DISPLAYINFORMATION_H

#include <QDialog>

namespace Ui {
class DisplayInformation;
}

class DisplayInformation : public QDialog
{
    Q_OBJECT

public:
    explicit DisplayInformation(QWidget *parent = nullptr);
    ~DisplayInformation();

private:
    Ui::DisplayInformation *ui;
};

#endif // DISPLAYINFORMATION_H
