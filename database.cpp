#include "database.h"
#include "user.h"
#include <QDebug>
#include <QtSql>

DataBase::DataBase()
{
    addDataBase();
}

DataBase::~DataBase()
{
    removeDataBase();
}

void DataBase::addDataBase()
{
    data_base = QSqlDatabase::addDatabase("QSQLITE");
    data_base.setDatabaseName("/home/vinicius/Documents/Facul/Programas/Projects/projeto-bit/CRUD/users.db");
}

void DataBase::removeDataBase()
{
    data_base.removeDatabase("/home/vinicius/Documents/Facul/Programas/Projects/projeto-bit/CRUD/users.db");
}

bool DataBase::open()
{
    return this->data_base.open();
}

void DataBase::close()
{
    this->data_base.close();
}

User* DataBase::search(QString key_type, QString key)
{
    open();
    QString cpf = "cpf";
    QSqlQuery query;
    User *user = nullptr;
    int key_number;
    if(key_type==cpf)
        key_number = 0;
    else
        key_number = 1;
    if(query.exec("select * from tb_users"))
    {
        while(query.next())
        {
            if(query.value(key_number).toString() == key)
            {
                user = new User();
                user->setCPF(query.value(0).toString());
                user->setNickname(query.value(1).toString());
                user->setNome(query.value(2).toString());
                user->setSobrenome(query.value(3).toString());
                user->setData(query.value(4).toString());
                user->setSenha(query.value(5).toString());
                break;
             }
        }
    }
    query.finish();
    close();
    return user;
}

bool DataBase::login(QString key_type, QString key, QString senha)
{
    open();
    QSqlQuery query;
    bool b;
    int count=0;
    if(query.exec("select * from tb_users where "+key_type+"='"+key+"' and senha = '"+senha+"'"))
        while(query.next())
            count++;
    if (count == 1)
        b = true;
    else
        b=false;
    query.finish();
    close();
    return b;
}



bool DataBase::insert(User user)
{
    open();
    QSqlQuery query;

    query.prepare("insert into tb_users (cpf,nickname,nome,sobrenome,data,senha) values"
                  "('"+user.getCPF()+"','"+user.getNickname()+"','"+user.getNome()+"','"+user.getSobrenome()+"','"+user.getData()+"','"+user.getSenha()+"')");
    bool b = query.exec();
    query.finish();
    close();
    return b;
}

bool DataBase::remove(User user)
{
    open();
    QSqlQuery query;
    bool b;
    query.prepare("delete from tb_users where cpf="+user.getCPF());
    b = query.exec();
    query.finish();
    close();
    return b;
}

bool DataBase::update(User user, QString old_cpf)
{
    open();
    QSqlQuery query;
    bool b;
    query.prepare("update tb_users set nome='"+user.getNome()+"', sobrenome='"+user.getSobrenome()+"', nickname='"+user.getNickname()+"',"
                   "senha='"+user.getSenha()+"', cpf='"+user.getCPF()+"' where cpf='"+old_cpf+"'");
    b = query.exec();
    query.finish();
    close();
    return b;
}
