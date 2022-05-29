#ifndef NEWUSERWINDOW_H
#define NEWUSERWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class NewUserWindow;
}

class NewUserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NewUserWindow(QWidget *parent = nullptr);
    ~NewUserWindow();

private slots:
    void on_cadastra_btn_clicked();

    void on_cancela_btn_clicked();

private:
    Ui::NewUserWindow *ui;
};

#endif // NEWUSERWINDOW_H
