#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "framregister.h"
#include "ui_framregister.h"
#include <QSqlDatabase>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->log_out->setDisabled(true);
    ui->borrow_book->setDisabled(true);
    ui->card_id->setDisabled(true);
    ui->give_cardid_line->setDisabled(true);
    ui->muti_books_in->setDisabled(true);
    ui->pass_line->setEchoMode(QLineEdit::Password);
    ui->pass_line->setPlaceholderText("密码栏");
    ui->ID_line->setPlaceholderText("ID栏");
    ui->card_id->setPlaceholderText("借书卡号栏");
    user_type = tourist;
    createConnection();
}

MainWindow::~MainWindow()
{
    db.removeDatabase("book_manage");
    delete ui;
}

/*注册用户功能*/
void MainWindow::on_register_button_clicked()
{
    QString text_id = ui->ID_line->text();
    QString pass_id = ui->pass_line->text();
    QString str;
    QSqlQuery query;
    int flag = 1;

    if(text_id == "" || pass_id == "")
        QMessageBox::about(0,QObject::tr("Fail"),"注册时用户名或密码不能为空!");
    else
    {
        query.exec("select * from user");
        while(query.next())
        {
            str = query.value(0).toString();
            if(QString::compare(str, text_id) == 0)
            {
                QMessageBox::about(0,QObject::tr("Fail"),"用户名已注册!");
                flag = 0;
                break;
            }
        }

        if(flag == 1)
        {
            query.exec("insert into user values('"+text_id+"','"+pass_id+"')");
            if(query.isActive())
                QMessageBox::about(0,QObject::tr("success"),"注册成功!");
            else
                QMessageBox::about(0,QObject::tr("fail"),"插入数据库失败!");
        }
    }

    ui->ID_line->clear();
    ui->pass_line->clear();
}

/*连接数据库*/
bool MainWindow::createConnection()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("book_manage");
    db.setUserName("root");
    db.setPassword("hhhhh19990910");
    db.setPort(3306);
    if(!db.open()){
        QMessageBox::critical(0,QObject::tr("error"),db.lastError().text());
        return false;
    }
    return true;
}

/*管理员登陆*/
void MainWindow::on_manager_log_in_clicked()
{
    QString text_id = ui->ID_line->text();
    QString pass_id = ui->pass_line->text();

    if(text_id == "" || pass_id == "")
        QMessageBox::about(0,QObject::tr("Fail"),"用户名或密码不能为空!");
    else
    {
        QSqlQuery query;
        query.exec("select password from manager where username = '"+text_id+"'");
        QString str;
        while(query.next())
        {
           str = query.value(0).toString();
        }

        if(str.isEmpty()) QMessageBox::about(0,QObject::tr("error"),"no such id!");
        else if(QString::compare(str, pass_id) == 0)
        {
            QMessageBox::about(0,QObject::tr("success"),"管理员登录成功!");
            current_name = text_id;//记录下当前的管理员名字
            ui->mode_title->setText("管理员模式:"+text_id);
            ui->user_log_in->setDisabled(true);
            ui->register_button->setDisabled(true);
            ui->manager_log_in->setDisabled(true);
            ui->log_out->setEnabled(true);
            ui->ID_line->setDisabled(true);
            ui->pass_line->setDisabled(true);
            ui->give_cardid_line->setEnabled(true);
            ui->muti_books_in->setEnabled(true);
            ui->card_id->setEnabled(true);
            ui->borrow_book->setEnabled(true);
            user_type = manager;
        }
        else
            QMessageBox::about(0,QObject::tr("fail"),"密码错误");
    }

    ui->pass_line->clear();
    ui->ID_line->clear();
}

/*用户登录模块*/
void MainWindow::on_user_log_in_clicked()
{
    QString text_id = ui->ID_line->text();
    QString pass_id = ui->pass_line->text();

    if(text_id == "" || pass_id == "")
        QMessageBox::about(0,QObject::tr("Fail"),"用户名或密码不能为空!");
    else
    {
        QSqlQuery query;
        query.exec("select password from user where username = '"+text_id+"'");
        QString str;
        while(query.next())
        {
           str = query.value(0).toString();
        }

        if(str.isEmpty()) QMessageBox::about(0,QObject::tr("error"),"no such id!");
        else if(QString::compare(str, pass_id) == 0)
        {
            QMessageBox::about(0,QObject::tr("success"),"用户登录成功!");
            ui->manager_log_in->setDisabled(true);
            ui->register_button->setDisabled(true);
            ui->user_log_in->setDisabled(true);
            ui->log_out->setEnabled(true);
            ui->mode_title->setText("用户模式："+text_id);
            ui->ID_line->setDisabled(true);
            ui->pass_line->setDisabled(true);
            ui->borrow_book->setEnabled(true);//打开借书的选项
            ui->card_id->setEnabled(true);//打开借书卡选项
            user_type = user;
        }
        else
            QMessageBox::about(0,QObject::tr("fail"),"密码错误");
    }

    ui->ID_line->clear();
    ui->pass_line->clear();
}

