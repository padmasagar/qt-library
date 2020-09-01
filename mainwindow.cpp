#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"window.h"
#include<QLibrary>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Window ref;
// ref= new.Window();
    ref.createControls("title");


}

MainWindow::~MainWindow()
{
    delete ui;
}

