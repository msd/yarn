#include "item_edit_form.h"
#include "ui_item_edit_form.h"
#include <QMessageBox>

namespace views {
namespace edit2 {

item_edit_form::item_edit_form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::item_edit_form)
{
    ui->setupUi(this);
}

item_edit_form::~item_edit_form()
{
    delete ui;
}

item_edit_model item_edit_form::model()
{
    QString name, type, source, notes;
    item_edit_model m{};
    m.name = ui->name->text();
    m.type = ui->type->text();
    m.notes = ui->notes->text();
    m.source = ui->source->text();
    return m;
}

bool item_edit_form::confirm_closing()
{
    auto reply = QMessageBox::question(this, "Edit form", "Close without submitting?");
    if (reply == QMessageBox::StandardButton::Yes)
    {
        return true;
    }
    return false;
}

void item_edit_form::submit()
{
    emit submitted(model());
}

void item_edit_form::reject()
{
    if (confirm_closing())
    {
        QDialog::reject();
    }
}


} // namespace edit2
} // namespace views
