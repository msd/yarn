#ifndef VIEWS_EDIT2_TYPE_EDIT_FORM_H
#define VIEWS_EDIT2_TYPE_EDIT_FORM_H

#include <QDialog>

namespace views {
namespace edit2 {

namespace Ui {
class type_edit_form;
}

struct type_edit_model
{
    QString name, weight, composition, notes, source;
};

class type_edit_form : public QDialog
{
    Q_OBJECT

public:
    explicit type_edit_form(QWidget *parent = nullptr);
    ~type_edit_form();

    type_edit_model model();
    bool confirm_closing();
public slots:
    void submit();
    void reject();
private:
    Ui::type_edit_form *ui;
signals:
    void submitted(type_edit_model);
};


} // namespace edit2
} // namespace views
#endif // VIEWS_EDIT2_TYPE_EDIT_FORM_H
