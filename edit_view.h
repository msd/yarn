#ifndef VIEWS_EDIT_EDITVIEW_H
#define VIEWS_EDIT_EDITVIEW_H

#include <QWidget>

namespace views {
namespace edit {

class EditView : public QWidget
{
    Q_OBJECT
public:
    explicit EditView(QWidget *parent = nullptr);

signals:

};

} // namespace edit
} // namespace views

#endif // VIEWS_EDIT_EDITVIEW_H
