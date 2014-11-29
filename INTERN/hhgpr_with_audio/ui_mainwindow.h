/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu May 22 12:22:51 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QRadioButton>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QLabel>
#include <QTableWidget>
#include <string>
#include "/usr/include/linux/i2c.h"
#include "/usr/include/linux/i2c-dev.h"
#include <QIODevice>
#include <QDebug>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <QTranslator>

unsigned char addr = 0x8;
unsigned char reg ;
unsigned char inbuf[2], outbuf;

struct i2c_rdwr_ioctl_data packets;
struct i2c_msg messages[2];
int i2c;
int ioc;
float voltage;

QT_BEGIN_NAMESPACE



class Ui_MainWindow
{
public:
    //QMenuBar *menuBar;
    //QToolBar *mainToolBar;
    QWidget *centralWidget;
    //QStatusBar *statusBar;
    QRadioButton *button;
    QRadioButton *button_1;
   // QRadioButton *button_2;
    QRadioButton *button_4;
    QRadioButton *button_3;
    QRadioButton *button_5;
    QRadioButton *button_6;
    QRadioButton *button_7;
    QRadioButton *button_8;
    QRadioButton *button_9;
    QRadioButton *button_10;
    QRadioButton *button_11;
    QVBoxLayout  *left;
    QVBoxLayout  *right;
    QVBoxLayout  *centre;
    QHBoxLayout *bottomLayout;
    QHBoxLayout *topLayout;
    QVBoxLayout *mainLayout;
    QLabel *label1 ;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;

    //QRadioButton *button_1;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("HHGPR"));
        MainWindow->resize(600, 300);

        button = new QRadioButton(MainWindow);
        button->setText("COMMAND_LINE");
        button->resize(100,70);
        button_1 = new QRadioButton(MainWindow);
        button_1->setText("AUDIO");
        button_1->resize(100,70);
        button_3 = new QRadioButton(MainWindow);
        button_3->setText("MMC_MOUNT");
        button_3->resize(100,70);
        button_5 = new QRadioButton(MainWindow);
        button_5->setText("Serial_123");
        button_5->resize(100,70);
        button_6 = new QRadioButton(MainWindow);
        button_6->setText("Serial_Read");
        button_6->resize(100,70);
        button_7 = new QRadioButton(MainWindow);
        button_7->setText("System_CALL");
        button_7->resize(100,70);
        button_10 = new QRadioButton(MainWindow);
        button_10->setText("USB_Mount");
        button_10->resize(100,70);
        button_11 = new QRadioButton(MainWindow);
        button_11->setText("Voltage");
        button_11->resize(100,70);

        left = new QVBoxLayout();
        right = new QVBoxLayout();
        centre= new QVBoxLayout();

        bottomLayout = new QHBoxLayout();
        topLayout = new QHBoxLayout();
        mainLayout = new QVBoxLayout();

        QLabel* label1 = new QLabel("<img src='bitmapperlogo.png' />");
        QLabel* label3 = new QLabel(QObject::tr("HHGPR DEVELOPMENT BOARD"));
        QLabel* label2 = new QLabel("<img src='LRDE-logo.png' />");

        label3->setStyleSheet("QLabel {  color : black; font : Courier }");
        label3->setStyleSheet("font: 18pt;");
        label1->setAlignment(Qt::AlignLeft);
        label2->setAlignment(Qt::AlignRight);
        label3->setAlignment(Qt::AlignCenter);

        left->addWidget(button);
        left->addWidget(button_1);
        left->addWidget(button_5);
        left->addWidget(button_6);

        right->addWidget(button_7);
        right->addWidget(button_3);
        right->addWidget(button_11);
        right->addWidget(button_10);

        left->setAlignment(Qt::AlignLeft);
        centre->setAlignment(Qt::AlignCenter);
        right->setAlignment(Qt::AlignRight);

        bottomLayout->addLayout(left);
        bottomLayout->addLayout(centre);
        bottomLayout->addLayout(right);
        topLayout->addWidget(label1);
        topLayout->addWidget(label3);
        topLayout->addWidget(label2);
        mainLayout->addLayout(topLayout);
        mainLayout->addLayout(bottomLayout);

        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setLayout(mainLayout);
        centralWidget->setStyleSheet("background-color: white;");
        MainWindow->setCentralWidget(centralWidget);
         retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

