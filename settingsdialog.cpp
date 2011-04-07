#include "mainwindow.h"
#include "settingsdialog.h"
#include "ui_settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    QStringList axis;
    axis.append("X");
    axis.append("Y");
    axis.append("Z");
    ui->Raxisbox->addItems(axis);
    ui->Gaxisbox->addItems(axis);
    ui->Baxisbox->addItems(axis);
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}


void SettingsDialog::accepted()
{
        MainWindow *mw = (MainWindow *)this->parent();

}