/*注销模块*/
void MainWindow::on_log_out_clicked()
{
    QMessageBox::about(0,QObject::tr("success"),"退出成功");
    ui->log_out->setDisabled(true);
    ui->register_button->setEnabled(true);
    ui->user_log_in->setEnabled(true);
    ui->manager_log_in->setEnabled(true);
    ui->ID_line->setEnabled(true);
    ui->pass_line->setEnabled(true);
    ui->mode_title->setText("游客模式");
    ui->card_id->clear();
    ui->card_id->setDisabled(true);
    ui->give_cardid_line->setDisabled(true);
    user_type = tourist;
    current_page = 1; //当前页码置为1

    QVector<QString>result_empty(2000,"");//清空当前的table里面的值，因为退出了
    update_table_checkInfo(ui->check_table, result_empty);
    update_table_checkInfo_manager(ui->manager_check_table, result_empty);
    update_table_mutibook(ui->muti_book_table, result_empty);
    update_table(ui->tableWidget, result_flash_table);

    QString page_in = "当前页码 : "+QString::number(current_page)+" / "+QString::number(max_page);
    ui->page_info_line->setText(page_in);
}

/*清空搜索时的输入栏内容*/
void MainWindow::on_make_empty_clicked()
{
    ui->book_name_line->clear();
    ui->author_line->clear();
    ui->press_line->clear();
    ui->price_line_1->clear();
    ui->price_line_2->clear();
    ui->year_line_1->clear();
    ui->year_line_2->clear();
}

/*树状结构被点击的时候*/
void MainWindow::on_treeWidget_clicked(const QModelIndex &index)
{
    QString str = ui->treeWidget->currentItem()->text(0);
    QString record;
    QSqlQuery query;
    QSqlQuery query1;
    result_flash_table.clear();//清空里面的值

    current_book_type = str;//记下所点击的书的类型
    if(order_type == "")
        query.exec("select * from book where type = '"+str+"'");
    else
        query.exec("select * from book where type = '"+str+"'"+order_type);

    while(query.next())
    {
        for(int i = 0; i < 9; i++)
        {
            if(i == 5) continue;
            result_flash_table.push_back(query.value(i).toString());
        }
        record = query.value(0).toString();
        query1.exec("select author_name from book_author where book_id = '"+record+"'");
        while(query1.next())
        {
            record = query1.value(0).toString();
            qDebug()<<record;
            result_flash_table.push_back(record);
        }
    }

    update_table(ui->tableWidget, result_flash_table);
    tree_flag = 1;
    normal_flag = 0; //现在点击的是树状结构查询
}

/*更新我们所要的图书信息*/
void MainWindow::update_table(QTableWidget* tableWidget,QVector<QString> &result)
{
    int row = tableWidget->rowCount();
    int col = tableWidget->columnCount();

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i * col + j + 1 <= ((result.size() - (current_page - 1) * row * (col - 1)) / (col-1) * col))
            {
                if (j == 0)
                    tableWidget->item(i,j)->setCheckState(Qt::Unchecked);
                else if(j != 0)
                    tableWidget->setItem(i,j,new QTableWidgetItem(result[i * (col-1) + j - 1 + (current_page - 1) * row * (col - 1)]));
            }
            else
                tableWidget->setItem(i,j,new QTableWidgetItem(""));
        }
    }
}

/*更新借书查询模块*/
void MainWindow::update_table_checkInfo(QTableWidget* tableWidget,QVector<QString> &result)
{
    int row = tableWidget->rowCount();
    int col = tableWidget->columnCount();

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i * col + j + 1 <= (result.size() / (col-1) * col))
            {
                if (j == 0)
                    tableWidget->item(i,j)->setCheckState(Qt::Unchecked);
                else
                    tableWidget->setItem(i,j,new QTableWidgetItem(result[i*(col-1)+j-1]));
            }
            else
                tableWidget->setItem(i,j,new QTableWidgetItem(""));
        }
    }
}

