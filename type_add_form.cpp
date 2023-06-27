#include "type_add_form.h"
#include "ui_type_add_form.h"
#include <QMessageBox>
#include <QPushButton>

type_add_form::type_add_form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::type_add_form)
{
    ui->setupUi(this);
}

type_add_model type_add_form::model()
{
    type_add_model m{};
    m.compositon = ui->composition->text();
    m.name = ui->name->text();
    m.weight = ui->weight->text();
    m.notes = ui->notes->text();
    m.source = ui->source->text();
    return m;
}

bool type_add_form::confirm_closing()
{
    auto reply = QMessageBox::question(this, "Edit form", "Close without submitting?");
    if (reply == QMessageBox::StandardButton::Yes)
    {
        return true;
    }
    return false;
}

void type_add_form::submit()
{
    emit submitted(model());
}

type_add_form::~type_add_form()
{
    delete ui;
}

void type_add_form::reject()
{
    if (confirm_closing())
    {
        QDialog::reject();
    }
}
