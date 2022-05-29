#include "userwindow.h"
#include "ui_userwindow.h"
#include "user.h"
#include "database.h"
#include "confirmpasswordwindow.h"
#include "updateuserwindow.h"
#include <QMessageBox>

UserWindow::UserWindow(QWidget *parent, QString key_type, QString key) :
    QDialog(parent),
    ui(new Ui::UserWindow)
{
    ui->setupUi(this);
    this->key = key;
    this->key_type = key_type;
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::on_update_user_btn_clicked()
{
    DataBase db;
    UpdateUserWindow update_user_window(this, db.search(key_type, key));
    update_user_window.setModal(true);
    update_user_window.exec();
    this->close();
}


void UserWindow::on_delete_user_btn_clicked()
{
    DataBase db;
    ConfirmPasswordWindow confirm_password(this, db.search(key_type, key));
    confirm_password.exec();
    this->close();
}


void UserWindow::on_display_data_btn_clicked()
{
    DataBase db;
    User *user = db.search(key_type, key);
    QMessageBox::information(this,"Dados do Cadastro", "Nome: "+user->getNome()+
                             "\nSobrenome: "+user->getSobrenome()+"\nUsuário: "+user->getNickname()+
                             "\nSenha: "+user->getSenha()+"\nCPF: "+user->getCPF()+
                             "\nData do Cadastro: "+user->getData());
}


void UserWindow::on_exit_btn_clicked()
{
    this->close();
}

