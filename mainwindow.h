#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "type_add_form.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void new_type_cb();
    void new_item_cb();
    void handle_new_type_submit(type_add_model new_type);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
