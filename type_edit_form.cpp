#include "type_edit_form.h"
#include "ui_type_edit_form.h"
#include <QMessageBox>

namespace views {
namespace edit2 {

type_edit_form::type_edit_form(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::type_edit_form)
{
    ui->setupUi(this);
}

type_edit_form::~type_edit_form()
{
    delete ui;
}

type_edit_model type_edit_form::model()
{
    type_edit_model m{};
    m.composition = ui->composition->text();
    m.name = ui->name->text();
    m.weight = ui->weight->text();
    m.notes = ui->notes->text();
    m.source = ui->source->text();
    return m;
}

bool type_edit_form::confirm_closing()
{
    auto reply = QMessageBox::question(this, "Edit form", "Close without submitting?");
    if (reply == QMessageBox::StandardButton::Yes)
    {
        return true;
    }
    return false;
}

void type_edit_form::submit()
{
    emit submitted(model());
}

void type_edit_form::reject()
{
    if (confirm_closing())
    {
        QDialog::reject();
    }
}

} // namespace edit2
} // namespace views
