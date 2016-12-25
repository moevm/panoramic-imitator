#include "inc/ImageLabel.h"

ImageLabel::ImageLabel(QWidget *parent): QLabel(parent)
{
    xRot=yRot=0;
}
/**
 * @brief ImageLabel::LoadImage выполняет загрузку изображения из файла
 * @param filename - путь к файлу
 */
void ImageLabel::LoadImage(char *filename)
{
    pixmap=new QPixmap(filename);
}
/**
 * @brief ImageLabel::paintEvent выполняет перерисовку содержимого
 * @param e - неиспользуемое в функции событие
 */
void ImageLabel::paintEvent(QPaintEvent* e)
{
    if(pixmap==NULL)
        return;
    Q_UNUSED(e);
    QPainter painter(this);
    painter.setPen(QPen(Qt::red, 1, Qt::SolidLine, Qt::FlatCap));
    QSize imageSize = pixmap->size();
    QSize labelSize = size();
    if (imageSize.height()>labelSize.height() || imageSize.width()>labelSize.width())
        imageSize.scale((labelSize), Qt::KeepAspectRatio);
    setScaledContents(true);
    setPixmap(*pixmap);
    painter.drawPixmap(0, 0, width(), height(), *pixmap);
    float x, y;
    x=0.75*width()-yRot*width()/360;
    y=0.5*height()-xRot*height()/180;
    if(x>width())
        x-=width();
    if(y<0)
    {
        x=x+width()/2;
        if(x>width())
            x-=width();
        y=-y;
    }
    painter.drawLine(x-10, y, x+10, y);
    painter.drawLine(x, y-10, x, y+10);
}
/**
 * @brief ImageLabel::set_xRot задаёт значение угла поворта вокруг горизнтальной оси
 * @param xRot - значение угла
 */
void ImageLabel::set_xRot(QString xRot)
{
    this->xRot=xRot.toFloat();
}
/**
 * @brief ImageLabel::set_yRot задаёт значение угла поворта вокруг вертикальной оси
 * @param yRot - значение угла
 */
void ImageLabel::set_yRot(QString yRot)
{
    this->yRot=yRot.toFloat();
}
/**
 * @brief PanoramicImage::rotate_up увеличивает вертикальный угол
 *      поворота камеры на 1 градус
 */
void ImageLabel::rotate_up()
{
    xRot++;
    if(xRot>180)
        xRot=180;
}
/**
 * @brief PanoramicImage::rotate_down уменьшает вертикальный угол
 *      поворота камеры на 1 градус
 */
void ImageLabel::rotate_down()
{
    xRot--;
    if(xRot<0)
        xRot=0;
}
/**
 * @brief PanoramicImage::rotate_left увеличивает горизонтальный угол
 *      поворота камеры на 1 градус
 */
void ImageLabel::rotate_left()
{
    yRot++;
    while(yRot>180)
        yRot-=360;
}
/**
 * @brief PanoramicImage::rotate_right уменьшает горизонтальный угол
 *      поворота камеры на 1 градус
 */
void ImageLabel::rotate_right()
{
    yRot--;
    while(yRot<-180)
        yRot+=360;
}
/**
 * @brief PanoramicImage::keyPressSlot обрабатывает нажатия клавиш клавиатуры
 * @param key - событие нажатия клавиши
 */
void ImageLabel::keyPressSlot(QKeyEvent* key)
{
    switch (key->key())
    {
    case Qt::Key_Up:
        rotate_up();
        break;
    case Qt::Key_Down:
        rotate_down();
        break;
    case Qt::Key_Left:
        rotate_left();
        break;
    case Qt::Key_Right:
        rotate_right();
        break;
    }
}
/**
 * @brief PanoramicImage::mousePressEvent устанавливает фокус на label при нажатии
 *      на него левой кнопкой мыши
 * @param event - событие нажатия кнопки мыши
 */
void ImageLabel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
        this->setFocus();
}
