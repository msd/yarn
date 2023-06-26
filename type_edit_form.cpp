#include "type_edit_form.h"
#include "ui_type_edit_form.h"

namespace views {
namespace edit2 {

type_edit_form::type_edit_form(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::type_edit_form)
{
    ui->setupUi(this);
}

type_edit_form::~type_edit_form()
{
    delete ui;
}

} // namespace edit2
} // namespace views
