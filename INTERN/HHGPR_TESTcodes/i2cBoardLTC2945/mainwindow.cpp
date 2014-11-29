#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //buf[0]=0x0;
    //buf[1]=0x0;
//    fileName = "/dev/i2c-2";

    oldMethod();
//    newMethod();


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::oldMethod()
{

    .

    qDebug()<<"Accessing i2c-2";
    i2c = open("/dev/i2c-1", O_RDWR);
    if(i2c<0)
    {
        qDebug("error in opening i2c-1");
        exit;
    }
    else
    {
        qDebug()<<"i2c-1"<<i2c;
        //i2c
//        for(unsigned char i=0x0CE;i<0x0CF;i++)
        {
            unsigned char i=0x16;
            ioc = ioctl (i2c, I2C_SLAVE_FORCE, i);
            if(ioc<0)
            {
                qDebug("Failed to acquire the bus access");
            }
            else
            {
                buf[0]=0x160f17;//accessing the reg
         .     buf3[0]=0x00;
                if ((i2c,buf,3)<0)
                {
                    qDebug("Failed to write");
                }
          .   if(read(i2c, buf3, 1)<0)
                {
                    qDebug("Failed to read");
                }
                qDebug()<<buf3;
    .        }
        }
    }
}

void MainWindow::newMethod()
{
    unsigned char addr = 0x16;        // The Power Mon IC Slave Address
//    if ((i2c = open("/dev/i2c-2",O_RDWR)) < 0)
    if ((i2c = open("/dev/i2c-1",O_RDWR)) < 0)
    {
        qDebug()<<"Failed to open the bus.";
        return;
    }

    if (ioctl(i2c,I2C_SLAVE,addr) < 0)
    {
        qDebug()<<"Failed to acquire bus access and/or talk to slave.\n";
        return;
    }


//    unsigned char addr = 0x68;
    unsigned char reg = 0x0;
    unsigned char inbuf[2], outbuf;

    struct i2c_rdwr_ioctl_data packets;
    struct i2c_msg messages[2];

    /*
    * In order to read a register, we first do a "dummy write" by writing
    * 0 bytes to the register we want to read from.  This is similar to
    * the packet in set_i2c_register0, except it's 1 byte rather than 2.
    */
    for(reg=0;reg<0x32;reg++)
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
            qDebug()<<ioctl(i2c, I2C_RDWR, &packets);
//            return;
        }
      //  qDebug() << inbuf[0];
    }
}
