#ifndef UPDATEUSERWINDOW_H
#define UPDATEUSERWINDOW_H

#include <QDialog>
#include "user.h"

namespace Ui {
class UpdateUserWindow;
}

class UpdateUserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateUserWindow(QWidget *parent = nullptr, User *old_user=nullptr);
    ~UpdateUserWindow();

private slots:
    void on_cancela_btn_clicked();

    void on_update_btn_clicked();

private:
    Ui::UpdateUserWindow *ui;
    User *old_user;
};

#endif // UPDATEUSERWINDOW_H
