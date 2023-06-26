#include "item_add_form.h"
#include "ui_item_add_form.h"

namespace views {
namespace add {

item_add_form::item_add_form(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::item_add_form)
{
    ui->setupUi(this);
}

item_add_form::~item_add_form()
{
    delete ui;
}

} // namespace add
} // namespace views
