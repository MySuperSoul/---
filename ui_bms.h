/********************************************************************************
** Form generated from reading UI file 'bms.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BMS_H
#define UI_BMS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTabWidget *tabWidget;
    QWidget *SearchWindow;
    QTreeWidget *treeWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_17;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit_18;
    QSpacerItem *verticalSpacer_2;
    QLineEdit *lineEdit_19;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_3;
    QTableWidget *tableWidget;
    QPushButton *search_button;
    QPushButton *clear_button;
    QPushButton *borrow_button;
    QWidget *ReturnWindow;
    QTableWidget *tableWidget_4;
    QPushButton *return_button;
    QPushButton *check_button;
    QWidget *InsertWindow;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_16;
    QLineEdit *nameEdit;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLineEdit *isbnEdit;
    QLineEdit *typeEdit;
    QLineEdit *yearEdit;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QSpacerItem *verticalSpacer_7;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_2;
    QLabel *label_20;
    QLineEdit *authorEdit;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLineEdit *publisherEdit;
    QLineEdit *numberEdit;
    QLineEdit *priceEdit;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_9;
    QSpacerItem *verticalSpacer_10;
    QPushButton *insert_Button;
    QWidget *Title;
    QGraphicsView *titleImage;
    QLineEdit *login_userid;
    QLineEdit *login_password;
    QLabel *dataText;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *login_button;
    QPushButton *log_out;
    QLabel *label_6;
    QLabel *usertype_edit_label;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(763, 589);
        tabWidget = new QTabWidget(Widget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 110, 741, 471));
        SearchWindow = new QWidget();
        SearchWindow->setObjectName(QStringLiteral("SearchWindow"));
        treeWidget = new QTreeWidget(SearchWindow);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        new QTreeWidgetItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setGeometry(QRect(20, 10, 201, 421));
        verticalLayoutWidget = new QWidget(SearchWindow);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(310, 10, 51, 121));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_17 = new QLineEdit(verticalLayoutWidget);
        lineEdit_17->setObjectName(QStringLiteral("lineEdit_17"));

        verticalLayout->addWidget(lineEdit_17);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        lineEdit_18 = new QLineEdit(verticalLayoutWidget);
        lineEdit_18->setObjectName(QStringLiteral("lineEdit_18"));

        verticalLayout->addWidget(lineEdit_18);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        lineEdit_19 = new QLineEdit(verticalLayoutWidget);
        lineEdit_19->setObjectName(QStringLiteral("lineEdit_19"));

        verticalLayout->addWidget(lineEdit_19);

        verticalLayoutWidget_2 = new QWidget(SearchWindow);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(240, 10, 41, 121));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        label_2 = new QLabel(verticalLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        label_3 = new QLabel(verticalLayoutWidget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        tableWidget = new QTableWidget(SearchWindow);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QFont font;
        font.setUnderline(true);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setFont(font);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setFont(font1);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setFont(font1);
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setFont(font1);
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        __qtablewidgetitem4->setFont(font1);
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        __qtablewidgetitem5->setFont(font1);
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        __qtablewidgetitem6->setFont(font1);
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        __qtablewidgetitem7->setFont(font1);
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (tableWidget->rowCount() < 9)
            tableWidget->setRowCount(9);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        __qtablewidgetitem8->setFont(font1);
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        __qtablewidgetitem9->setFont(font1);
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        __qtablewidgetitem10->setFont(font1);
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setFont(font1);
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setFont(font1);
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font1);
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        __qtablewidgetitem14->setFont(font1);
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        __qtablewidgetitem15->setFont(font1);
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setFont(font1);
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setCheckState(Qt::Unchecked);
        __qtablewidgetitem17->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget->setItem(0, 0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        __qtablewidgetitem18->setCheckState(Qt::Unchecked);
        tableWidget->setItem(1, 0, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setCheckState(Qt::Unchecked);
        tableWidget->setItem(2, 0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        __qtablewidgetitem20->setCheckState(Qt::Unchecked);
        tableWidget->setItem(3, 0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        __qtablewidgetitem21->setCheckState(Qt::Unchecked);
        tableWidget->setItem(4, 0, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        __qtablewidgetitem22->setCheckState(Qt::Unchecked);
        tableWidget->setItem(5, 0, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        __qtablewidgetitem23->setCheckState(Qt::Unchecked);
        tableWidget->setItem(6, 0, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        __qtablewidgetitem24->setCheckState(Qt::Unchecked);
        tableWidget->setItem(7, 0, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        __qtablewidgetitem25->setCheckState(Qt::Unchecked);
        tableWidget->setItem(8, 0, __qtablewidgetitem25);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setEnabled(true);
        tableWidget->setGeometry(QRect(260, 140, 461, 291));
        tableWidget->setCornerButtonEnabled(true);
        search_button = new QPushButton(SearchWindow);
        search_button->setObjectName(QStringLiteral("search_button"));
        search_button->setGeometry(QRect(450, 30, 75, 23));
        clear_button = new QPushButton(SearchWindow);
        clear_button->setObjectName(QStringLiteral("clear_button"));
        clear_button->setGeometry(QRect(590, 30, 75, 23));
        borrow_button = new QPushButton(SearchWindow);
        borrow_button->setObjectName(QStringLiteral("borrow_button"));
        borrow_button->setGeometry(QRect(450, 80, 75, 23));
        tabWidget->addTab(SearchWindow, QString());
        ReturnWindow = new QWidget();
        ReturnWindow->setObjectName(QStringLiteral("ReturnWindow"));
        tableWidget_4 = new QTableWidget(ReturnWindow);
        if (tableWidget_4->columnCount() < 6)
            tableWidget_4->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(0, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(1, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(2, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(3, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(4, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_4->setHorizontalHeaderItem(5, __qtablewidgetitem31);
        if (tableWidget_4->rowCount() < 5)
            tableWidget_4->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        __qtablewidgetitem32->setFont(font1);
        tableWidget_4->setVerticalHeaderItem(0, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        __qtablewidgetitem33->setFont(font1);
        tableWidget_4->setVerticalHeaderItem(1, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        __qtablewidgetitem34->setFont(font1);
        tableWidget_4->setVerticalHeaderItem(2, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        __qtablewidgetitem35->setFont(font1);
        tableWidget_4->setVerticalHeaderItem(3, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        __qtablewidgetitem36->setFont(font1);
        tableWidget_4->setVerticalHeaderItem(4, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        __qtablewidgetitem37->setCheckState(Qt::Unchecked);
        __qtablewidgetitem37->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_4->setItem(0, 0, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setCheckState(Qt::Unchecked);
        __qtablewidgetitem38->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_4->setItem(1, 0, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        __qtablewidgetitem39->setCheckState(Qt::Unchecked);
        __qtablewidgetitem39->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_4->setItem(2, 0, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        __qtablewidgetitem40->setCheckState(Qt::Unchecked);
        __qtablewidgetitem40->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_4->setItem(3, 0, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        __qtablewidgetitem41->setCheckState(Qt::Unchecked);
        __qtablewidgetitem41->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        tableWidget_4->setItem(4, 0, __qtablewidgetitem41);
        tableWidget_4->setObjectName(QStringLiteral("tableWidget_4"));
        tableWidget_4->setGeometry(QRect(10, 10, 681, 191));
        return_button = new QPushButton(ReturnWindow);
        return_button->setObjectName(QStringLiteral("return_button"));
        return_button->setGeometry(QRect(310, 260, 75, 23));
        check_button = new QPushButton(ReturnWindow);
        check_button->setObjectName(QStringLiteral("check_button"));
        check_button->setGeometry(QRect(160, 260, 75, 23));
        tabWidget->addTab(ReturnWindow, QString());
        InsertWindow = new QWidget();
        InsertWindow->setObjectName(QStringLiteral("InsertWindow"));
        formLayoutWidget = new QWidget(InsertWindow);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(110, 80, 141, 251));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(formLayoutWidget);
        label_16->setObjectName(QStringLiteral("label_16"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_16);

        nameEdit = new QLineEdit(formLayoutWidget);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);

        label_17 = new QLabel(formLayoutWidget);
        label_17->setObjectName(QStringLiteral("label_17"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_17);

        label_18 = new QLabel(formLayoutWidget);
        label_18->setObjectName(QStringLiteral("label_18"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_18);

        label_19 = new QLabel(formLayoutWidget);
        label_19->setObjectName(QStringLiteral("label_19"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_19);

        isbnEdit = new QLineEdit(formLayoutWidget);
        isbnEdit->setObjectName(QStringLiteral("isbnEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, isbnEdit);

        typeEdit = new QLineEdit(formLayoutWidget);
        typeEdit->setObjectName(QStringLiteral("typeEdit"));

        formLayout->setWidget(4, QFormLayout::FieldRole, typeEdit);

        yearEdit = new QLineEdit(formLayoutWidget);
        yearEdit->setObjectName(QStringLiteral("yearEdit"));

        formLayout->setWidget(6, QFormLayout::FieldRole, yearEdit);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::LabelRole, verticalSpacer_5);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(3, QFormLayout::LabelRole, verticalSpacer_6);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(5, QFormLayout::LabelRole, verticalSpacer_7);

        formLayoutWidget_2 = new QWidget(InsertWindow);
        formLayoutWidget_2->setObjectName(QStringLiteral("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(280, 80, 141, 251));
        formLayout_2 = new QFormLayout(formLayoutWidget_2);
        formLayout_2->setSpacing(6);
        formLayout_2->setContentsMargins(11, 11, 11, 11);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_20 = new QLabel(formLayoutWidget_2);
        label_20->setObjectName(QStringLiteral("label_20"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_20);

        authorEdit = new QLineEdit(formLayoutWidget_2);
        authorEdit->setObjectName(QStringLiteral("authorEdit"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, authorEdit);

        label_21 = new QLabel(formLayoutWidget_2);
        label_21->setObjectName(QStringLiteral("label_21"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_21);

        label_22 = new QLabel(formLayoutWidget_2);
        label_22->setObjectName(QStringLiteral("label_22"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_22);

        label_23 = new QLabel(formLayoutWidget_2);
        label_23->setObjectName(QStringLiteral("label_23"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_23);

        publisherEdit = new QLineEdit(formLayoutWidget_2);
        publisherEdit->setObjectName(QStringLiteral("publisherEdit"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, publisherEdit);

        numberEdit = new QLineEdit(formLayoutWidget_2);
        numberEdit->setObjectName(QStringLiteral("numberEdit"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, numberEdit);

        priceEdit = new QLineEdit(formLayoutWidget_2);
        priceEdit->setObjectName(QStringLiteral("priceEdit"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, priceEdit);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(1, QFormLayout::LabelRole, verticalSpacer_8);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(3, QFormLayout::LabelRole, verticalSpacer_9);

        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout_2->setItem(5, QFormLayout::LabelRole, verticalSpacer_10);

        insert_Button = new QPushButton(InsertWindow);
        insert_Button->setObjectName(QStringLiteral("insert_Button"));
        insert_Button->setGeometry(QRect(240, 370, 75, 23));
        tabWidget->addTab(InsertWindow, QString());
        Title = new QWidget(Widget);
        Title->setObjectName(QStringLiteral("Title"));
        Title->setGeometry(QRect(9, 19, 741, 81));
        titleImage = new QGraphicsView(Title);
        titleImage->setObjectName(QStringLiteral("titleImage"));
        titleImage->setGeometry(QRect(5, 1, 731, 81));
        titleImage->setStyleSheet(QStringLiteral("border-image:url(:/new/image/6.png)"));
        login_userid = new QLineEdit(Title);
        login_userid->setObjectName(QStringLiteral("login_userid"));
        login_userid->setGeometry(QRect(590, 30, 113, 20));
        login_password = new QLineEdit(Title);
        login_password->setObjectName(QStringLiteral("login_password"));
        login_password->setGeometry(QRect(590, 60, 113, 20));
        dataText = new QLabel(Title);
        dataText->setObjectName(QStringLiteral("dataText"));
        dataText->setGeometry(QRect(30, 20, 91, 41));
        label_4 = new QLabel(Title);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(530, 30, 54, 12));
        label_5 = new QLabel(Title);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(530, 60, 54, 12));
        login_button = new QPushButton(Widget);
        login_button->setObjectName(QStringLiteral("login_button"));
        login_button->setGeometry(QRect(470, 100, 75, 23));
        log_out = new QPushButton(Widget);
        log_out->setObjectName(QStringLiteral("log_out"));
        log_out->setGeometry(QRect(600, 100, 75, 23));
        label_6 = new QLabel(Widget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(293, 100, 71, 20));
        usertype_edit_label = new QLabel(Widget);
        usertype_edit_label->setObjectName(QStringLiteral("usertype_edit_label"));
        usertype_edit_label->setGeometry(QRect(360, 100, 91, 21));

        retranslateUi(Widget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        tabWidget->setToolTip(QApplication::translate("Widget", "<html><head/><body><p>type search</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("Widget", "alltype", Q_NULLPTR));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("Widget", "type", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("Widget", "physics", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("Widget", "cs", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QApplication::translate("Widget", "literature", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem1->child(3);
        ___qtreewidgetitem5->setText(0, QApplication::translate("Widget", "math", Q_NULLPTR));
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem1->child(4);
        ___qtreewidgetitem6->setText(0, QApplication::translate("Widget", "other", Q_NULLPTR));
        treeWidget->setSortingEnabled(__sortingEnabled);

        label->setText(QApplication::translate("Widget", "name", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "isbn", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "author", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem->setText(QApplication::translate("Widget", "isbn", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem1->setText(QApplication::translate("Widget", "name", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem2->setText(QApplication::translate("Widget", "author", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem3->setText(QApplication::translate("Widget", "type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem4->setText(QApplication::translate("Widget", "storage", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem5->setText(QApplication::translate("Widget", "price", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem6->setText(QApplication::translate("Widget", "publisher", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("Widget", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("Widget", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("Widget", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("Widget", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("Widget", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem12->setText(QApplication::translate("Widget", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem13->setText(QApplication::translate("Widget", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem14->setText(QApplication::translate("Widget", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem15->setText(QApplication::translate("Widget", "9", Q_NULLPTR));

        const bool __sortingEnabled1 = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled1);

        search_button->setText(QApplication::translate("Widget", "search", Q_NULLPTR));
        clear_button->setText(QApplication::translate("Widget", "clear", Q_NULLPTR));
        borrow_button->setText(QApplication::translate("Widget", "borrow", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(SearchWindow), QApplication::translate("Widget", "Search", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_4->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QApplication::translate("Widget", "user_id", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_4->horizontalHeaderItem(2);
        ___qtablewidgetitem17->setText(QApplication::translate("Widget", "isbn", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_4->horizontalHeaderItem(3);
        ___qtablewidgetitem18->setText(QApplication::translate("Widget", "Bookname", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_4->horizontalHeaderItem(4);
        ___qtablewidgetitem19->setText(QApplication::translate("Widget", "BorrowDate", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_4->horizontalHeaderItem(5);
        ___qtablewidgetitem20->setText(QApplication::translate("Widget", "IsReturned", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_4->verticalHeaderItem(0);
        ___qtablewidgetitem21->setText(QApplication::translate("Widget", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_4->verticalHeaderItem(1);
        ___qtablewidgetitem22->setText(QApplication::translate("Widget", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_4->verticalHeaderItem(2);
        ___qtablewidgetitem23->setText(QApplication::translate("Widget", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_4->verticalHeaderItem(3);
        ___qtablewidgetitem24->setText(QApplication::translate("Widget", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_4->verticalHeaderItem(4);
        ___qtablewidgetitem25->setText(QApplication::translate("Widget", "5", Q_NULLPTR));

        const bool __sortingEnabled2 = tableWidget_4->isSortingEnabled();
        tableWidget_4->setSortingEnabled(false);
        tableWidget_4->setSortingEnabled(__sortingEnabled2);

        return_button->setText(QApplication::translate("Widget", "return", Q_NULLPTR));
        check_button->setText(QApplication::translate("Widget", "check", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(ReturnWindow), QApplication::translate("Widget", "Record", Q_NULLPTR));
        label_16->setText(QApplication::translate("Widget", "name", Q_NULLPTR));
        label_17->setText(QApplication::translate("Widget", "isbn", Q_NULLPTR));
        label_18->setText(QApplication::translate("Widget", "type", Q_NULLPTR));
        label_19->setText(QApplication::translate("Widget", "year", Q_NULLPTR));
        label_20->setText(QApplication::translate("Widget", "author", Q_NULLPTR));
        label_21->setText(QApplication::translate("Widget", "publisher", Q_NULLPTR));
        label_22->setText(QApplication::translate("Widget", "number", Q_NULLPTR));
        label_23->setText(QApplication::translate("Widget", "price", Q_NULLPTR));
        insert_Button->setText(QApplication::translate("Widget", "insert", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(InsertWindow), QApplication::translate("Widget", "Insert", Q_NULLPTR));
        dataText->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
        label_4->setText(QApplication::translate("Widget", "     id:", Q_NULLPTR));
        label_5->setText(QApplication::translate("Widget", "password:", Q_NULLPTR));
        login_button->setText(QApplication::translate("Widget", "login", Q_NULLPTR));
        log_out->setText(QApplication::translate("Widget", "log out", Q_NULLPTR));
        label_6->setText(QApplication::translate("Widget", "user type:", Q_NULLPTR));
        usertype_edit_label->setText(QApplication::translate("Widget", "TextLabel", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BMS_H
