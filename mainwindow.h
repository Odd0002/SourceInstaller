#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

void autoMode();
QString getFile();
void buildStart();
void extractFile();

namespace Ui {
class MainWindow;
}

// added private Ui::MainWindow

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_autoCompileButton_clicked();

    void on_browseButtonAuto_clicked();

    void on_browseButtonManual_clicked();

    void on_browseButtonAdvanced_clicked();

    void on_pushButton_clicked();

    void on_manualCompileButton_clicked();

    void on_actionQuit_triggered();

    void on_advancedCompileButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
