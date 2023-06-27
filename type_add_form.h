#ifndef type_ADD_FORM_H
#define type_ADD_FORM_H

#include <QDialog>

namespace Ui {
class type_add_form;
}

struct type_add_model
{
    QString name, weight, composition, source, notes;

    QString to_string()
    {
        return "Type<Name: " + name + ", Weight: " +weight + ", Source: " + source + ", Notes: " + notes + ">";
    }
};

class type_add_form : public QDialog
{
    Q_OBJECT

public:
    explicit type_add_form(QWidget *parent = nullptr);
    ~type_add_form();
    type_add_model model();
    bool confirm_closing();
public slots:
    void reject();
    void submit();
signals:
    void submitted(type_add_model);
private:
    bool confirmed_close = false;
    Ui::type_add_form *ui;
};

#endif // type_ADD_FORM_H
