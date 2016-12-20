#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pbdata.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(this, SIGNAL(keyPressSignal(QKeyEvent*)),
               ui->widget, SLOT(keyPressSlot(QKeyEvent*)));
    ui->widget->LoadImage("image.jpg");
    this->setFocus();
    ui->xRot_textbox->setText("0");
    ui->yRot_textbox->setText("0");
}
MainWindow::~MainWindow()
{
    delete ui;
}
/**
 * @brief MainWindow::keyPressEvent обрабатывает нажатия клавиш клавиатуры
 * @param key - событие нажатия клавиши
 */
void MainWindow::keyPressEvent(QKeyEvent* key)
{
    emit keyPressSignal(key);
    char xRot[5], yRot[5];
    sprintf(xRot, "%i", (int) ui->widget->get_xRot());
    sprintf(yRot, "%i", (int) ui->widget->get_yRot());
    if(key->key()==Qt::Key_Space)
    {
        ui->widget->set_xRot(ui->xRot_textbox->text());
        ui->widget->set_yRot(ui->yRot_textbox->text());
    }
    ui->xRot_textbox->setText(xRot);
    ui->yRot_textbox->setText(yRot);
}
