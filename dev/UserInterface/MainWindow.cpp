#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //QString pic1 = "C:/Projects/Chess_v2/dev/Resources/Pictures/Field_white";
    //QString pic2 = "C:/Projects/Chess_v2/dev/Resources/Pictures/Field_black";

    //QPixmap pix1(":dev/Resources/Pictures/Field_white");
    //QPixmap pix2(":dev/Resources/Pictures/Field_black");

}

MainWindow::~MainWindow()
{
    delete ui;
}

