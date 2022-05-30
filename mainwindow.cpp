#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newuserwindow.h"
#include "searchuserwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_newUser_clicked()
{
    //abre uma tela para criar um usuário e salvar no BD
    NewUserWindow new_user_window;
    new_user_window.setModal(true);
    new_user_window.exec();
}


void MainWindow::on_readUser_clicked()
{
    //abre uma nova tela para buscar um usuário no BD
    SearchUserWindow search_user_window;
    search_user_window.setModal(true);
    search_user_window.exec();
}

