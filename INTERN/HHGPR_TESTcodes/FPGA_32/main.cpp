#include "mainwindow.h"
#include <QApplication>
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>

int    j;
int   words = 10;
int   devmem;
off_t PageOffset, PageAddress;

unsigned long *hw_addr = (unsigned long *) 0x08000000;
unsigned long  read_data;


#define INTERVAL 5

int howmany = 0;

void alarm_wakeup (int i)
{
   struct itimerval tout_val;

  // int    j;
   PageOffset = (off_t) hw_addr % getpagesize();
   PageAddress = (off_t) (hw_addr - PageOffset);

   hw_addr = (unsigned long *) mmap(0, 4, PROT_READ|PROT_WRITE, MAP_SHARED, devmem, PageAddress);

   signal(SIGALRM,alarm_wakeup);

   howmany += 1;

   j+=4;
   //printf("\n%d sec up partner, Wakeup!!!\n",howmany);

   printf("Writing to hardware model\n");

   *(hw_addr+j) = 0xabcd0000+j;

   read_data = *(hw_addr+j);

   printf("Read from hardware %x\n",read_data);


   tout_val.it_interval.tv_sec = 0;
   tout_val.it_interval.tv_usec = 0;
   tout_val.it_value.tv_sec = 1; /* 10 seconds timer */
   tout_val.it_value.tv_usec = 0;

   setitimer(ITIMER_REAL, &tout_val,0);

}

void exit_func (int i)
{
    signal(SIGINT,exit_func);
    printf("\nBye Bye!!!\n");
    exit(0);
}


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    //////////////////////***********////////////////


    devmem = open("/dev/mem", O_RDWR | O_SYNC);

    ////////////////////**************//////////////

    struct itimerval tout_val;

      tout_val.it_interval.tv_sec = 0;
      tout_val.it_interval.tv_usec = 0;
      tout_val.it_value.tv_sec = 1; /* 10 seconds timer */
      tout_val.it_value.tv_usec = 0;
      setitimer(ITIMER_REAL, &tout_val,0);

      signal(SIGALRM,alarm_wakeup); /* set the Alarm signal capture */
      signal(SIGINT,exit_func);

      while (1)
      {
        //printf("!");
      }


    return a.exec();
}