     void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("HHGPR", "HHGPR", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};





class Ui_MainWindow_2
{
public:

    QTableWidget *tableWidget;

    void setupUi(QMainWindow *MainWindow)
    {int x,setpoint;
        tableWidget = new QTableWidget(26,2);
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("HHGPR"));
        MainWindow->resize(300, 300);

        int row=0;
        reg =0x1a;
        outbuf = reg;
        messages[0].addr  = addr;
        messages[0].flags = 0;
        messages[0].len   = sizeof(outbuf);
        messages[0].buf   = &outbuf;
        /* The data will get returned in this structure */
        messages[1].addr  = addr;
        messages[1].flags = I2C_M_RD/* | I2C_M_NOSTART*/;
        messages[1].len   = 2;
        messages[1].buf   = inbuf;
        /* Send the request to the kernel and get the result back */
        packets.msgs      = messages;
        packets.nmsgs     = 2;
        if(ioctl(i2c, I2C_RDWR, &packets) < 0)
        {
            qDebug()<<reg<<"Unable to send data";
//            return;
        }
        x= (int) inbuf[0];
        setpoint =x%8;
        if(setpoint==0){voltage = 2.5;}
        else {voltage = 2.7 + 0.1 * (setpoint-1);}
                QTableWidgetItem *newItem = new QTableWidgetItem(1);
                        newItem->setData(Qt::DisplayRole,voltage);

                        QTableWidgetItem *reg_addr = new QTableWidgetItem(1);
                        reg_addr->setData(Qt::DisplayRole,reg);
                        tableWidget->setItem(row, 0, reg_addr);
                        tableWidget->setItem(row, 1, newItem);
        row+=1;



        for(reg=0x20;reg<0x23;reg++)
        {
            outbuf = reg;
            messages[0].addr  = addr;
            messages[0].flags = 0;
            messages[0].len   = sizeof(outbuf);
            messages[0].buf   = &outbuf;
            /* The data will get returned in this structure */
            messages[1].addr  = addr;
            messages[1].flags = I2C_M_RD/* | I2C_M_NOSTART*/;
            messages[1].len   = 2;
            messages[1].buf   = inbuf;
            /* Send the request to the kernel and get the result back */
            packets.msgs      = messages;
            packets.nmsgs     = 2;
            if(ioctl(i2c, I2C_RDWR, &packets) < 0)
            {
                qDebug()<<reg<<"Unable to send data";
    //            return;
            }
        x= (int) inbuf[0];
        setpoint =x%64;
        voltage = 0.3 + 0.025 * setpoint;

            QTableWidgetItem *newItem = new QTableWidgetItem(1);
                            newItem->setData(Qt::DisplayRole,voltage);
                            QTableWidgetItem *reg_addr = new QTableWidgetItem(1);
                            reg_addr->setData(Qt::DisplayRole,reg);
                            tableWidget->setItem(row, 0, reg_addr);
                            tableWidget->setItem(row, 1, newItem);
            row+=1;
        }





        for(reg=0x2e;reg<0x31;reg++)
        {
            outbuf = reg;
            messages[0].addr  = addr;
            messages[0].flags = 0;
            messages[0].len   = sizeof(outbuf);
            messages[0].buf   = &outbuf;
            /* The data will get returned in this structure */
            messages[1].addr  = addr;
            messages[1].flags = I2C_M_RD/* | I2C_M_NOSTART*/;
            messages[1].len   = 2;
            messages[1].buf   = inbuf;
            /* Send the request to the kernel and get the result back */
            packets.msgs      = messages;
            packets.nmsgs     = 2;
            if(ioctl(i2c, I2C_RDWR, &packets) < 0)
            {
                qDebug()<<reg<<"Unable to send data";
    //            return;
            }
        x= (int) inbuf[0];
        setpoint =x%64;
        voltage = 0.3 + 0.025 * setpoint;

            QTableWidgetItem *newItem = new QTableWidgetItem(1);
                            newItem->setData(Qt::DisplayRole,voltage);
                            QTableWidgetItem *reg_addr = new QTableWidgetItem(1);
                            reg_addr->setData(Qt::DisplayRole,reg);
                            tableWidget->setItem(row, 0, reg_addr);
                            tableWidget->setItem(row, 1, newItem);
            row+=1;
        }





