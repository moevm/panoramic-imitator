#include "image_window.h"
#include "ui_image_window.h"

ImageWindow::ImageWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImageWindow)
{
    ui->setupUi(this);
}

ImageWindow::~ImageWindow()
{
    delete ui;
}
