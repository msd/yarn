#ifndef type_ADD_FORM_H
#define type_ADD_FORM_H

#include <QFrame>

namespace Ui {
class type_add_form;
}

class type_add_form : public QFrame
{
    Q_OBJECT

public:
    explicit type_add_form(QWidget *parent = nullptr);
    ~type_add_form();

private:
    Ui::type_add_form *ui;
};

#endif // type_ADD_FORM_H