        for(reg=0x35;reg<0x38;reg++)
        {
            outbuf = reg;
            messages[0].addr  = addr;
            messages[0].flags = 0;
            messages[0].len   = sizeof(outbuf);
            messages[0].buf   = &outbuf;
            /* The data will get returned in this structure */
            messages[1].addr  = addr;
            messages[1].flags = I2C_M_RD/* | I2C_M_NOSTART*/;
            messages[1].len   = 2;
            messages[1].buf   = inbuf;
            /* Send the request to the kernel and get the result back */
            packets.msgs      = messages;
            packets.nmsgs     = 2;
            if(ioctl(i2c, I2C_RDWR, &packets) < 0)
            {
                qDebug()<<reg<<"Unable to send data";
    //            return;
            }
        x= (int) inbuf[0];
        setpoint =x%128;
        if(setpoint<64) {voltage = 0.4 + 0.025 * setpoint;}
        else {voltage = 0.8 + 0.5 * (setpoint-64);}

            if(voltage<=3.3)
            {
                QTableWidgetItem *reg_addr = new QTableWidgetItem(1);
                reg_addr->setData(Qt::DisplayRole,reg);
                tableWidget->setItem(row, 0, reg_addr);
                QTableWidgetItem *newItem = new QTableWidgetItem(1);
                newItem->setData(Qt::DisplayRole,voltage);
                tableWidget->setItem(row, 1, newItem);}

            else { QTableWidgetItem *newItem = new QTableWidgetItem("Reserved");
                QTableWidgetItem *reg_addr = new QTableWidgetItem(1);
                reg_addr->setData(Qt::DisplayRole,reg);
                tableWidget->setItem(row, 0, reg_addr);
                tableWidget->setItem(row, 1, newItem);}
            row++;
        }


        for(reg=0x3c;reg<0x3e;reg++)
        {
            outbuf = reg;
            messages[0].addr  = addr;
            messages[0].flags = 0;
            messages[0].len   = sizeof(outbuf);
            messages[0].buf   = &outbuf;
            /* The data will get returned in this structure */
            messages[1].addr  = addr;
            messages[1].flags = I2C_M_RD/* | I2C_M_NOSTART*/;
            messages[1].len   = 2;
            messages[1].buf   = inbuf;
            /* Send the request to the kernel and get the result back */
            packets.msgs      = messages;
            packets.nmsgs     = 2;
            if(ioctl(i2c, I2C_RDWR, &packets) < 0)
            {
                qDebug()<<reg<<"Unable to send data";
    //            return;
            }
        x= (int) inbuf[0];
        setpoint =x%128;
        if(setpoint<64) {voltage = 0.4 + 0.025 * setpoint;}
        else {voltage = 0.8 + 0.5 * (setpoint-64);}

            if(voltage<=3.3){
                QTableWidgetItem *newItem = new QTableWidgetItem(1);
                                newItem->setData(Qt::DisplayRole,voltage);
                                tableWidget->setItem(row, 1, newItem);
                                QTableWidgetItem *reg_addr = new QTableWidgetItem(1);
                                reg_addr->setData(Qt::DisplayRole,reg);
                                tableWidget->setItem(row, 0, reg_addr);}
            else {
                QTableWidgetItem *newItem = new QTableWidgetItem("Reserved");
                QTableWidgetItem *reg_addr = new QTableWidgetItem(1);
                reg_addr->setData(Qt::DisplayRole,reg);
                tableWidget->setItem(row, 0, reg_addr);
                tableWidget->setItem(row, 1, newItem);}
            row++;
        }


