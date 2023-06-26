#ifndef VIEWS_EDIT2_TYPE_EDIT_FORM_H
#define VIEWS_EDIT2_TYPE_EDIT_FORM_H

#include <QFrame>

namespace views {
namespace edit2 {

namespace Ui {
class type_edit_form;
}

class type_edit_form : public QFrame
{
    Q_OBJECT

public:
    explicit type_edit_form(QWidget *parent = nullptr);
    ~type_edit_form();

private:
    Ui::type_edit_form *ui;
};


} // namespace edit2
} // namespace views
#endif // VIEWS_EDIT2_TYPE_EDIT_FORM_H
