#include "mainwindow.h"
#include "./ui_mainwindow.h"

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
    QObject::connect(form, &type_add_form::submitted, this, &MainWindow::handle_new_type_submit);
    form->show();
}

void MainWindow::handle_new_type_submit(type_add_model new_type)
{

}

void MainWindow::new_item_cb()
{
}