        for(reg=0x43;reg<0x46;reg++)
        {
            outbuf = reg;
            messages[0].addr  = addr;
            messages[0].flags = 0;
            messages[0].len   = sizeof(outbuf);
            messages[0].buf   = &outbuf;
            /* The data will get returned in this structure */
            messages[1].addr  = addr;
            messages[1].flags = I2C_M_RD/* | I2C_M_NOSTART*/;
            messages[1].len   = 2;
            messages[1].buf   = inbuf;
            /* Send the request to the kernel and get the result back */
            packets.msgs      = messages;
            packets.nmsgs     = 2;
            if(ioctl(i2c, I2C_RDWR, &packets) < 0)
            {
                qDebug()<<reg<<"Unable to send data";
    //            return;
            }
        x= (int) inbuf[0];
        setpoint =x%128;
        if(setpoint<64) {voltage = 0.4 + 0.025 * setpoint;}
        else {voltage = 0.8 + 0.5 * (setpoint-64);}

            if(voltage<=3.3){
                QTableWidgetItem *newItem = new QTableWidgetItem(1);
                                newItem->setData(Qt::DisplayRole,voltage);
                                tableWidget->setItem(row, 1, newItem);
                                QTableWidgetItem *reg_addr = new QTableWidgetItem(1);
                                reg_addr->setData(Qt::DisplayRole,reg);
                                tableWidget->setItem(row, 0, reg_addr);}
            else {
                QTableWidgetItem *newItem = new QTableWidgetItem("Reserved");
                QTableWidgetItem *reg_addr = new QTableWidgetItem(1);
                reg_addr->setData(Qt::DisplayRole,reg);
                tableWidget->setItem(row, 0, reg_addr);
                tableWidget->setItem(row, 1, newItem);}
            row++;
        }


        for(reg=0x4a;reg<0x4d;reg++)
        {
            outbuf = reg;
            messages[0].addr  = addr;
            messages[0].flags = 0;
            messages[0].len   = sizeof(outbuf);
            messages[0].buf   = &outbuf;
            /* The data will get returned in this structure */
            messages[1].addr  = addr;
            messages[1].flags = I2C_M_RD/* | I2C_M_NOSTART*/;
            messages[1].len   = 2;
            messages[1].buf   = inbuf;
            /* Send the request to the kernel and get the result back */
            packets.msgs      = messages;
            packets.nmsgs     = 2;
            if(ioctl(i2c, I2C_RDWR, &packets) < 0)
            {
                qDebug()<<reg<<"Unable to send data";
    //            return;
            }
        x= (int) inbuf[0];
        setpoint =x%128;
        if(setpoint<64) {voltage = 0.4 + 0.025 * setpoint;}
        else {voltage = 0.8 + 0.5 * (setpoint-64);}

            if(voltage<=3.3){
                QTableWidgetItem *newItem = new QTableWidgetItem(1);
                                newItem->setData(Qt::DisplayRole,voltage);
                                tableWidget->setItem(row, 1, newItem);
                                QTableWidgetItem *reg_addr = new QTableWidgetItem(1);
                                reg_addr->setData(Qt::DisplayRole,reg);
                                tableWidget->setItem(row, 0, reg_addr);}
            else {
                QTableWidgetItem *newItem = new QTableWidgetItem("Reserved");
                QTableWidgetItem *reg_addr = new QTableWidgetItem(1);
                reg_addr->setData(Qt::DisplayRole,reg);
                tableWidget->setItem(row, 0, reg_addr);
                tableWidget->setItem(row, 1, newItem);}
            row++;
        }


        reg = 0x66;
        outbuf = reg;
        messages[0].addr  = addr;
        messages[0].flags = 0;
        messages[0].len   = sizeof(outbuf);
        messages[0].buf   = &outbuf;
        /* The data will get returned in this structure */
        messages[1].addr  = addr;
        messages[1].flags = I2C_M_RD/* | I2C_M_NOSTART*/;
        messages[1].len   = 2;
        messages[1].buf   = inbuf;
        /* Send the request to the kernel and get the result back */
        packets.msgs      = messages;
        packets.nmsgs     = 2;
        if(ioctl(i2c, I2C_RDWR, &packets) < 0)
        {
            qDebug()<<reg<<"Unable to send data";
//            return;
        }
        x= (int) inbuf[0];
        setpoint =x%4;
        voltage = 5.0 + 0.05 * setpoint;

        QTableWidgetItem *newItem_1 = new QTableWidgetItem(1);
        newItem_1->setData(Qt::DisplayRole,voltage);
        tableWidget->setItem(row, 1, newItem_1);
        QTableWidgetItem *reg_addr_1 = new QTableWidgetItem(1);
        reg_addr->setData(Qt::DisplayRole,reg);
        tableWidget->setItem(row, 0, reg_addr_1);
        row++;

