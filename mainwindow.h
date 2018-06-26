#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QVector>
#include <QLineEdit>
#include <QLayout>
#include <QComboBox>
#include <QLabel>
#include <QFrame>
#include <QGroupBox>
#include <QPushButton>
#include <QTabWidget>
#include <QTreeWidget>
#include <QPalette>
#include <QBrush>
#include <QPixmap>
#include <QDateTime>
#include <QtSql>
#include <QStringList>
#include <QPluginLoader>
#include <QMessageBox>
#include <QCheckBox>
#include <QTableWidget>
#include <QTimer>
#include <QFileDialog>
#include <QDebug>
#include "framregister.h"
#include "ui_framregister.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QSqlDatabase db;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    bool createConnection();

    void on_register_button_clicked();

    void on_manager_log_in_clicked();

    void on_user_log_in_clicked();

    void on_log_out_clicked();

    void on_make_empty_clicked();

    void on_treeWidget_clicked(const QModelIndex &index);

    void update_table(QTableWidget* tableWidget,QVector<QString> &result);

    void update_table_checkInfo(QTableWidget* tableWidget,QVector<QString> &result);

    void update_table_checkInfo_manager(QTableWidget* tableWidget,QVector<QString> &result);

    void update_table_mutibook(QTableWidget* tableWidget,QVector<QString> &result);

    void on_borrow_book_clicked();

    void on_search_book_clicked();

    void on_check_info_clicked();

    void on_return_book_clicked();

    void on_manager_check_clicked();

    void on_delete_card_clicked();

    void on_give_card_id_button_clicked();

    void on_check_in_base_clicked();

    void on_empty_info_in_clicked();

    void on_muti_books_in_clicked();

    void on_make_muti_empty_clicked();

    void on_submit_muti_clicked();

    void on_order_tree_clicked(const QModelIndex &index);

    void on_next_page_clicked();

    void on_last_page_clicked();

private:
    Ui::MainWindow *ui;
    //FramRegister view;
    enum{tourist=-1,user,manager};
    int user_type = -1;
    QString current_name;//用来记下当前的操作人信息
    QString current_book_type = "";//用来记下当前的书籍类型
    QString order_type = ""; //用来排序的标志
    QString page_info = ""; //刷新当前的页码信息
    int current_page = 1; //当前的页码
    int max_page = 10; //最大的页码
    QVector<QString> result_flash_table;//用来动态更新值

    int tree_flag = 0;
    int normal_flag = 0; //记录当前是用哪种方式查询的
};

#endif // MAINWINDOW_H
