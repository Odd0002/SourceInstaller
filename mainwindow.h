#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

void autoMode();
bool getFile();
void buildStart();
//

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    void on_actionChoose_file_triggered();

    void on_actionAutomatic_mode_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