        reg = 0x6b;
        outbuf = reg;
        messages[0].addr  = addr;
        messages[0].flags = 0;
        messages[0].len   = sizeof(outbuf);
        messages[0].buf   = &outbuf;
        /* The data will get returned in this structure */
        messages[1].addr  = addr;
        messages[1].flags = I2C_M_RD/* | I2C_M_NOSTART*/;
        messages[1].len   = 2;
        messages[1].buf   = inbuf;
        /* Send the request to the kernel and get the result back */
        packets.msgs      = messages;
        packets.nmsgs     = 2;
        if(ioctl(i2c, I2C_RDWR, &packets) < 0)
        {
            qDebug()<<reg<<"Unable to send data";
//            return;
        }
        x= (int) inbuf[0];
        setpoint =x%8;
        if(setpoint <=3){voltage = 1.0 + 0.1 * setpoint;}
        else if(setpoint==4){voltage=1.5;}
        else if(setpoint==5){voltage=1.8;}
        else {voltage=3.0;}

        if(setpoint !=7){
            QTableWidgetItem *newItem_1 = new QTableWidgetItem(1);
            newItem_1->setData(Qt::DisplayRole,voltage);
            tableWidget->setItem(row, 1, newItem_1);
            QTableWidgetItem *reg_addr = new QTableWidgetItem(1);
            reg_addr->setData(Qt::DisplayRole,reg);
            tableWidget->setItem(row, 0, reg_addr);
            }
        else {
            QTableWidgetItem *newItem = new QTableWidgetItem("Reserved");
            QTableWidgetItem *reg_addr = new QTableWidgetItem(1);
            reg_addr->setData(Qt::DisplayRole,reg);
            tableWidget->setItem(row, 0, reg_addr);
            tableWidget->setItem(row, 1, newItem);}
        row++;


        for(reg=0x6c;reg<0x6e;reg++)
        {
            outbuf = reg;
            messages[0].addr  = addr;
            messages[0].flags = 0;
            messages[0].len   = sizeof(outbuf);
            messages[0].buf   = &outbuf;
            /* The data will get returned in this structure */
            messages[1].addr  = addr;
            messages[1].flags = I2C_M_RD/* | I2C_M_NOSTART*/;
            messages[1].len   = 2;
            messages[1].buf   = inbuf;
            /* Send the request to the kernel and get the result back */
            packets.msgs      = messages;
            packets.nmsgs     = 2;
            if(ioctl(i2c, I2C_RDWR, &packets) < 0)
            {
                qDebug()<<reg<<"Unable to send data";
    //            return;
            }
        x= (int) inbuf[0];
        setpoint =x%16;
        voltage = 0.8 + 0.05 * setpoint;

            QTableWidgetItem *newItem_1 = new QTableWidgetItem(1);
            newItem_1->setData(Qt::DisplayRole,voltage);
            tableWidget->setItem(row, 1, newItem_1);
            QTableWidgetItem *reg_addr = new QTableWidgetItem(1);
            reg_addr->setData(Qt::DisplayRole,reg);
            tableWidget->setItem(row, 0, reg_addr);
            row++;
        }



        for(reg=0x6e;reg<0x72;reg++)
        {
            outbuf = reg;
            messages[0].addr  = addr;
            messages[0].flags = 0;
            messages[0].len   = sizeof(outbuf);
            messages[0].buf   = &outbuf;
            /* The data will get returned in this structure */
            messages[1].addr  = addr;
            messages[1].flags = I2C_M_RD/* | I2C_M_NOSTART*/;
            messages[1].len   = 2;
            messages[1].buf   = inbuf;
            /* Send the request to the kernel and get the result back */
            packets.msgs      = messages;
            packets.nmsgs     = 2;
            if(ioctl(i2c, I2C_RDWR, &packets) < 0)
            {
                qDebug()<<reg<<"Unable to send data";
    //            return;
            }
        x= (int) inbuf[0];
        setpoint =x%16;
        voltage = 1.8 + 0.1 * setpoint;

            QTableWidgetItem *newItem_1 = new QTableWidgetItem(1);
            newItem_1->setData(Qt::DisplayRole,voltage);
            tableWidget->setItem(row, 1, newItem_1);
            QTableWidgetItem *reg_addr = new QTableWidgetItem(1);
            reg_addr->setData(Qt::DisplayRole,reg);
            tableWidget->setItem(row, 0, reg_addr);
            row++;
        }


    MainWindow->setCentralWidget(tableWidget);
        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

     void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("HHGPR", "HHGPR", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Window1: public Ui_MainWindow {};class Window2: public Ui_MainWindow_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
