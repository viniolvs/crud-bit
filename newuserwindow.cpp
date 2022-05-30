#include "newuserwindow.h"
#include "ui_newuserwindow.h"
#include <QMessageBox>
#include "user.h"
#include "database.h"

NewUserWindow::NewUserWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewUserWindow)
{
    ui->setupUi(this);
}

NewUserWindow::~NewUserWindow()
{
    delete ui;
}

void NewUserWindow::on_cadastra_btn_clicked()
{
    QString nome = ui->nome_txt->text();
    QString sobrenome = ui->sobrenome_txt->text();
    QString cpf = ui->cpf_txt->text();
    QString nickname = ui->nickname_txt->text();
    QString senha = ui->senha_txt->text();
    QString data = ui->data_txt->text();

    if(nome.isEmpty() || sobrenome.isEmpty() || cpf.isEmpty() || nickname.isEmpty() || senha.isEmpty() || data.isEmpty())
        QMessageBox::warning(this,"Erro", "Preencha todos os campos para cadastrar!");

    User user(nome, sobrenome, nickname, senha, cpf, data);
    DataBase user_db;
    if(user_db.search("nickname", nickname)!=nullptr)
        QMessageBox::information(this, "Cadastro", "Usuário já cadastrado");
    else if(user_db.search("cpf", cpf)!=nullptr)
        QMessageBox::information(this, "Cadastro", "CPF já cadastrado");
    else if(user_db.insert(user))
    {
        QMessageBox::information(this, "Cadastro", "Usuário cadastrado com sucesso");
        this->close();
    }
    else
       qDebug() << "Erro ao inserir usuário!";
}


void NewUserWindow::on_cancela_btn_clicked()
{

}