/*借书功能实现*/
void MainWindow::on_borrow_book_clicked()
{
    if(user_type == tourist)
    {
        QMessageBox::about(0,QObject::tr("fail"),"并没有借书的权限！");
        return;
    }else if(ui->card_id->text().isEmpty())//判断是否有借书证号信息
    {
        QMessageBox::about(0,QObject::tr("fail"),"请先输入借书证号！");
        return;
    }

    QSqlQuery query;
    int row = ui->tableWidget->rowCount();
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy-MM-dd");//当前的时间，用来放到loan表的内容
    QString CardId = ui->card_id->text();//得到用户输入，进到card表中查询
    int SelectFlag = 0;
    int Is_Zero = 0;

    query.exec("select user_name_card from card where card_id = '"+CardId+"'");
    QString str;//存下对应的user_name

    if(CardId == ""){
        QMessageBox::about(0,QObject::tr("fail"),"借书号为空,请输入");
        return;
    }//借书号为空的情况

    while(query.next())
    {
        str = query.value(0).toString();
    }

    if(str.isEmpty()){//没有相应的结果返回
        QMessageBox::about(0,QObject::tr("fail"),"没有对应的借书证号,重新输入");
        ui->card_id->clear();//清除对应的栏中内容
        return;
    }else{
        QMessageBox::about(0,QObject::tr("ok"),"借书卡有效");
        //ui->card_id->clear();
    }

    for(int i = 0; i < row; i++)
    {
        if(ui->tableWidget->item(i, 0)->checkState()){
            SelectFlag = 1;
            if(ui->tableWidget->item(i, 4)->text().toInt() == 0){
                QMessageBox::about(0,QObject::tr("fail"),"该书没有库存，不能借阅");
                Is_Zero = 1;
            }//如果库存为0，不能借阅
            else{
                QString BookId = ui->tableWidget->item(i, 1)->text();
                QSqlQuery query1;//用来查询是否有存在的借书记录
                query.exec("update book set number = number - 1 where book_id = '"+BookId+"'");//更新当前库存量

                query.exec("select cur_number from loan where book_id = '"+BookId+"' and loan_number = '"+CardId+"'");//查询是否借过相同的书
                if(query.size() == 0)//没有记录，那么借书数量为1,并插入当前的记录
                {
                     query1.exec("insert into loan values ('"+str+"', '"+BookId+"', '"+current_date+"', '"+CardId+"', 1)");
                }
                else
                {
                     query1.exec("update loan set cur_number = cur_number + 1 where book_id = '"+BookId+"' and loan_number = '"+CardId+"'");
                }//如果已经有记录了，那么直接借阅数量+1
            }
        }
    }

    if(SelectFlag == 0)
        QMessageBox::about(0,QObject::tr("警告"),"未选择借阅书籍");
    else if(SelectFlag == 1 && Is_Zero == 0)
        QMessageBox::about(0,QObject::tr("成功"),"借阅成功");

    on_check_info_clicked(); //动态更新

    if(user_type == manager)
        on_manager_check_clicked();

    QModelIndex index;
    if(tree_flag == 1 && normal_flag == 0){
        on_treeWidget_clicked(index); //动态更新
    }

    if(tree_flag == 0 && normal_flag == 1){
        on_search_book_clicked(); //复合查询的时候动态更新
    }
}

