#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(this, SIGNAL(keyPressSignal(QKeyEvent*)),
               ui->widget, SLOT(keyPressSlot(QKeyEvent*)));
    QObject::connect(this, SIGNAL(applyPressSignal()),
               ui->widget, SLOT(applyPressSlot()));
    ui->widget->LoadImage("image.jpg");
    ui->label->LoadImage("image.jpg");
    QObject::connect(this, SIGNAL(keyPressSignal(QKeyEvent*)),
               ui->label, SLOT(keyPressSlot(QKeyEvent*)));
    ui->xRot_textbox->setText("0");
    ui->yRot_textbox->setText("0");
    ui->label->setFocus();
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
    if(key->key()==Qt::Key_Space)
    {
        ui->widget->set_xRot(ui->xRot_textbox->text());
        ui->widget->set_yRot(ui->yRot_textbox->text());
    }
    sprintf(xRot, "%i", (int) ui->widget->get_xRot());
    sprintf(yRot, "%i", (int) ui->widget->get_yRot());
    ui->label->set_xRot(xRot);
    ui->label->set_yRot(yRot);
    ui->xRot_textbox->setText(xRot);
    ui->yRot_textbox->setText(yRot);
}
/**
 * @brief MainWindow::on_Apply_clicked изменяет панораму в соотвествии
 *      с введёнными в текстовые поля значениями
 */
void MainWindow::on_Apply_clicked()
{
    ui->label->setFocus();
    char xRot[5], yRot[5];
    ui->widget->set_xRot(ui->xRot_textbox->text());
    ui->widget->set_yRot(ui->yRot_textbox->text());
    emit applyPressSignal();
    sprintf(xRot, "%i", (int) ui->widget->get_xRot());
    sprintf(yRot, "%i", (int) ui->widget->get_yRot());
    ui->label->set_xRot(xRot);
    ui->label->set_yRot(yRot);
    ui->xRot_textbox->setText(xRot);
    ui->yRot_textbox->setText(yRot);
}
