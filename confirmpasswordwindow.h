#ifndef CONFIRMPASSWORDWINDOW_H
#define CONFIRMPASSWORDWINDOW_H
#include "user.h"

#include <QDialog>

namespace Ui {
class ConfirmPasswordWindow;
}

class ConfirmPasswordWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmPasswordWindow(QWidget *parent = nullptr, User *user=nullptr);
    ~ConfirmPasswordWindow();
private slots:
    void on_ok_btn_clicked();

    void on_abort_btn_clicked();

private:
    Ui::ConfirmPasswordWindow *ui;
    User *user;
};

#endif // CONFIRMPASSWORDWINDOW_H
