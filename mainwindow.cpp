// checksum 0xa193 version 0x30001
/*
  This file was generated by the Mobile Qt Application wizard of Qt Creator.
  MainWindow is a convenience class containing mobile device specific code
  such as screen orientation handling.
  It is recommended not to modify this file, since newer versions of Qt Creator
  may offer an updated version of it.
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingsdialog.h"

#include <QtCore>
#include <QtGui>
#include <QAccelerometer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    R = "00";
    G = "00";
    B = "00";
    QAction *settingsAction = new QAction("Settings", this);
        connect(settingsAction, SIGNAL(triggered()), this, SLOT(settingsWindowSlot()));
    QMenu *menu = new QMenu("Fremantle", this);
    menu->addAction(settingsAction);
    menuBar()->addMenu(menu);
    commitSettings("X", "Y", "Z");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOrientation(ScreenOrientation orientation)
{
#if defined(Q_OS_SYMBIAN)
    // If the version of Qt on the device is < 4.7.2, that attribute won't work
    if (orientation != ScreenOrientationAuto) {
        const QStringList v = QString::fromAscii(qVersion()).split(QLatin1Char('.'));
        if (v.count() == 3 && (v.at(0).toInt() << 16 | v.at(1).toInt() << 8 | v.at(2).toInt()) < 0x040702) {
            qWarning("Screen orientation locking only supported with Qt 4.7.2 and above");
            return;
        }
    }
#endif // Q_OS_SYMBIAN

    Qt::WidgetAttribute attribute;
    switch (orientation) {
#if QT_VERSION < 0x040702
    // Qt < 4.7.2 does not yet have the Qt::WA_*Orientation attributes
    case ScreenOrientationLockPortrait:
        attribute = static_cast<Qt::WidgetAttribute>(128);
        break;
    case ScreenOrientationLockLandscape:
        attribute = static_cast<Qt::WidgetAttribute>(129);
        break;
    default:
    case ScreenOrientationAuto:
        attribute = static_cast<Qt::WidgetAttribute>(130);
        break;
#else // QT_VERSION < 0x040702
    case ScreenOrientationLockPortrait:
        attribute = Qt::WA_LockPortraitOrientation;
        break;
    case ScreenOrientationLockLandscape:
        attribute = Qt::WA_LockLandscapeOrientation;
        break;
    default:
    case ScreenOrientationAuto:
        attribute = Qt::WA_AutoOrientation;
        break;
#endif // QT_VERSION < 0x040702
    };
    setAttribute(attribute, true);
}

void MainWindow::showExpanded()
{
#ifdef Q_OS_SYMBIAN
    showFullScreen();
#elif defined(Q_WS_MAEMO_5) || defined(Q_WS_MAEMO_6)
    showMaximized();
#else
    show();
#endif
}

void MainWindow::on_verticalSlider_2_valueChanged(int value)
{
   if(value < 16) {
        R = "0" + R.setNum(value, 16);
        }
        else {
        R = R.setNum(value,16);
        }

        QString valueString = "<body bgcolor=\"#" + R + G + B + "\">";
        ui->textEdit->setHtml(valueString);
}

void MainWindow::on_verticalSlider_valueChanged(int value)
{
if(value < 16) {
        B = "0" + B.setNum(value, 16);
        }
        else {
        B = B.setNum(value,16);
        }

        QString valueString = "<body bgcolor=\"#" + R + G + B + "\">";
        ui->textEdit->setHtml(valueString);

}

void MainWindow::on_verticalSlider_3_valueChanged(int value)
{
if(value < 16) {
        G = "0" + G.setNum(value, 16);
        }
        else {
        G = G.setNum(value,16);
        }

        QString valueString = "<body bgcolor=\"#" + R + G + B + "\">";
        ui->textEdit->setHtml(valueString);
}

void MainWindow::settingsWindowSlot()
{

        SettingsDialog *sd = new SettingsDialog(this);
        sd->show();

}

void MainWindow::commitSettings(const QString &Raxis,
                    const QString &Gaxis,
                    const QString &Baxis)
{

        if (Raxis == "X")
                this->Raxis = X;
        else if (Raxis == "Y")
                this->Raxis = Y;
        else if (Raxis == "Z")
                this->Raxis = Z;

        if (Gaxis == "X")
                this->Gaxis = X;
        else if (Gaxis == "Y")
                this->Gaxis = Y;
        else if (Gaxis == "Z")
                this->Gaxis = Z;

        if (Baxis == "X")
                this->Baxis = X;
        else if (Baxis == "Y")
                this->Baxis = Y;
        else if (Baxis == "Z")
                this->Baxis = Z;
}
