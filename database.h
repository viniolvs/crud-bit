#ifndef DATABASE_H
#define DATABASE_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include "user.h"

class DataBase
{
private:
    QSqlDatabase data_base;

    void addDataBase();
    void removeDataBase();
    bool open();
    void close();

public:
    DataBase();
    ~DataBase();

    User* search(QString key_type, QString key);

    bool login(QString key_type, QString key, QString senha);

    //create (insere um usuário)
    bool insert(User user);

    //atualiza um usuário já existente
    bool update(User user, QString old_cpf);

    bool remove(User user);
};

#endif // DATABASE_H
