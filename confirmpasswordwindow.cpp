#include "confirmpasswordwindow.h"
#include "ui_confirmpasswordwindow.h"
#include "database.h"
#include <QMessageBox>
#include "user.h"

ConfirmPasswordWindow::ConfirmPasswordWindow(QWidget *parent, User *user) :
    QDialog(parent),
    ui(new Ui::ConfirmPasswordWindow)
{
    ui->setupUi(this);
    this->user = user;
}

ConfirmPasswordWindow::~ConfirmPasswordWindow()
{
    delete ui;
}

void ConfirmPasswordWindow::on_ok_btn_clicked()
{
    DataBase db;
    if(ui->senha_txt->text() == user->getSenha())
    {
        if (db.remove(*user))
        {
            QMessageBox::information(this,"","Conta excluída com sucessso!");
            this->close();
        }
    }
    else
        QMessageBox::information(this,"","Senha incorreta!");
}


void ConfirmPasswordWindow::on_abort_btn_clicked()
{
    this->close();
}

