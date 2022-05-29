#ifndef USER_H
#define USER_H
#include <QString>

using namespace std;

class User
{
private:
     QString nome;
     QString sobrenome;
     QString nickname;
     QString senha;
     QString CPF;
     QString data;

public:
    User(QString nome, QString sobrenome, QString nickname, QString senha, QString CPF, QString data);

    User();

    QString getNome();
    void setNome(QString nome);

    QString getSobrenome();
    void setSobrenome(QString sobrenome);

    QString getNickname();
    void setNickname(QString nickname);

    QString getSenha();
    void setSenha(QString senha);

    QString getCPF();
    void setCPF(QString CPF);

    QString getData();
    void setData(QString Data);
};

#endif // USER_H
