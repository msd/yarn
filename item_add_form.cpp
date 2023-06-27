#include "item_add_form.h"
#include "ui_item_add_form.h"
#include <QMessageBox>

namespace views {
namespace add {

item_add_form::item_add_form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::item_add_form)
{
    ui->setupUi(this);
}

item_add_form::~item_add_form()
{
    delete ui;
}

item_add_model item_add_form::model()
{
    QString name, type, source, notes;
    item_add_model m{};
    m.name = ui->name->text();
    m.type = ui->type->text();
    m.notes = ui->notes->text();
    m.source = ui->source->text();
    return m;
}

bool item_add_form::confirm_closing()
{
    auto reply = QMessageBox::question(this, "Edit form", "Close without submitting?");
    if (reply == QMessageBox::StandardButton::Yes)
    {
        return true;
    }
    return false;
}

void item_add_form::submit()
{
    emit submitted(model());
}

void item_add_form::reject()
{
    if (confirm_closing())
    {
        QDialog::reject();
    }
}


} // namespace add
} // namespace views
