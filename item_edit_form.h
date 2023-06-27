#ifndef VIEWS_EDIT2_ITEM_EDIT_FORM_H
#define VIEWS_EDIT2_ITEM_EDIT_FORM_H

#include <QDialog>

namespace views {
namespace edit2 {

namespace Ui {
class item_edit_form;
}

struct item_edit_model
{
    QString name, type, source, notes;
};


class item_edit_form : public QDialog
{
    Q_OBJECT

public:
    explicit item_edit_form(QWidget *parent = nullptr);
    ~item_edit_form();

    item_edit_model model();
    bool confirm_closing();
public slots:
    void reject();
    void submit();
signals:
    void submitted(item_edit_model);
private:
    Ui::item_edit_form *ui;
};


} // namespace edit2
} // namespace views
#endif // VIEWS_EDIT2_ITEM_EDIT_FORM_H