/*复合查询书籍*/
void MainWindow::on_search_book_clicked()
{
    QVector<QString> list;
    QString book = ui->book_name_line->text();
    QString press = ui->press_line->text();
    QString author = ui->author_line->text();
    QString price1 = ui->price_line_1->text(), year1 = ui->year_line_1->text();
    QString price2 = ui->price_line_2->text(), year2 = ui->year_line_2->text();
    QString ans = "select * from book where ";
    result_flash_table.clear();//对于每次查询，都先清空
    double p1, p2;
    int y1, y2;
    int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;
    p1 = price1.toDouble();     p2 = price2.toDouble();     y1 = year1.toInt();     y2 = year2.toInt();

    //判断是否输入信息
    if(book.isEmpty() && press.isEmpty() && author.isEmpty() && price1.isEmpty() && price2.isEmpty() &&year1.isEmpty() && year2.isEmpty()){
        QMessageBox::about(0,QObject::tr("fail"),"没有有效的查询信息");
        QVector<QString>result_empty(200,"");//清空当前的table里面的值，因为待会儿要更新值进去
        update_table(ui->tableWidget, result_empty);
        return;
    }

    //判断价格范围是否有误
    else if((price1.isEmpty() && !price2.isEmpty()) || (!price1.isEmpty() && price2.isEmpty())){
        QMessageBox::about(0,QObject::tr("fail"),"价格范围有误");
        return;
    }

    //判断价格大小
    else if(p1 > p2 && !price1.isEmpty() && !price2.isEmpty())
    {
        QMessageBox::about(0,QObject::tr("fail"),"价格范围有误");
        return;
    }

    /*判断年份范围是否有误*/
    else if((year1.isEmpty() && !year2.isEmpty()) || (!year1.isEmpty() && year2.isEmpty())){
        QMessageBox::about(0,QObject::tr("fail"),"年份范围有误");
        return;
    }

    /*判断年份大小*/
    else if(y1 > y2 && !year1.isEmpty() && !year2.isEmpty())
    {
        QMessageBox::about(0,QObject::tr("fail"),"年份范围有误");
        return;
    }

    //查询书名
    if(!book.isEmpty()){
        if(!flag2 && !flag3 && !flag4)//判断其他是否有输入，否则SQL语句会出错
            ans = ans + "name = '" + book + "'";
        else
            ans = ans + " and name = '" + book + "'";
        flag1 = 1;//有输入，置1
    }

    //查询出版社
    if(!press.isEmpty()){
        if(!flag1 && !flag3 && !flag4 && !flag5)
            ans = ans + "publisher = '" + press + "'";
        else
            ans = ans + " and publisher = '" + press +"'";
        flag2 = 1;//有输入，置1
    }

    //查询作者，支持模糊查询
    if(!author.isEmpty()){
        QSqlQuery query;
        query.exec("select book_id from book_author where author_name like '%" + author + "%'");
        while(query.next())
        {
            QString str = query.value(0).toString();//记下查到的book_id
            list.push_back(str);//放到list容器当中
        }

        if(list.length() == 0)
            QMessageBox::about(0,QObject::tr("fail"),"不存在该作者");
        else if(list.length() == 1){
            if(!flag1 && !flag2 && !flag4 && !flag5)
                ans = ans + "book_id = '" + list[0] + "'";//长度为1，直接and
            else
                ans = ans + " and book_id = '" + list[0] + "'";
        }
        else {
            for(int i = 0; i < list.length(); i++)
            {
                if(i == 0){
                    if(!flag1 && !flag2 && !flag4)
                        ans = ans + "(book_id = '" + list[0] + "'";
                    else
                        ans = ans + " and (book_id = '" + list[0] + "'";//判断其他栏是否有输入，生成对应的SQL语句
                }
                else if(i != list.length() - 1)
                    ans = ans + " or book_id = '" + list[i] + "'";
                else
                    ans = ans + " or book_id = '" + list[i] + "')";
            }//否则的话，中间用或隔开
        }

        list.clear();
        flag3 = 1;
    }

    //判断价格大小
    if(!price1.isEmpty() && !price2.isEmpty())
    {
         if(!flag1 && !flag2 && !flag3 && !flag5)
             ans = ans + "(price >= "+price1+" and price <= "+price2+")";
         else
             ans = ans + " and (price >= "+price1+" and price <= "+price2+")";
         flag4 = 1;
    }

    /*判断年份大小*/
    if(!year1.isEmpty() && !year2.isEmpty())
    {
         if(!flag1 && !flag2 && !flag3 && !flag4)
             ans = ans + "(publish_year >= "+year1+" and publish_year <= "+year2+")";
         else
             ans = ans + " and (publish_year >= "+year1+" and publish_year <= "+year2+")";
         flag5 = 1;
    }

    if(current_book_type != "")
        ans = ans + " and type = '"+current_book_type+"'";//如果有选中信息的话，我们就将书籍信息给它加上去

    if(order_type != "")
        ans = ans + order_type; //排序属性

    /*根据用户输入，执行对应的SQL语句*/
    QSqlQuery query;
    query.exec(ans);//执行生成的SQL语句

    if(query.size() == 0)//如果没有找到，进行提示没有查询结果
    {
        QMessageBox::about(0,QObject::tr("fail"),"没有查询到对应结果");
        //return;
    }

    while(query.next())//将所有的信息装到list容器里面，再送到屏幕输出
    {
        for(int i = 0; i < 9; i++)
        {
            if(i == 5) continue;
            result_flash_table.push_back(query.value(i).toString());
        }
        QString record = query.value(0).toString();
        QSqlQuery query1;
        query1.exec("select author_name from book_author where book_id = '"+record+"'");
        while(query1.next())
        {
            record = query1.value(0).toString();
            qDebug()<<record;
            result_flash_table.push_back(record);//将作者信息填入
        }
    }

    update_table(ui->tableWidget, result_flash_table);//更新table
    normal_flag = 1;
    tree_flag = 0; //点击的是复合查询
}

/*用户或者管理员对于借书卡借阅情况的查询*/
void MainWindow::on_check_info_clicked()
{
    QVector<QString> result;
    if(user_type == tourist){
        QMessageBox::about(0,QObject::tr("fail"),"游客模式下不能查询");
        return;
    }//如果是游客，不能查询

    if(ui->card_id->text().isEmpty()){
        QMessageBox::about(0,QObject::tr("fail"),"借书证号不能为空");
        return;
    }//需要输入借书证号

    /*获取用户输入的借书证号信息，判断借书证号是否有效*/
    QString CardId = ui->card_id->text();//得到用户输入，进到card表中查询
    QSqlQuery query;//查询语句准备
    QSqlQuery query1;//查询借阅数量
    QSqlQuery query2;//从book表里面获取信息

    query.exec("select user_name_card from card where card_id = '"+CardId+"'");
    QString str;//存下对应的user_name

    if(CardId == ""){
        QMessageBox::about(0,QObject::tr("fail"),"借书号为空,请输入");
        return;
    }//借书号为空的情况

    while(query.next())
    {
        str = query.value(0).toString();
    }

    if(str.isEmpty()){//没有相应的结果返回
        QMessageBox::about(0,QObject::tr("fail"),"没有对应的借书证号,重新输入");
        ui->card_id->clear();//清除对应的栏中内容
        return;
    }else{
        QMessageBox::about(0,QObject::tr("ok"),"借书卡有效");
    }

    query.exec("select book_id from loan where loan_number = '"+CardId+"'");//查询book_id
    if(query.size() == 0){
        QMessageBox::about(0,QObject::tr("fail"),"该借书卡没有借阅情况");
        //return;
    }

    while(query.next())//对于每一条查询的结果
    {
        query1.exec("select cur_number, loan_date from loan where book_id = '"+query.value(0).toString()+"' and loan_number = '"+CardId+"'");
        while(query1.next()){
            result.push_back(query1.value(0).toString());//将查到的借阅数量装到vector里面
            result.push_back(CardId);//将借书证号传进vector里面
            result.push_back(query1.value(1).toString());//将查到的借书时间装到vector里面

            QDateTime Loan_Date = QDateTime::fromString(query1.value(1).toString(), "yyyy-MM-dd");//获取借阅的时间
            QDateTime Return_Date = Loan_Date.addDays(80);//还书时限是80天
            QDateTime current_time = QDateTime::currentDateTime();//获取当前时间
            QString return_date = Return_Date.toString("yyyy-MM-dd");//还书的最后期限

            int remain_days = current_time.daysTo(Return_Date);
            QString Remain = QString::number(remain_days); //获取到剩余的天数

            result.push_back(return_date); //还书时间入vector
            result.push_back(Remain); //剩余天数入vector

            query2.exec("select * from book where book_id = '"+query.value(0).toString()+"'");
            while(query2.next()){
                for(int i = 0; i < 9; i++){
                    if(i == 5) continue;
                    result.push_back(query2.value(i).toString());//将相应信息装入
                }
            }
        }
    }

    update_table_checkInfo(ui->check_table, result);//更新查询界面
}

