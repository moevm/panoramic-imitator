#include "panoramic_image_window.h"
#include "ui_image_window.h"
#include "image_window.h"
ImageWindow::ImageWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImageWindow)
{
    ui->setupUi(this);
    QPixmap Pixmap("image.jpg");
    QSize imageSize = Pixmap.size();
    QSize labelSize = ui->label->size();
    if (imageSize.height()>labelSize.height() || imageSize.width()>labelSize.width())
        imageSize.scale((labelSize), Qt::KeepAspectRatio);
    ui->label->setScaledContents(true);
    ui->label->setPixmap(Pixmap);
    ui->xRot_textbox->setText("0");
    ui->yRot_textbox->setText("0");
}
ImageWindow::~ImageWindow()
{
    delete ui;
}
/**
 * @brief ImageWindow::on_OpenPanoramicImage_clicked открывает окно с частью
 *      сферического панорамного изображения
 */
void ImageWindow::on_OpenPanoramicImage_clicked()
{
    PanoramicImageWindow *window=new PanoramicImageWindow(ui->xRot_textbox->text().toFloat(),
                                                          ui->yRot_textbox->text().toFloat());
    window->show();
}
