#include "searchuserwindow.h"
#include "ui_searchuserwindow.h"
#include "user.h"
#include "database.h"
#include "userwindow.h"
#include <QMessageBox>

SearchUserWindow::SearchUserWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SearchUserWindow)
{
    ui->setupUi(this);
}

SearchUserWindow::~SearchUserWindow()
{
    delete ui;
}

void SearchUserWindow::on_seach_btn_clicked()
{
    QString nickname, cpf, senha;
    QString key_type, key;
    nickname = ui->nickname_txt->text();
    cpf = ui->cpf_txt->text();
    senha  = ui->senha_txt->text();
    if(cpf.isEmpty() && nickname.isEmpty())
        QMessageBox::warning(this,"Falha no login", "Preencha o campo Usuário ou CPF para logar!");
    else
    {
        DataBase user_db;
        if (!cpf.isEmpty())
        {
            key_type = "cpf";
            key = cpf;
        }
        else
        {
            key_type = "nickname";
            key = nickname;
        }
        //faz o login
        bool b = user_db.login(key_type, key, senha);
        if (b)
        {
            //abre tela usuario
            UserWindow user_window(this, key_type, key);
            user_window.exec();
        }
        else
          ui->output_label->setText("Falha no login!");
     }
        ui->cpf_txt->clear();
        ui->nickname_txt->clear();
}
