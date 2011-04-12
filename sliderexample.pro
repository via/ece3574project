# Add files and directories to ship with the application 
# by adapting the examples below.
# file1.source = myfile
# dir1.source = mydir
DEPLOYMENTFOLDERS = # file1 dir1

symbian:TARGET.UID3 = 0xE7DF0F77

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment
# the following lines and add the respective components to the 
# MOBILITY variable. 

SOURCES += main.cpp mainwindow.cpp settingsdialog.cpp MapDataPoint.cpp \
DataPointList.cpp
HEADERS += mainwindow.h settingsdialog.h MapDataPoint.h DataPointList.h
FORMS += mainwindow.ui settingsdialog.ui
CONFIG += mobility
MOBILITY += sensors
INCLUDEPATH += /usr/include/QtSensors/

# Please do not modify the following two lines. Required for deployment.
include(deployment.pri)
qtcAddDeployment()
