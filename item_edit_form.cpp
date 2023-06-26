#include "item_edit_form.h"
#include "ui_item_edit_form.h"

namespace views {
namespace edit2 {

item_edit_form::item_edit_form(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::item_edit_form)
{
    ui->setupUi(this);
}

item_edit_form::~item_edit_form()
{
    delete ui;
}

} // namespace edit2
} // namespace views
