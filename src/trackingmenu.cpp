#include "trackingmenu.h"
#include "ui_trackingmenu.h"

TrackingMenu::TrackingMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrackingMenu)
{
    ui->setupUi(this);
}

TrackingMenu::~TrackingMenu()
{
    delete ui;
}
