#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QDialog>
#include "user.h"

namespace Ui {
class UserWindow;
}

class UserWindow : public QDialog
{
    Q_OBJECT
public:
    explicit UserWindow(QWidget *parent = nullptr, QString key_type = "", QString key = "");
    ~UserWindow();
private slots:
    void on_update_user_btn_clicked();

    void on_delete_user_btn_clicked();

    void on_display_data_btn_clicked();

    void on_exit_btn_clicked();

private:
    Ui::UserWindow *ui;
    QString key;
    QString key_type;
};

#endif // USERWINDOW_H
