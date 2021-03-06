#include "inc/mainwindow.h"
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

    QString appPath = QApplication::applicationDirPath();
    QString imagePath = appPath + "/image.jpg";
    qDebug(imagePath.toLatin1());
    QFile::copy(":/images/res/image.jpg", imagePath.toLatin1());

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
	char xRot[5], yRot[5], frameSize[5];
    if(key->key()==Qt::Key_Space)
    {
		ui->widget->set_xRot(ui->xRot_textbox->text());//углы
        ui->widget->set_yRot(ui->yRot_textbox->text());

		ui->widget->set_frameSize(ui->frameSize_textbox->text());//рамка
    }
    sprintf(xRot, "%i", (int) ui->widget->get_xRot());
    sprintf(yRot, "%i", (int) ui->widget->get_yRot());
	sprintf(frameSize, "%i", (int) ui->widget->get_frameSize());
    ui->label->set_xRot(xRot);
    ui->label->set_yRot(yRot);
    ui->xRot_textbox->setText(xRot);
    ui->yRot_textbox->setText(yRot);
	ui->frameSize_textbox->setText(frameSize);
    if((key->key()==Qt::Key_Up)||(key->key()==Qt::Key_Down)||(key->key()==Qt::Key_Left)
            ||(key->key()==Qt::Key_Right)||(key->key()==Qt::Key_Space))
    {
        ui->xRot_label->setText("Текущее\n значение: "+QString(xRot));
        ui->yRot_label->setText("Текущее\n значение: "+QString(yRot));
    }
}
/**
 * @brief MainWindow::on_Apply_clicked изменяет панораму в соотвествии
 *      с введёнными в текстовые поля значениями
 */
void MainWindow::on_Apply_clicked()
{
    ui->label->setFocus();
	char xRot[5], yRot[5], frameSize[5];
	ui->widget->set_xRot(ui->xRot_textbox->text());
	ui->widget->set_yRot(ui->yRot_textbox->text());
	ui->widget->set_frameSize(ui->frameSize_textbox->text());
    emit applyPressSignal();
    sprintf(xRot, "%i", (int) ui->widget->get_xRot());
    sprintf(yRot, "%i", (int) ui->widget->get_yRot());
	sprintf(frameSize, "%i", (int) ui->widget->get_frameSize());
    ui->label->set_xRot(xRot);
    ui->label->set_yRot(yRot);
    ui->xRot_textbox->setText(xRot);
    ui->yRot_textbox->setText(yRot);
	ui->frameSize_textbox->setText(frameSize);
    ui->xRot_label->setText("Текущее\n значение: "+QString(xRot));
    ui->yRot_label->setText("Текущее\n значение: "+QString(yRot));
}
