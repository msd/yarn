#ifndef VIEWS_ADD_ITEM_ADD_FORM_H
#define VIEWS_ADD_ITEM_ADD_FORM_H

#include <QDialog>

namespace views {
namespace add {

namespace Ui {
class item_add_form;
}

struct item_add_model
{
    QString name, type, source, notes;

    QString to_string()
    {
        return "<Name: " + name + ", Type: " + type + ", Source " + source + ", Notes: " + notes + ">";
    }
};

class item_add_form : public QDialog
{
    Q_OBJECT

public:
    explicit item_add_form(QWidget *parent = nullptr);
    ~item_add_form();

    item_add_model model();
    bool confirm_closing();
public slots:
    void reject();
    void submit();
signals:
    void submitted(item_add_model);
private:
    Ui::item_add_form *ui;
};


} // namespace add
} // namespace views
#endif // VIEWS_ADD_ITEM_ADD_FORM_H
