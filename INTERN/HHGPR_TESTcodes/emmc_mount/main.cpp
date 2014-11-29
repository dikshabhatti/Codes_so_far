#include "mainwindow.h"
#include <QApplication>
#include "mainwindow.h"
#include <QApplication>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <sys/mount.h>
#include <stdio.h>
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <fcntl.h>



#include <sys/stat.h>

#include <sys/types.h>

#include <time.h>

char *get_timestamp();



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    /* The file to which to append the timestamp.  */

      char* filename = argv[1];

      /* Get the current timestamp.  */
       mount("/dev/mmcblk0p3", "/mnt/mmcblk0p3", "ext3", MS_MGC_VAL | MS_NOSUID, "");

      char* timestamp = get_timestamp ();

      /* Open the file for writing. If it exists, append to it;

         otherwise, create a new file.  */

      int fd = open (filename, O_WRONLY | O_CREAT | O_APPEND, 0666);

      /* Compute the length of the timestamp string.  */

      size_t length = strlen (timestamp);

      /* Write the timestamp to the file.  */

      write (fd, timestamp, length);

      /* All done.  */

      close (fd);

      return 0;

    return a.exec();
}

char *get_timestamp()

{

  time_t now = time (NULL);

  return asctime (localtime (&now));

}