/*还书的功能实现*/
void MainWindow::on_return_book_clicked()
{
    if(user_type == tourist){
        QMessageBox::about(0,QObject::tr("Wrong"),"游客模式下不能使用还书功能");
        return;
    }

    int row = ui->check_table->rowCount();//得到当前所有的列数
    int select_flag = 0;
    QString BookId;
    QSqlQuery query;
    QString Cardid = ui->card_id->text();

    for(int i = 0; i < row; i++){
        if(ui->check_table->item(i, 0)->checkState()){
            select_flag = 1;
            if(ui->check_table->item(i, 1)->text().toInt() == 1){//如果只借了一本，直接删除loan记录，并且book表中的number + 1
                BookId = ui->check_table->item(i, 6)->text();//获取书号
                query.exec("update book set number = number + 1 where book_id = '"+BookId+"'");//更新book库存
                query.exec("delete from loan where book_id = '"+BookId+"' and loan_number = '"+Cardid+"'");//删除loan表中的记录
            }else{//如果借了多本书，loan表中的借阅数量减1，book库存加一
                BookId = ui->check_table->item(i, 6)->text();
                query.exec("update book set number = number + 1 where book_id = '"+BookId+"'");
                query.exec("update loan set cur_number = cur_number - 1 where book_id = '"+BookId+"' and loan_number = '"+Cardid+"'");
                int cur_num = ui->check_table->item(i, 1)->text().toInt();
                cur_num--;
                ui->check_table->item(i, 1)->setText(QString::number(cur_num)); //动态更新
            }
        }
    }

    //判断是否有书籍被选择
    if(select_flag == 1){
        QMessageBox::about(0,QObject::tr("成功"),"还书成功，请重新查询借阅情况，观察是否还书");
    }
    else
        QMessageBox::about(0,QObject::tr("警告"),"并未选择书籍，还书失败");

    on_check_info_clicked(); //动态更新
    if(user_type == manager)
        on_manager_check_clicked();

    QModelIndex index;
    if(tree_flag == 1 && normal_flag == 0){
        on_treeWidget_clicked(index); //动态更新
    }

    if(tree_flag == 0 && normal_flag == 1){
        on_search_book_clicked(); //复合查询的时候动态更新
    }
}

/*
 *
 * 管理员层业务逻辑
 *
 */

/*管理用户的信息*/
void MainWindow::on_manager_check_clicked()
{
    if(user_type != manager){
        QMessageBox::about(0,QObject::tr("警告"),"非管理员不能操作");
        return;
    }

    QSqlQuery query, query1;
    QVector<QString> result;//最后装入结果的容器中
    query.exec("select * from user");//从用户的表中加载信息

    while(query.next()){//对于每一条查询记录
        result.push_back(query.value(0).toString());//记下用户名
        result.push_back(query.value(1).toString());//记下用户密码

        query1.exec("select card_id from card where user_name_card = '"+query.value(0).toString()+"'");//查卡号
        if(query1.size() == 0)
            result.push_back("NULL");
        else{
            while(query1.next()){
                result.push_back(query1.value(0).toString());
            }
        }

        query1.exec("select sum(cur_number) from loan where username = '"+query.value(0).toString()+"'");//查借阅数量

        if(query1.size() == 0)
            result.push_back("0");
        else{
            while(query1.next()){
                result.push_back(query1.value(0).toString());
            }
        }
    }

    update_table_checkInfo_manager(ui->manager_check_table, result);//更新对应的table
}

/*更新管理员管理界面*/
void MainWindow::update_table_checkInfo_manager(QTableWidget* tableWidget,QVector<QString> &result)
{
    int col = tableWidget->columnCount();
    int row = tableWidget->rowCount();

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(i * col + j + 1 <= result.size() / (col-1) * col){
                if(j == 0)
                    tableWidget->item(i, j)->setCheckState(Qt::Unchecked);
                else
                    tableWidget->setItem(i,j,new QTableWidgetItem(result[i*(col-1)+j-1]));
            }
            else
                tableWidget->setItem(i,j,new QTableWidgetItem(""));
        }
    }
}

