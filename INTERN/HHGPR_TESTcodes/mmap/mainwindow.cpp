#include "mainwindow.h"
#include "ui_mainwindow.h"
///////////////////////////////////////////
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>

#define MAP_SIZE 4096
#define MAP_MASK (MAP_SIZE-1)
off_t target = 0x08000000;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);





    int fd1;
    char *map_base;

    if((fd1=open("/dev/mem",O_RDWR))==0) {
    perror("Error openning file /dev/mem");

    }

    map_base = (char *)mmap(0,MAP_SIZE,PROT_READ|PROT_WRITE,MAP_SHARED,fd1,target&~MAP_MASK);

    if(map_base == (void *)-1) {
    perror("Error mapping");

    }

    printf("Value at map_base before writing is %2X\n",map_base[0]);

    map_base[0] = 1; //***This should alter the value at this memory location***

    printf("Value at map_base after writing is %2X\n",map_base[0]);
    //***This should print 1 but it prints FF***



}

MainWindow::~MainWindow()
{
    delete ui;
}
