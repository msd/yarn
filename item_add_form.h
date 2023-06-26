#ifndef VIEWS_ADD_ITEM_ADD_FORM_H
#define VIEWS_ADD_ITEM_ADD_FORM_H

#include <QFrame>

namespace views {
namespace add {

namespace Ui {
class item_add_form;
}

class item_add_form : public QFrame
{
    Q_OBJECT

public:
    explicit item_add_form(QWidget *parent = nullptr);
    ~item_add_form();

private:
    Ui::item_add_form *ui;
};


} // namespace add
} // namespace views
#endif // VIEWS_ADD_ITEM_ADD_FORM_H
