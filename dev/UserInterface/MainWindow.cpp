#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(Core* core, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_core = core;
    ui->gameField->setCore(m_core);
}

MainWindow::~MainWindow()
{
    delete ui;
}

