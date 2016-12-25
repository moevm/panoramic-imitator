#include "inc/panoramic_image_window.h"
#include "ui_panoramic_image_window.h"

PanoramicImageWindow::PanoramicImageWindow(float yRot, float xRot, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PanoramicImageWindow)
{
    ui->setupUi(this);
    QObject::connect(this, SIGNAL(keyPressSignal(QKeyEvent*)),
               ui->widget, SLOT(keyPressSlot(QKeyEvent*)));
    ui->widget->LoadImage("image.jpg");
    this->setFocus();
    char xRot_str[5], yRot_str[5];
    sprintf(xRot_str, "%i", (int) xRot);
    sprintf(yRot_str, "%i", (int) yRot);
    ui->widget->set_xRot(xRot_str);
    ui->widget->set_yRot(yRot_str);
    sprintf(xRot_str, "%i", (int) ui->widget->get_xRot());
    sprintf(yRot_str, "%i", (int) ui->widget->get_yRot());
    ui->xRot_textbox->setText(yRot_str);
    ui->yRot_textbox->setText(xRot_str);
}

PanoramicImageWindow::~PanoramicImageWindow()
{
    delete ui;
}
/**
 * @brief MainWindow::keyPressEvent обрабатывает нажатия клавиш клавиатуры
 * @param key - событие нажатия клавиши
 */
void PanoramicImageWindow::keyPressEvent(QKeyEvent* key)
{
    emit keyPressSignal(key);
    char xRot[5], yRot[5];
    if(key->key()==Qt::Key_Space)
    {
        ui->widget->set_xRot(ui->xRot_textbox->text());
        ui->widget->set_yRot(ui->yRot_textbox->text());
    }
    sprintf(xRot, "%i", (int) ui->widget->get_xRot());
    sprintf(yRot, "%i", (int) ui->widget->get_yRot());
    ui->xRot_textbox->setText(xRot);
    ui->yRot_textbox->setText(yRot);
}
