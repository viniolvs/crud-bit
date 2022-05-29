#ifndef SEARCHUSERWINDOW_H
#define SEARCHUSERWINDOW_H

#include <QDialog>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class SearchUserWindow;
}

class SearchUserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SearchUserWindow(QWidget *parent = nullptr);
    ~SearchUserWindow();

private slots:
    void on_seach_btn_clicked();

private:
    Ui::SearchUserWindow *ui;
};

#endif // SEARCHUSERWINDOW_H
