#include "type_add_form.h"
#include "ui_type_add_form.h"

type_add_form::type_add_form(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::type_add_form)
{
    ui->setupUi(this);
}

type_add_form::~type_add_form()
{
    delete ui;
}
