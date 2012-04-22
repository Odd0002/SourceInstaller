#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

void autoMode();
bool getFile();
void buildStart();

namespace Ui {
class MainWindow;
}

// added private Ui::MainWindow

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_actionChoose_file_triggered();

    void on_actionAutomatic_mode_triggered();

    void on_autoCompileButton_clicked();

    void on_browseButtonAuto_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
