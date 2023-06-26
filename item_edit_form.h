#ifndef VIEWS_EDIT2_ITEM_EDIT_FORM_H
#define VIEWS_EDIT2_ITEM_EDIT_FORM_H

#include <QFrame>

namespace views {
namespace edit2 {

namespace Ui {
class item_edit_form;
}

class item_edit_form : public QFrame
{
    Q_OBJECT

public:
    explicit item_edit_form(QWidget *parent = nullptr);
    ~item_edit_form();

private:
    Ui::item_edit_form *ui;
};


} // namespace edit2
} // namespace views
#endif // VIEWS_EDIT2_ITEM_EDIT_FORM_H
