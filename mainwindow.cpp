#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "type_add_form.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::new_type_cb()
{
    auto form = new type_add_form();
    form->show();
}

void MainWindow::new_item_cb()
{
}
