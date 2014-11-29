#include "mainwindow.h"
 #include <QApplication>
#include <QLabel>
   int main(int argc, char **argv)
    {
        QApplication app(argc, argv);
        Window1 w1;
        Window2 w2;
                //slots correspond to the functions that will be called when corresponding radiobuttons are clicked
        QObject::connect(&w1, SIGNAL(showOtherWindow()), &w1, SLOT(command_line()));
        QObject::connect(&w1, SIGNAL(mmcmount()), &w1, SLOT(mmc_mount()));
        QObject::connect(&w1, SIGNAL(system_1()), &w1, SLOT(system1()));
        QObject::connect(&w1, SIGNAL(serialread()), &w1, SLOT(serial_read()));
        QObject::connect(&w1, SIGNAL(NEW()), &w1, SLOT(NEWF()));
        QObject::connect(&w1, SIGNAL(serial123()), &w1, SLOT(serial_123()));
        QObject::connect(&w1, SIGNAL(usbmount()), &w1, SLOT(usb_mount()));
        QObject::connect(&w1, SIGNAL(volt()), &w2, SLOT(show()));

        w1.show();  // only show one of them to start the mainwindow of gui
        return app.exec();
    }
