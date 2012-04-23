#include "mainwindow.h"
#include "ui_mainwindow.h"

//will clean up includes later

#include <QApplication>
#include <QtGui>
#include <QFileDialog>
#include <QFileSystemModel>
#include <QLineEdit>

QString tempDirPath = QDir::homePath() + "/.sourceInstallerTemp/";


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

QString getFile()
{
    return (QFileDialog::getOpenFileName(0,"Choose a tar.gz or tar.bz2 file to compile...",QDir::homePath(),"Compressed tarball files (*.tar.gz *.tar.bz2)"));
}

void extractFile(QString sourceFile)
{
    if (sourceFile == ""  || (!(sourceFile.endsWith('2', Qt::CaseInsensitive)) && !(sourceFile.endsWith('z', Qt::CaseInsensitive))))
    {
        QMessageBox msgBox;
        msgBox.setText("No file set!");
        msgBox.exec();
        return;
    }
    QProcess::execute("mkdir "+ tempDirPath);
    if (sourceFile.endsWith('2', Qt::CaseInsensitive))
        QProcess::execute("tar -xJf "+ sourceFile + " -C " + tempDirPath);
    else
        QProcess::execute("tar -xzf "+ sourceFile + " -C " + tempDirPath);

    QMessageBox msgBox;
    msgBox.setText(tempDirPath);
    msgBox.exec();

    return;
}

void buildStart(QString buildCommand, QString envVariables, QString makeOptions)
{
    QProcess::execute(buildCommand);
    QProcess::execute("make " + makeOptions);


    /*
    QWidget sudoPassDialog;
    QLabel *passwordLabel = new QLabel("Enter your sudo password to install this application or click Cancel not to.");
    QLineEdit *passwordBox = new QLineEdit(&sudoPassDialog);
    sudoPassDialog.show();
    */
}


void MainWindow::on_autoCompileButton_clicked()
{
    extractFile(ui->dirTextAuto->text());
    //getBuildType();
}

void MainWindow::on_browseButtonAuto_clicked()
{
    QString sourceFilePath = getFile();
    ui->dirTextAuto->setText(sourceFilePath);
    ui->dirTextAdvanced->setText(sourceFilePath);
    ui->dirTextManual->setText(sourceFilePath);
}

void MainWindow::on_browseButtonManual_clicked()
{
    QString sourceFilePath = getFile();
    ui->dirTextAuto->setText(sourceFilePath);
    ui->dirTextAdvanced->setText(sourceFilePath);
    ui->dirTextManual->setText(sourceFilePath);
}

void MainWindow::on_browseButtonAdvanced_clicked()
{
    QString sourceFilePath = getFile();
    ui->dirTextAuto->setText(sourceFilePath);
    ui->dirTextAdvanced->setText(sourceFilePath);
    ui->dirTextManual->setText(sourceFilePath);
}

void MainWindow::on_pushButton_clicked()
{
    buildStart("./configure","","");
}

void MainWindow::on_manualCompileButton_clicked()
{
    if (ui->configSource->isChecked())
        buildStart(tempDirPath + "/configure", "","");
    else if (ui->qtSource->isChecked())
        buildStart("mkdir "+tempDirPath+"/Build; cd "+tempDirPath+"; cmake ..","","");
    else if (ui->autogenSource->isChecked())
        buildStart(tempDirPath+"");
}
