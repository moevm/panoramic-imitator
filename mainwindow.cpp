#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(this, SIGNAL(keyPressSignal(QKeyEvent*)),
               ui->widget, SLOT(keyPressSlot(QKeyEvent*)));
    ui->widget->LoadImage("image.jpg");
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::keyPressEvent(QKeyEvent* key)
{
    emit keyPressSignal(key);
}
