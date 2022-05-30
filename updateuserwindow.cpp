#include "updateuserwindow.h"
#include "ui_updateuserwindow.h"
#include "database.h"
#include "user.h"
#include <QMessageBox>

UpdateUserWindow::UpdateUserWindow(QWidget *parent, User *old_user) :
    QDialog(parent),
    ui(new Ui::UpdateUserWindow)
{
    ui->setupUi(this);
    this->old_user = old_user;
}

UpdateUserWindow::~UpdateUserWindow()
{
    delete ui;
}

void UpdateUserWindow::on_cancela_btn_clicked()
{
    this->close();
}


void UpdateUserWindow::on_update_btn_clicked()
{
    QString nome=ui->nome_txt->text();
    QString sobrenome=ui->sobrenome_txt->text();
    QString nickname = ui->nickname_txt->text();
    QString cpf = ui->cpf_txt->text();
    QString senha = ui->senha_txt->text();
    QString data = old_user->getData();

    bool b;
    DataBase db;

    if(cpf!=old_user->getCPF() && db.search("cpf", cpf) != nullptr)
            QMessageBox::information(this, "Erro","CPF já cadastrado!");
    else if (nickname!=old_user->getNickname() && db.search("nickname", nickname) != nullptr)
            QMessageBox::information(this,"Erro","Usuário já cadastrado!");
    else
    {
        User user(nome,sobrenome,nickname,senha,cpf,data);
        b = db.update(user, old_user->getCPF());
        if(b)
            QMessageBox::information(this,"Atualizar Cadastro", "Cadastro atualizado com sucesso!");
        else
            QMessageBox::warning(this,"Atualizar Cadastro", "Falha ao atualizar cadastro!");
        this->close();
    }
}

