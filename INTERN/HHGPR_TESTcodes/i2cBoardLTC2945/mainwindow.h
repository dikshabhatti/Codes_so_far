#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "/usr/include/linux/i2c.h"
#include "/usr/include/linux/i2c-dev.h"
#include <QIODevice>
#include <QDebug>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <fcntl.h>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int i2c;
    int ioc;
    unsigned char buf[3],buf1[2],buf2[2],buf3[2];
    QString fileName;

private:
    Ui::MainWindow *ui;
    void oldMethod();
    void newMethod();
};

#endif // MAINWINDOW_H