/*管理员删除借书卡*/
void MainWindow::on_delete_card_clicked()
{
    if(user_type != manager){
        QMessageBox::about(0,QObject::tr("警告"),"非管理员不能操作");
        return;
    }

    int row = ui->manager_check_table->rowCount();
    int select_flag = 0;//判断是否有用户被选择
    QSqlQuery query;

    for(int i = 0; i < row; i++){
        if(ui->manager_check_table->item(i, 0)->checkState()){
            select_flag = 1;//有被选择的对象
            if(ui->manager_check_table->item(i, 3)->text() == "NULL"){//如果没有借书卡，删除失败
                QMessageBox::about(0,QObject::tr("失败"),"该用户并没有借书卡，删除失败");
            }else{//借书卡存在的情况
                if(ui->manager_check_table->item(i, 4)->text().toInt() != 0){//还有书没还
                    QMessageBox::about(0,QObject::tr("失败"),"该用户尚有书籍未归还，不能删除");
                }else{
                    query.exec("delete from card where user_name_card = '"+ui->manager_check_table->item(i, 1)->text()+"'");
                    QMessageBox::about(0,QObject::tr("成功"),"该借书卡已成功注销");
                    ui->manager_check_table->item(i, 3)->setText("NULL");//动态更新
                }
            }
        }
    }
    if(select_flag == 0)
        QMessageBox::about(0,QObject::tr("警告"),"没有选择相应的用户");
}

/*借书卡号的权限授予*/
void MainWindow::on_give_card_id_button_clicked()
{
    if(user_type != manager){
        QMessageBox::about(0,QObject::tr("警告"),"非管理员不能操作");
        return;
    }

    if(ui->give_cardid_line->text().isEmpty()){
        QMessageBox::about(0,QObject::tr("警告"),"未填写需要授予的借书卡号");
        return;
    }//没有填写借书卡

    int row = ui->manager_check_table->rowCount();
    int selectflag = 0;
    QSqlQuery query;

    for(int i = 0; i < row; i++){
        if(ui->manager_check_table->item(i, 0)->checkState()){
            selectflag = 1;
            /*第一种情况，该用户已经有借书卡了，即card_id != NULL*/

            if(ui->manager_check_table->item(i, 3)->text() != "NULL"){
                QMessageBox::about(0,QObject::tr("失败"),"该用户已经有借书卡，不能重复授予，授予失败");
            }else{//第二种，插入成功的情况
                QString cardid = ui->give_cardid_line->text();
                QString user_name = ui->manager_check_table->item(i, 1)->text();
                query.exec("insert into card values ('"+cardid+"', '"+user_name+"')");
                if(query.isActive()){
                    ui->manager_check_table->item(i, 3)->setText(cardid);
                    QMessageBox::about(0,QObject::tr("成功"),"借书卡权限授予成功！");
                }
                else
                    QMessageBox::about(0,QObject::tr("失败"),"该借书证号已存在");
            }
        }
    }

    if(selectflag == 0)
        QMessageBox::about(0,QObject::tr("警告"),"没有选择相应的用户");
    ui->give_cardid_line->clear();//清除框里面的东西
}

/*单册入库的功能*/
void MainWindow::on_check_in_base_clicked()
{
    if(user_type != manager){
        QMessageBox::about(0,QObject::tr("警告"),"非管理员不能操作");
        return;
    }

    if(ui->book_name_in->text().isEmpty() || ui->press_name_in->text().isEmpty() || ui->press_date_in->text().isEmpty()
    || ui->cur_date_in->text().isEmpty() || ui->book_type_in->text().isEmpty() || ui->price_in->text().isEmpty()
    || ui->book_number_in->text().isEmpty() || ui->author_in->text().isEmpty()){
        QMessageBox::about(0,QObject::tr("警告"),"信息填写不完全，不能入库");
        return;
    }//如果信息不完全的话，不会执行入库的操作
    QString bookname = ui->book_name_in->text(), pressname = ui->press_name_in->text(), pressdate = ui->press_date_in->text();
    QString curdate = ui->cur_date_in->text(), booktype = ui->book_type_in->text(), price = ui->price_in->text();
    QString booknumber = ui->book_number_in->text(), author = ui->author_in->text();//将用户输入的信息全部记下来，都是字符串类型的

    QSqlQuery query; //SQL查询语句
    QSqlQuery query1;
    int merge_flag = 0; //用来判断是否进行合并

    query.exec("select number, book_id from book natural join book_author where name = '"+bookname+"' and publisher = '"
               +pressname+"' and publish_year = "+pressdate+" and author_name = '"+author+"'");//查找是否有重复的语句

    if(!query.isActive()){
        QMessageBox::about(0,QObject::tr("错误"),"存在非法数据输入，入库失败");
        return;
    }//存在非法输入

    if(query.size() == 0)
        merge_flag = 0;
    else merge_flag = 1;//如果查询到，合并标志标记为1

    if(merge_flag == 1){
        int old_number;//旧的数目，记下
        int new_number;//新的数目，计算好

        while(query.next()){
            old_number = query.value(0).toInt();//int型
            new_number = old_number + booknumber.toInt();
            QString New_Number = QString::number(new_number);
            query1.exec("update book set number = "+New_Number+" where book_id = '"+query.value(1).toString()+"'");
            QMessageBox::about(0,QObject::tr("提示"),"有相同书籍，已自动合并");
        }
    } //需要合并的情况
    else{
        QString ans = "insert into book values ";
        QString temp = "insert into book_author values ";
        query1.exec("select count(*) from book");

        while(query1.next()){
            int old_id = query1.value(0).toInt();
            int new_id = old_id + 1;
            ans = ans + "('"+QString::number(new_id)+"', '";//书号，计算得到的
            temp = temp + "('"+QString::number(new_id)+"', '";
        }

        ans = ans + bookname+"', "+price+", "+booknumber+", '"+curdate+"', '"+current_name+"', '"+pressname+"', "+pressdate+", '"+booktype+"')";
        query1.exec(ans);//插入到book表里面去

        if(!query1.isActive()){//存在非法的输入
            QMessageBox::about(0,QObject::tr("错误"),"存在非法数据输入，入库失败");
        }else{
            temp = temp + author +"')";
            query1.exec(temp);//插入到book_author里面去
            QMessageBox::about(0,QObject::tr("成功"),"图书已成功入库");
        }

    }//无需合并的情况

    QModelIndex index;
    if(tree_flag == 1 && normal_flag == 0){
        on_treeWidget_clicked(index); //动态更新
    }

    if(tree_flag == 0 && normal_flag == 1){
        on_search_book_clicked(); //复合查询的时候动态更新
    }
}

