#ifndef TRACKINGMENU_H
#define TRACKINGMENU_H

#include <QDialog>

namespace Ui {
class TrackingMenu;
}

class TrackingMenu : public QDialog
{
    Q_OBJECT

public:
    explicit TrackingMenu(QWidget *parent = nullptr);
    ~TrackingMenu();

private:
    Ui::TrackingMenu *ui;
};

#endif // TRACKINGMENU_H
