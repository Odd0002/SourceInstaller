#include "mainwindow.h"
#include "ui_mainwindow.h"

//will clean up includes later

#include <QApplication>
#include <QtGui>
#include <QFileDialog>
#include <QFileSystemModel>
#include <QLineEdit>

QString sourceFilePath;
QString tempDirPath;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    /*QMessageBox msgBox;
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setText("Click File > Automatic Mode to start automatic compiling.");
    msgBox.exec();
    */
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionChoose_file_triggered()
{
    getFile();
}

bool getFile()
{
    sourceFilePath = "";
    sourceFilePath = QFileDialog::getOpenFileName(0,"Choose a tar.gz or tar.bz2 file to compile...",QDir::homePath(),"Compressed tarball files (*.tar.gz *.tar.bz2)");
    if (sourceFilePath == "")
       return false;
    else
        return true;
}

void buildStart()
{
    if (!getFile())
    {
        return;
    }

    QMessageBox msgBox;
    msgBox.setText("Would you like to automatically build the project?");
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Cancel);
    switch (msgBox.exec()) {
       case QMessageBox::Yes:
        autoMode();
           break;
       case QMessageBox::No:
           break;
       case QMessageBox::Cancel:
           break;
       default:
           break;
     }
}

void autoMode()
    {
    QMessageBox msgBox;
    msgBox.setText("UNIMPLIMENTED");
    msgBox.exec();
    }

void MainWindow::on_actionAutomatic_mode_triggered()
{
    buildStart();
}

void MainWindow::on_autoCompileButton_clicked()
{
    //connect(dirTextAuto, SIGNAL(null), dirTextAuto, SLOT(setText(int )));
}

void MainWindow::on_browseButtonAuto_clicked()
{
    if (!getFile())
        return;
    //dirTextAuto->setText(sourceFilePath);

}
