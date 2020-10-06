#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

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

// when yes is clicked, go to chat with that person
// and change the person in the picture
void MainWindow::on_pushButton_2_clicked()
{

}

// when no is clicked, skip this person and
// change the person in the picture
void MainWindow::on_pushButton_clicked()
{

}