/*清空入库栏的信息*/
void MainWindow::on_empty_info_in_clicked()
{
    ui->book_name_in->clear();   ui->press_name_in->clear();
    ui->press_date_in->clear();  ui->cur_date_in->clear();
    ui->book_type_in->clear();   ui->price_in->clear();
    ui->book_number_in->clear(); ui->author_in->clear();
}

/*批量入库*/
void MainWindow::on_muti_books_in_clicked()
{
    if(user_type != manager){
        QMessageBox::about(0,QObject::tr("警告"),"非管理员不能操作");
        return;
    }

    //新建文件显示窗口
    QWidget* fileWindow = new QWidget;
    QFileDialog dlg(fileWindow,"打开文本");
    QVector<QString> result;//存储处理过后的数据
    dlg.resize(400,300);
    dlg.setAcceptMode(QFileDialog::AcceptOpen);

    //只允许打开.txt后缀的文件
    dlg.setNameFilter("*txt");

    //打开文件对话框
    if(dlg.exec()==QDialog::Accepted )
    {
        QStringList files = dlg.selectedFiles();
        if(!files.isEmpty())
        {
            //以只读形式打开选中文件
            QFile file;
            file.setFileName(files.at(0));
            file.open(QIODevice::ReadOnly);
            if(!file.atEnd())
            {
                //读取文本所有信息，并进行转码处理
                QByteArray buff;
                buff = file.readAll();
                QString fileContent(buff);//保存下来所有的信息
                QString temp = "";//初始文本

                for(int k = 0; k <= fileContent.length(); k++)
                {
                    if(k == fileContent.length()){
                        result.push_back(temp);
                        temp = "";
                        break;
                    }

                    if(fileContent.at(k) != '\n' && fileContent.at(k) != '\r')
                    {//换行符回车符直接跳过
                        if(fileContent.at(k) != ' ')
                            temp = temp + fileContent.at(k);
                        else
                        {
                            result.push_back(temp);//将处理得到的每一个字符都传到vector容器当中
                            temp = "";
                        }
                    }else if(fileContent.at(k) != '\r')
                    {
                        result.push_back(temp);
                        temp = "";
                    }
                }
            }
        }
    }

    update_table_mutibook(ui->muti_book_table, result);//更新表单，最后控制表单提交
}

/*更新到表单里面*/
void MainWindow::update_table_mutibook(QTableWidget* tableWidget,QVector<QString> &result)
{
    int row = tableWidget->rowCount();
    int col = tableWidget->columnCount();

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(i * col + j + 1 <= result.size())
                tableWidget->setItem(i,j,new QTableWidgetItem(result[i*col+j]));
            else
                tableWidget->setItem(i,j,new QTableWidgetItem(""));
        }
    }
}

/*清空批量入库的表单*/
void MainWindow::on_make_muti_empty_clicked()
{
    if(user_type != manager){
        QMessageBox::about(0,QObject::tr("警告"),"非管理员不能操作");
        return;
    }

    QVector<QString> make_empty(2000, "");
    update_table_mutibook(ui->muti_book_table, make_empty);
}

