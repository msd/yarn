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
    if (!type_form)
    {
        type_form = new type_add_form(this);
        QObject::connect(type_form, &type_add_form::submitted, this, &MainWindow::handle_new_type_submit);
    }
    type_form->show();
}

void MainWindow::handle_new_type_submit(type_add_model new_type)
{
    qInfo().noquote() << "New type: " + new_type.to_string();
}

void MainWindow::handle_new_item_submit(views::add::item_add_model new_item)
{
    qInfo().noquote() << "New item: " + new_item.to_string();
}

void MainWindow::new_item_cb()
{
    using views::add::item_add_form;
    if (!item_form)
    {
        item_form = new item_add_form(this);
        QObject::connect(item_form, &item_add_form::submitted, this, &MainWindow::handle_new_item_submit);
    }
    item_form->show();
}

void MainWindow::delete_selected_cb()
{

    qInfo() << "DELTEING LOL"; //fixme

}
