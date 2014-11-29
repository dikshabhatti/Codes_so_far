#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int fd = open("/dev/ttymxc0", O_RDWR | O_NOCTTY);
        if (fd == -1)
        {
            /* Could not open the port. */
            perror("open_port: Unable to open /dev/ttyS0 - ");
        }

        char buffer[32];
        int n = read(fd, buffer, sizeof(buffer));
        if (n < 0)
            fputs("read failed!\n", stderr);
        printf("Data read is %d", n);

}

MainWindow::~MainWindow()
{
    delete ui;
}