/*提交表单，插入到数据库当中去*/
void MainWindow::on_submit_muti_clicked()
{
    if(user_type != manager){
        QMessageBox::about(0,QObject::tr("警告"),"非管理员不能操作");
        return;
    }//非管理员，不能进行操作

    /*计算总共有多少本书*/
    int book_number = 0;
    int row = ui->muti_book_table->rowCount();//得到总的行数
    int merge_flag = 0;//判断是否需要合并的标志
    QSqlQuery query, query1;

    /*计算总的不同需要入库的书籍*/
    for(int i = 0; i < row; i++)
    {
        if(ui->muti_book_table->item(i, 0)->text() == "")
            break;
        else
            book_number++;//得到总共需要入库的书籍
    }

    /*对每一本需要入库的书都进行相对应的判断*/
    for(int j = 0; j < book_number; j++)//对于每一本书的操作
    {
        QString bookname = ui->muti_book_table->item(j, 1)->text(); QString pressname = ui->muti_book_table->item(j, 2)->text();
        QString pressdate = ui->muti_book_table->item(j, 3)->text(), author = ui->muti_book_table->item(j, 4)->text();
        QString price = ui->muti_book_table->item(j, 5)->text(), booknumber = ui->muti_book_table->item(j, 6)->text();
        QString booktype = ui->muti_book_table->item(j, 0)->text();
        query.exec("select number, book_id from book natural join book_author where name = '"+bookname+"' and publisher = '"
                   +pressname+"' and publish_year = "+pressdate+" and author_name = '"+author+"'");//查找是否有重复的语句

        if(query.size() == 0)
            merge_flag = 0;//无结果不合并
        else
            merge_flag = 1;//存在结果，合并

        if(merge_flag == 1){
            int old_number;//旧的数目，记下
            int new_number;//新的数目，计算好
            while(query.next()){
                old_number = query.value(0).toInt();//int型
                new_number = old_number + booknumber.toInt();
                QString New_Number = QString::number(new_number);
                query1.exec("update book set number = "+New_Number+" where book_id = '"+query.value(1).toString()+"'");
                QMessageBox::about(0,QObject::tr("提示"),"有相同书籍，已自动合并\n"+bookname+" "+pressname+" "+author+" ");
            }
        } //需要合并的情况
        else//无需合并的情况
        {
            QString ans = "insert into book values ";
            QString temp = "insert into book_author values ";
            query1.exec("select count(*) from book");

            while(query1.next()){
                int old_id = query1.value(0).toInt();
                int new_id = old_id + 1;
                ans = ans + "('" + QString::number(new_id) + "', '";//书号，计算得到的
                temp = temp + "('" + QString::number(new_id) + "', '";
            }

            QDateTime current_date_time = QDateTime::currentDateTime();
            QString current_date = current_date_time.toString("yyyy-MM-dd");//计算得到当前时间，即入库时间

            ans = ans + bookname + "', " + price + ", " + booknumber + ", '" + current_date + "', '"
                    + current_name + "', '" + pressname + "', " + pressdate + ", '" + booktype + "')"; //生成对应SQL语句
            query1.exec(ans);//插入到book表里面去

            if(!query1.isActive()){//存在非法的输入
                QMessageBox::about(0,QObject::tr("错误"),"存在非法数据输入，入库失败");
            }else{
                temp = temp + author +"')";
                query1.exec(temp);//插入到book_author里面去
            }
        }
    }

    QMessageBox::about(0,QObject::tr("成功"),"批量入库成功完成");
    QModelIndex index;
    if(tree_flag == 1 && normal_flag == 0){
        on_treeWidget_clicked(index); //动态更新
    }

    if(tree_flag == 0 && normal_flag == 1){
        on_search_book_clicked(); //复合查询的时候动态更新
    }
}

/*排序属性树被点击的时候*/
void MainWindow::on_order_tree_clicked(const QModelIndex &index)
{
    QString str = ui->order_tree->currentItem()->text(0); //点击的属性
    if(str == "书号"){
        order_type = " order by book_id";
    }else if(str == "书名"){
        order_type = " order by name";
    }else if(str == "价格"){
        order_type = " order by price";
    }else if(str == "库存"){
        order_type = " order by number";
    }else if(str == "出版年份"){
        order_type = " order by publish_year";
    }else if(str == "出版社"){
        order_type = " order by publisher";
    }else{
        order_type = "";
    }

    if(tree_flag == 1 && normal_flag == 0){
        on_treeWidget_clicked(index); //动态更新
    }

    if(tree_flag == 0 && normal_flag == 1){
        on_search_book_clicked(); //复合查询的时候动态更新
    }
}

/*点击下一页的机制*/
void MainWindow::on_next_page_clicked()
{
    if(current_page < max_page) //未到达最大页码
    {
        current_page++;
        update_table(ui->tableWidget, result_flash_table);
    }

    QString page_in = "当前页码 : "+QString::number(current_page)+" / "+QString::number(max_page);
    ui->page_info_line->setText(page_in);
}

/*点击上一页的机制*/
void MainWindow::on_last_page_clicked()
{
    if(current_page > 1) //未到达最小页码1
    {
        current_page--;
        update_table(ui->tableWidget, result_flash_table);
    }

    QString page_in = "当前页码 : "+QString::number(current_page)+" / "+QString::number(max_page);
    ui->page_info_line->setText(page_in);
}
