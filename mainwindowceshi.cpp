#include "mainwindowceshi.h"
#include "ui_mainwindowceshi.h"

MainWindowCeshi::MainWindowCeshi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowCeshi)
{
    ui->setupUi(this);
}

MainWindowCeshi::~MainWindowCeshi()
{
    delete ui;
}
