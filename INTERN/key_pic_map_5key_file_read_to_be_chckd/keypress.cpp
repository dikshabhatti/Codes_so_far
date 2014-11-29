#include "keypress.h"
#include"ui_keypress.h"

//#include <QApplication>
//#include <QKeyEvent>
#include <QtGui>
#include <fstream>
#include <iostream>
#include<QString>
using namespace std;

KeyPress::KeyPress(QWidget *parent) :
    QWidget(parent)
{
    l = new QLabel;

           mainLayout = new QHBoxLayout;
           mainLayout->addWidget(l);
           setLayout(mainLayout);

}

void KeyPress::keyPressEvent(QKeyEvent *event)
{

  if(event->key() == Qt::Key_A)
    { delete l;
        l =new QLabel("<img src='LRDE-logo.png' />");
        QHBoxLayout* left= new QHBoxLayout();
        mainLayout->addLayout(left);
        left->setAlignment(Qt::AlignLeft);
        left->addWidget(l);
    }

  if(event->key() == Qt::Key_B)
    {delete l;
            l =new QLabel("<img src='bitmapperlogo.png' />");
            QHBoxLayout* left= new QHBoxLayout();
            mainLayout->addLayout(left);
            left->setAlignment(Qt::AlignLeft);
            left->addWidget(l);
    }

  if(event->key() == Qt::Key_C)
    {delete l;
            l =new QLabel("<img src='images-jpeg.png' />");
            QHBoxLayout* left= new QHBoxLayout();
            mainLayout->addLayout(left);
            left->setAlignment(Qt::AlignLeft);
            left->addWidget(l);
     }

  if(event->key() == Qt::Key_F)
     {
            cout<<"ENTER THE FILENAME TO READ FROM : \n";
            string s ;
            cin >> s;
            ifstream the_file;
            the_file.open(s.c_str());
                  if ( !the_file.is_open() )
                  cout<<"Could not open file\n";
                else { char x;
                       while ( the_file.get ( x ) )
                      cout<< x;

                     }
     }

  if(event->key() == Qt::Key_D)
    {delete l;
            l =new QLabel("<img src='index-jpeg.png' />");
            QHBoxLayout* left= new QHBoxLayout();
            mainLayout->addLayout(left);
            left->setAlignment(Qt::AlignLeft);
            left->addWidget(l);
     }
  if(event->key() == Qt::Key_E)
    {delete l;
            l =new QLabel("key pressed");
            QHBoxLayout* left= new QHBoxLayout();
            mainLayout->addLayout(left);
            left->setAlignment(Qt::AlignLeft);
            left->addWidget(l);
     }

}


