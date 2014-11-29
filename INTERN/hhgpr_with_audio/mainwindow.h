#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "/usr/include/linux/i2c.h"
#include "/usr/include/linux/i2c-dev.h"
#include <QIODevice>
#include <QDebug>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>

namespace Ui {
    class Window2;class Window1;
}

void alarm_wakeup(int i);
void alarm_wakeup_2 (int i);
void exit_func (int i);
void alarm_wakeup_fpga (int i);
void exit_func_fpga(int i);
char *get_timestamp();

class Window1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window1(QWidget *parent = 0);
    ~Window1();
      // public slots:
     //void hide();
private:
    Ui::Window1 *ui;

signals:
    void showOtherWindow();
    //void showgui();
    //void memorymapping();
    //void memorymapping2();
    void NEW();
    void mmcmount();
    void serial123();
    void serialread();
    void system_1();
    //void alarmtime();
    //void alarmtime_2();
    //void fpga();
    void usbmount();
    void volt();
public slots:
    void serial_read();
    void serial_123();
    void NEWF();
    void mmc_mount();
    //void memorymap();
    //void memorymap_2();
    void command_line();
    void system1();
    //void timer();
    //void timer_2();
    //void fpga_32();
    void usb_mount();

};

class Window2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Window2(QWidget *parent = 0);
    ~Window2();


    unsigned char buf[2];
    QString fileName;

private:
    Ui::Window2 *ui;

};

#endif // MAINWINDOW_H
