#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "defs.h"
#include <QMainWindow>
#include "aboutdialog.h"
#include "contactdialog.h"
#include"home.h"
#include"addteacher.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void about();
    void contact();
    void add();
    void remove();
    void switchtohome();
    void actualisedata();
private:
    home *m_home;
    QAction *m_home_button;
    QAction * m_edit_button;
    QSqlDatabase m_db;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
