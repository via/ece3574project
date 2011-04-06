#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>

namespace Ui {
    class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0);
    ~SettingsDialog();
private slots:
    void BlueChanged(QString const&);
    void GreenChanged(QString const&);
    void RedChanged(QString const&);

private:
    Ui::SettingsDialog *ui;
};

#endif // SETTINGSDIALOG_H
