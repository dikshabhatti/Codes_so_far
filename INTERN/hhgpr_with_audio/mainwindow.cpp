#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/mount.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <fstream>
#include <iostream>
#include <sched.h>
#include <getopt.h>
#include "/usr/include/alsa/asoundlib.h"
#include <math.h>
#define MAP_SIZE 4096
#define MAP_MASK (MAP_SIZE-1)
#define INTERVAL 32000
using namespace std;

off_t target = 0x08000000;
int howmany=0;
int howmany_fpga = 0;
int    j_fpga;
int   devmem_fpga;
off_t PageOffset_fpga, PageAddress_fpga;
unsigned long *hw_addr_fpga = (unsigned long *) 0x08000000;
unsigned long  read_data_fpga;



void alarm_wakeup(int i)
{
signal(SIGALRM,alarm_wakeup);
   printf("%d sec up partner, Wakeup!!!\n",INTERVAL);
}

void alarm_wakeup_2 (int i)
{
   struct itimerval tout_val;

   signal(SIGALRM,alarm_wakeup_2);

   howmany += 32000;

   printf("\n%d sec up partner, Wakeup!!!\n",howmany);
   tout_val.it_interval.tv_sec = 0;
   tout_val.it_interval.tv_usec = 0;
   tout_val.it_value.tv_sec = 0; // 10 seconds timer
   tout_val.it_value.tv_usec = 32000;

   setitimer(ITIMER_REAL, &tout_val,0);

}

void exit_func (int i)
{
    signal(SIGINT,exit_func);
    printf("\nBye Bye!!!\n");
    exit(0);
}

char *get_timestamp()

{

  time_t now = time (NULL);

  return asctime (localtime (&now));

}



//////////////////


Window1::Window1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window1)
{
    ui->setupUi(this);

    connect(ui->button, SIGNAL(clicked()), SIGNAL(showOtherWindow()));
    connect(ui->button_1, SIGNAL(clicked()), SIGNAL(NEW()));
    connect(ui->button_3, SIGNAL(clicked()), SIGNAL(mmcmount()));
    connect(ui->button_5, SIGNAL(clicked()), SIGNAL(serial123()));
    connect(ui->button_6, SIGNAL(clicked()), SIGNAL(serialread()));
    connect(ui->button_7, SIGNAL(clicked()), SIGNAL(system_1()));
    connect(ui->button_10, SIGNAL(clicked()), SIGNAL(usbmount()));
    connect(ui->button_11, SIGNAL(clicked()), SIGNAL(volt()));

   }


//////////////
void Window1::NEWF()
{


void Window1::mmc_mount()
{ cout<<"give filename to which to append the timestamp\n";
    string filename ;
    cin >> filename;
    mount("/dev/mmcblk0p3", "/mnt/mmcblk0p3", "ext3", MS_MGC_VAL | MS_NOSUID, "");

          char* timestamp = get_timestamp ();

          // Open the file for writing. If it exists, append to it;

            // otherwise, create a new file.

          int fd = open (filename.c_str(), O_WRONLY | O_CREAT | O_APPEND, 0666);

          // Compute the length of the timestamp string.

          size_t length = strlen (timestamp);

          // Write the timestamp to the file.

          write (fd, timestamp, length);

          //All done.

          ::close (fd);



}



void Window1::serial_read()
{
    int fd = open("/dev/ttymxc0", O_RDWR | O_NOCTTY);
            if (fd == -1)
            {
                // Could not open the port.
                perror("open_port: Unable to open /dev/ttyS0 - ");
            }

            char buffer[32];
            int n = read(fd, buffer, sizeof(buffer));
            if (n < 0)
                fputs("read failed!\n", stderr);
            printf("Data read is %d", n);
}


void Window1::serial_123()
{
 int fd; // File descriptor for the port
  int n;

  fd = open("/dev/ttymxc0", O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd == -1)
  {
   //Could not open the port.
    perror("open_port: Unable to open /dev/ttyS0 - ");
  }
  else
    fcntl(fd, F_SETFL, 0);

  n = write(fd, "ATZ\r", 4);
  if (n < 0)
    fputs("write() of 4 bytes failed!\n", stderr);
}



void Window1::command_line()
{
cout<<"give filename\n";
string s ;
cin >> s;
//getline(cin,s);
 ifstream the_file;
the_file.open(s.c_str());
    // Always check to see if file opening succeeded
    if ( !the_file.is_open() )
      cout<<"Could not open file\n";
    else {
      char x;
      // the_file.get ( x ) returns false if the end of the file
      //  is reached or an error occurs
      while ( the_file.get ( x ) )
        cout<< x;
    }

}

void Window1::usb_mount()
{
cout<<"give filename to which to append the timestamp\n";
string filename ;
cin >> filename;
mount("/dev/sda1", "/mnt/transcend", "vfat", MS_MGC_VAL | MS_NOSUID, "");

      char* timestamp = get_timestamp ();

      // Open the file for writing. If it exists, append to it;

        // otherwise, create a new file.

      int fd = open (filename.c_str(), O_WRONLY | O_CREAT | O_APPEND, 0666);

      // Compute the length of the timestamp string.

      size_t length = strlen (timestamp);

      // Write the timestamp to the file.

      write (fd, timestamp, length);

      //All done.

      ::close (fd);




}

void Window1::system1()
{
   char command[50];
    char command_1[50];
   //strcpy( command, "ls -l" );
   strcpy(command, "gplay /mnt/transcend/audio_1.mp4" );
   system(command);

   int   i, j;
   int   words = 10;
   int   devmem;
   off_t PageOffset, PageAddress;

   unsigned long *hw_addr = (unsigned long *) 0x08000000;
   unsigned long  read_data;

   devmem = open("/dev/mem", O_RDWR | O_SYNC);
   PageOffset = (off_t) hw_addr % getpagesize();
   PageAddress = (off_t) (hw_addr - PageOffset);

   hw_addr = (unsigned long *) mmap(0, 4, PROT_READ|PROT_WRITE, MAP_SHARED, devmem, PageAddress);

   for (i = 0, j = 0; i < words; i++, j+=4)
   {
       printf("Writing to hardware model\n");

       *(hw_addr+j) = 0xabcd0000+j;

       read_data = *(hw_addr+j);

       printf("Read from hardware %x\n",read_data);

   }
}



//////////////////////////

Window1::~Window1()
{
    delete ui;
}

Window2::Window2(QWidget *parent) :    QMainWindow(parent),    ui(new Ui::Window2)
{if ((i2c = open("/dev/i2c-1",O_RDWR)) < 0)
    {
        qDebug()<<"Failed to open the bus.";
        return;
    }

    if (ioctl(i2c,I2C_SLAVE,addr) < 0)
    {
        qDebug()<<"Failed to acquire bus access and/or talk to slave.\n";
        return;
    }
    ui->setupUi(this);


}

Window2::~Window2()
{
    delete ui;
}


