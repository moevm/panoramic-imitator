#include "panoramic_image_window.h"
#include "ui_panoramic_image_window.h"

PanoramicImageWindow::PanoramicImageWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PanoramicImageWindow)
{
    ui->setupUi(this);
}

PanoramicImageWindow::~PanoramicImageWindow()
{
    delete ui;
}
