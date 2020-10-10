#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// aplication closes when quit button is clicked
void MainWindow::on_actionQuit_triggered()
{
    close();
}

// when no is clicked, skip this person and
// change the person in the picture
void MainWindow::on_pushButton_2_clicked()
{

}

// when yes is clicked, go to chat with that person
// and change the person in the picture
void MainWindow::on_pushButton_clicked()
{

}

// when Help/About is clicked, display messagebox
void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About Binder", "<h1><b>BINDER</b></h1> <br>"
                                             "Binder is an app helping people <br>"
                                             "find others to communicate with");
}
