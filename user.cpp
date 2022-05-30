#include "user.h"
#include <QString>
#include <QString>

using namespace std;

User::User(QString nome, QString sobrenome, QString nickname, QString senha, QString CPF, QString data)
{
    this->nome = nome;
    this->sobrenome = sobrenome;
    this->nickname = nickname;
    this->senha = senha;
    this->CPF = CPF;
    this->data = data;
}
User::User(){};

QString User::getNome()
{
    return nome;
}
void User::setNome(QString nome)
{
    this->nome = nome;
}

QString User::getSobrenome()
{
    return sobrenome;
}
void User::setSobrenome(QString sobrenome)
{
    this->sobrenome = sobrenome;
}

QString User::getNickname()
{
    return nickname;
}
void User::setNickname(QString nickname)
{
    this->nickname = nickname;
}

QString User::getSenha()
{
    return senha;
}
void User::setSenha(QString senha)
{
    this->senha = senha;
}

QString User::getCPF()
{
    return CPF;
}
void User::setCPF(QString CPF)
{
    this->CPF = CPF;
}

QString User::getData()
{
    return data;
}
void User::setData(QString data)
{
    this->data = data;
}
