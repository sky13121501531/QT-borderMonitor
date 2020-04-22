/********************************************************************************
** Form generated from reading UI file 'uidemo01.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UIDEMO01_H
#define UI_UIDEMO01_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UIDemo01
{
public:
    QGridLayout *gridLayout_6;
    QHBoxLayout *horizontalLayout_7;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labIco;
    QLabel *labTitle;
    QWidget *widgetTop;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_6;
    QToolButton *btnMain;
    QSpacerItem *horizontalSpacer_5;
    QToolButton *btnConfig;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *btnData;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *btnHelp;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *btnExit;
    QSpacerItem *horizontalSpacer;
    QWidget *widgetMenu;
    QGridLayout *gridLayout_2;
    QPushButton *btnMenu_Min;
    QPushButton *btnMenu_Close;
    QPushButton *btnMenu_Max;
    QSpacerItem *verticalSpacer;
    QStackedWidget *stackedWidget;
    QWidget *page1;
    QGridLayout *gridLayout_5;
    QSplitter *splitter;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_11;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_8;
    QPushButton *pushButton_add;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushButton_5;
    QSpacerItem *horizontalSpacer_10;
    QSpacerItem *verticalSpacer_3;
    QTableView *TableViewNew;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_10;
    QPushButton *pushButton_ChannelSet;
    QSpacerItem *verticalSpacer_8;
    QPushButton *pushButton_2;
    QSpacerItem *verticalSpacer_9;
    QPushButton *pushButton_channelscan;
    QSpacerItem *verticalSpacer_13;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_11;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QComboBox *comboBox_TV_IP;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QComboBox *comboBox_TV_FREQ;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QComboBox *comboBox_TV_CHANNEL;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *lineEdit_TV_SERNAME;
    QSpacerItem *verticalSpacer_12;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QHBoxLayout *horizontalLayout_10;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_6;
    QWidget *widget_VLCPlayer;
    QTableView *tableView_PROLIST;
    QWidget *page2;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QSpacerItem *horizontalSpacer_13;
    QSpacerItem *horizontalSpacer_12;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_17;
    QCommandLinkButton *commandLinkButton;
    QLabel *lab_ReadConfig;
    QSpacerItem *horizontalSpacer_15;
    QTableView *tableView_SysConfig;
    QVBoxLayout *verticalLayout_8;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_skinblack;
    QCheckBox *checkBox_black;
    QSpacerItem *verticalSpacer_15;
    QVBoxLayout *verticalLayout_9;
    QSpacerItem *verticalSpacer_16;
    QLabel *label_skinwhite;
    QCheckBox *checkBox_white;
    QSpacerItem *verticalSpacer_18;
    QSpacerItem *horizontalSpacer_16;
    QSpacerItem *horizontalSpacer_14;
    QLabel *label_4;
    QWidget *page3;
    QLabel *lab3;
    QWidget *page4;
    QVBoxLayout *verticalLayout_4;
    QLabel *lab4;

    void setupUi(QDialog *UIDemo01)
    {
        if (UIDemo01->objectName().isEmpty())
            UIDemo01->setObjectName(QString::fromUtf8("UIDemo01"));
        UIDemo01->resize(923, 493);
        UIDemo01->setSizeGripEnabled(true);
        gridLayout_6 = new QGridLayout(UIDemo01);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));

        gridLayout_6->addLayout(horizontalLayout_7, 0, 0, 1, 1);

        widgetTitle = new QWidget(UIDemo01);
        widgetTitle->setObjectName(QString::fromUtf8("widgetTitle"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widgetTitle->sizePolicy().hasHeightForWidth());
        widgetTitle->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(widgetTitle);
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(10, 0, 0, 0);
        labIco = new QLabel(widgetTitle);
        labIco->setObjectName(QString::fromUtf8("labIco"));
        labIco->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(labIco);

        labTitle = new QLabel(widgetTitle);
        labTitle->setObjectName(QString::fromUtf8("labTitle"));
        labTitle->setStyleSheet(QString::fromUtf8(""));
        labTitle->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labTitle);

        widgetTop = new QWidget(widgetTitle);
        widgetTop->setObjectName(QString::fromUtf8("widgetTop"));
        horizontalLayout_3 = new QHBoxLayout(widgetTop);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        btnMain = new QToolButton(widgetTop);
        btnMain->setObjectName(QString::fromUtf8("btnMain"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btnMain->sizePolicy().hasHeightForWidth());
        btnMain->setSizePolicy(sizePolicy1);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/main_main.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnMain->setIcon(icon);
        btnMain->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnMain);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_5);

        btnConfig = new QToolButton(widgetTop);
        btnConfig->setObjectName(QString::fromUtf8("btnConfig"));
        sizePolicy1.setHeightForWidth(btnConfig->sizePolicy().hasHeightForWidth());
        btnConfig->setSizePolicy(sizePolicy1);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/image/main_config.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnConfig->setIcon(icon1);
        btnConfig->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnConfig);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        btnData = new QToolButton(widgetTop);
        btnData->setObjectName(QString::fromUtf8("btnData"));
        sizePolicy1.setHeightForWidth(btnData->sizePolicy().hasHeightForWidth());
        btnData->setSizePolicy(sizePolicy1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/image/main_data.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnData->setIcon(icon2);
        btnData->setChecked(false);
        btnData->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnData);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        btnHelp = new QToolButton(widgetTop);
        btnHelp->setObjectName(QString::fromUtf8("btnHelp"));
        sizePolicy1.setHeightForWidth(btnHelp->sizePolicy().hasHeightForWidth());
        btnHelp->setSizePolicy(sizePolicy1);
        btnHelp->setStyleSheet(QString::fromUtf8(""));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/image/main_person.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnHelp->setIcon(icon3);
        btnHelp->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnHelp);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        btnExit = new QToolButton(widgetTop);
        btnExit->setObjectName(QString::fromUtf8("btnExit"));
        sizePolicy1.setHeightForWidth(btnExit->sizePolicy().hasHeightForWidth());
        btnExit->setSizePolicy(sizePolicy1);
        btnExit->setStyleSheet(QString::fromUtf8(""));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/image/main_exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnExit->setIcon(icon4);
        btnExit->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);

        horizontalLayout_3->addWidget(btnExit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);


        horizontalLayout_2->addWidget(widgetTop);

        widgetMenu = new QWidget(widgetTitle);
        widgetMenu->setObjectName(QString::fromUtf8("widgetMenu"));
        gridLayout_2 = new QGridLayout(widgetMenu);
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        btnMenu_Min = new QPushButton(widgetMenu);
        btnMenu_Min->setObjectName(QString::fromUtf8("btnMenu_Min"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btnMenu_Min->sizePolicy().hasHeightForWidth());
        btnMenu_Min->setSizePolicy(sizePolicy2);
        btnMenu_Min->setMinimumSize(QSize(30, 30));
        btnMenu_Min->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Min->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Min, 0, 1, 1, 1);

        btnMenu_Close = new QPushButton(widgetMenu);
        btnMenu_Close->setObjectName(QString::fromUtf8("btnMenu_Close"));
        sizePolicy2.setHeightForWidth(btnMenu_Close->sizePolicy().hasHeightForWidth());
        btnMenu_Close->setSizePolicy(sizePolicy2);
        btnMenu_Close->setMinimumSize(QSize(30, 30));
        btnMenu_Close->setCursor(QCursor(Qt::ArrowCursor));
        btnMenu_Close->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Close, 0, 3, 1, 1);

        btnMenu_Max = new QPushButton(widgetMenu);
        btnMenu_Max->setObjectName(QString::fromUtf8("btnMenu_Max"));
        sizePolicy2.setHeightForWidth(btnMenu_Max->sizePolicy().hasHeightForWidth());
        btnMenu_Max->setSizePolicy(sizePolicy2);
        btnMenu_Max->setMinimumSize(QSize(30, 30));
        btnMenu_Max->setFocusPolicy(Qt::NoFocus);

        gridLayout_2->addWidget(btnMenu_Max, 0, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 1, 1, 3);


        horizontalLayout_2->addWidget(widgetMenu);


        gridLayout_6->addWidget(widgetTitle, 1, 0, 1, 1);

        stackedWidget = new QStackedWidget(UIDemo01);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setStyleSheet(QString::fromUtf8(""));
        page1 = new QWidget();
        page1->setObjectName(QString::fromUtf8("page1"));
        gridLayout_5 = new QGridLayout(page1);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        splitter = new QSplitter(page1);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setElideMode(Qt::ElideNone);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_11 = new QSpacerItem(127, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_11, 0, 1, 1, 1);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_8);

        pushButton_add = new QPushButton(tab);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/qss/psblack/branch_open.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_add->setIcon(icon5);

        horizontalLayout_8->addWidget(pushButton_add);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);

        pushButton_5 = new QPushButton(tab);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/qss/psblack/branch_close.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon6);

        horizontalLayout_8->addWidget(pushButton_5);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);


        verticalLayout_2->addLayout(horizontalLayout_8);


        verticalLayout_7->addLayout(verticalLayout_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_3);

        TableViewNew = new QTableView(tab);
        TableViewNew->setObjectName(QString::fromUtf8("TableViewNew"));

        verticalLayout_7->addWidget(TableViewNew);


        gridLayout->addLayout(verticalLayout_7, 2, 0, 1, 3);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 1, 0, 1, 1);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_10 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_10);

        pushButton_ChannelSet = new QPushButton(tab);
        pushButton_ChannelSet->setObjectName(QString::fromUtf8("pushButton_ChannelSet"));
        pushButton_ChannelSet->setMinimumSize(QSize(45, 45));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/image/ChannelSet.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_ChannelSet->setIcon(icon7);

        verticalLayout_6->addWidget(pushButton_ChannelSet);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_8);

        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setMinimumSize(QSize(45, 45));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/image/TimeSet.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon8);
        pushButton_2->setAutoRepeatInterval(100);

        verticalLayout_6->addWidget(pushButton_2);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_9);

        pushButton_channelscan = new QPushButton(tab);
        pushButton_channelscan->setObjectName(QString::fromUtf8("pushButton_channelscan"));
        pushButton_channelscan->setMinimumSize(QSize(45, 45));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/image/ChannelScan.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_channelscan->setIcon(icon9);
        pushButton_channelscan->setIconSize(QSize(16, 16));

        verticalLayout_6->addWidget(pushButton_channelscan);

        verticalSpacer_13 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_13);


        gridLayout->addLayout(verticalLayout_6, 0, 2, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer_11 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_11);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\245\267\344\275\223\";"));

        horizontalLayout_4->addWidget(label_2);

        comboBox_TV_IP = new QComboBox(tab);
        comboBox_TV_IP->setObjectName(QString::fromUtf8("comboBox_TV_IP"));

        horizontalLayout_4->addWidget(comboBox_TV_IP);

        horizontalLayout_4->setStretch(0, 3);
        horizontalLayout_4->setStretch(1, 7);

        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_5);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\245\267\344\275\223\";"));

        horizontalLayout->addWidget(label_3);

        comboBox_TV_FREQ = new QComboBox(tab);
        comboBox_TV_FREQ->setObjectName(QString::fromUtf8("comboBox_TV_FREQ"));

        horizontalLayout->addWidget(comboBox_TV_FREQ);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_6);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(9);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\245\267\344\275\223\";"));

        horizontalLayout_6->addWidget(label_5);

        comboBox_TV_CHANNEL = new QComboBox(tab);
        comboBox_TV_CHANNEL->setObjectName(QString::fromUtf8("comboBox_TV_CHANNEL"));

        horizontalLayout_6->addWidget(comboBox_TV_CHANNEL);


        verticalLayout->addLayout(horizontalLayout_6);

        verticalSpacer_7 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_7);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 9pt \"\346\245\267\344\275\223\";"));

        horizontalLayout_5->addWidget(label);

        lineEdit_TV_SERNAME = new QLineEdit(tab);
        lineEdit_TV_SERNAME->setObjectName(QString::fromUtf8("lineEdit_TV_SERNAME"));

        horizontalLayout_5->addWidget(lineEdit_TV_SERNAME);


        verticalLayout->addLayout(horizontalLayout_5);

        verticalSpacer_12 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_12);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        tabWidget->addTab(tab_5, QString());
        splitter->addWidget(tabWidget);

        gridLayout_5->addWidget(splitter, 0, 0, 1, 1);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_6 = new QLabel(page1);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_10->addWidget(label_6);

        widget_VLCPlayer = new QWidget(page1);
        widget_VLCPlayer->setObjectName(QString::fromUtf8("widget_VLCPlayer"));
        widget_VLCPlayer->setEnabled(true);

        verticalLayout_10->addWidget(widget_VLCPlayer);

        verticalLayout_10->setStretch(0, 2);
        verticalLayout_10->setStretch(1, 8);

        horizontalLayout_10->addLayout(verticalLayout_10);

        tableView_PROLIST = new QTableView(page1);
        tableView_PROLIST->setObjectName(QString::fromUtf8("tableView_PROLIST"));

        horizontalLayout_10->addWidget(tableView_PROLIST);

        horizontalLayout_10->setStretch(0, 8);
        horizontalLayout_10->setStretch(1, 2);

        gridLayout_5->addLayout(horizontalLayout_10, 0, 1, 1, 1);

        stackedWidget->addWidget(page1);
        page2 = new QWidget();
        page2->setObjectName(QString::fromUtf8("page2"));
        gridLayout_4 = new QGridLayout(page2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_13, 0, 1, 1, 1);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_12, 0, 3, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_17 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_17);

        commandLinkButton = new QCommandLinkButton(page2);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));

        horizontalLayout_9->addWidget(commandLinkButton);

        lab_ReadConfig = new QLabel(page2);
        lab_ReadConfig->setObjectName(QString::fromUtf8("lab_ReadConfig"));
        lab_ReadConfig->setStyleSheet(QString::fromUtf8("font: 12pt \"\346\245\267\344\275\223\";\n"
"color: rgb(255, 255, 0);"));
        lab_ReadConfig->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(lab_ReadConfig);

        horizontalSpacer_15 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_15);


        verticalLayout_3->addLayout(horizontalLayout_9);

        tableView_SysConfig = new QTableView(page2);
        tableView_SysConfig->setObjectName(QString::fromUtf8("tableView_SysConfig"));

        verticalLayout_3->addWidget(tableView_SysConfig);


        gridLayout_3->addLayout(verticalLayout_3, 0, 0, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_4);

        label_skinblack = new QLabel(page2);
        label_skinblack->setObjectName(QString::fromUtf8("label_skinblack"));

        verticalLayout_8->addWidget(label_skinblack);

        checkBox_black = new QCheckBox(page2);
        checkBox_black->setObjectName(QString::fromUtf8("checkBox_black"));

        verticalLayout_8->addWidget(checkBox_black);

        verticalSpacer_15 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_8->addItem(verticalSpacer_15);


        gridLayout_3->addLayout(verticalLayout_8, 0, 2, 1, 1);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalSpacer_16 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_16);

        label_skinwhite = new QLabel(page2);
        label_skinwhite->setObjectName(QString::fromUtf8("label_skinwhite"));

        verticalLayout_9->addWidget(label_skinwhite);

        checkBox_white = new QCheckBox(page2);
        checkBox_white->setObjectName(QString::fromUtf8("checkBox_white"));

        verticalLayout_9->addWidget(checkBox_white);

        verticalSpacer_18 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_9->addItem(verticalSpacer_18);


        gridLayout_3->addLayout(verticalLayout_9, 0, 5, 1, 1);

        horizontalSpacer_16 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_16, 0, 4, 1, 1);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_14, 0, 6, 1, 1);

        gridLayout_3->setColumnStretch(0, 4);
        gridLayout_3->setColumnStretch(1, 3);
        gridLayout_3->setColumnStretch(2, 3);

        gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

        label_4 = new QLabel(page2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_4->addWidget(label_4, 0, 1, 1, 1);

        stackedWidget->addWidget(page2);
        page3 = new QWidget();
        page3->setObjectName(QString::fromUtf8("page3"));
        lab3 = new QLabel(page3);
        lab3->setObjectName(QString::fromUtf8("lab3"));
        lab3->setGeometry(QRect(270, 70, 301, 201));
        lab3->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(page3);
        page4 = new QWidget();
        page4->setObjectName(QString::fromUtf8("page4"));
        verticalLayout_4 = new QVBoxLayout(page4);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        lab4 = new QLabel(page4);
        lab4->setObjectName(QString::fromUtf8("lab4"));
        lab4->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(lab4);

        stackedWidget->addWidget(page4);

        gridLayout_6->addWidget(stackedWidget, 2, 0, 1, 1);


        retranslateUi(UIDemo01);

        stackedWidget->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(UIDemo01);
    } // setupUi

    void retranslateUi(QDialog *UIDemo01)
    {
        UIDemo01->setWindowTitle(QCoreApplication::translate("UIDemo01", "Form", nullptr));
        labIco->setText(QString());
        labTitle->setText(QString());
        btnMain->setText(QCoreApplication::translate("UIDemo01", "\346\223\215\344\275\234\347\225\214\351\235\242", nullptr));
        btnConfig->setText(QCoreApplication::translate("UIDemo01", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        btnData->setText(QCoreApplication::translate("UIDemo01", "\346\212\245\350\255\246\346\237\245\350\257\242", nullptr));
        btnHelp->setText(QCoreApplication::translate("UIDemo01", "\350\260\203\350\257\225\345\270\256\345\212\251", nullptr));
        btnExit->setText(QCoreApplication::translate("UIDemo01", "\347\224\250\346\210\267\351\200\200\345\207\272", nullptr));
#if QT_CONFIG(tooltip)
        btnMenu_Min->setToolTip(QCoreApplication::translate("UIDemo01", "\346\234\200\345\260\217\345\214\226", nullptr));
#endif // QT_CONFIG(tooltip)
        btnMenu_Min->setText(QString());
#if QT_CONFIG(tooltip)
        btnMenu_Close->setToolTip(QCoreApplication::translate("UIDemo01", "\345\205\263\351\227\255", nullptr));
#endif // QT_CONFIG(tooltip)
        btnMenu_Close->setText(QString());
        btnMenu_Max->setText(QString());
        pushButton_add->setText(QCoreApplication::translate("UIDemo01", "\351\200\211  \346\213\251", nullptr));
        pushButton_5->setText(QCoreApplication::translate("UIDemo01", "\347\247\273  \351\231\244", nullptr));
        pushButton_ChannelSet->setText(QCoreApplication::translate("UIDemo01", "\351\242\221\351\201\223\350\256\276\347\275\256", nullptr));
        pushButton_2->setText(QCoreApplication::translate("UIDemo01", "\346\235\277\345\215\241\346\240\241\346\227\266", nullptr));
        pushButton_channelscan->setText(QCoreApplication::translate("UIDemo01", "\351\242\221\351\201\223\346\211\253\346\217\217", nullptr));
        label_2->setText(QCoreApplication::translate("UIDemo01", "\346\235\277 \345\215\241 IP:", nullptr));
        label_3->setText(QCoreApplication::translate("UIDemo01", "\351\242\221    \347\202\271:", nullptr));
        label_5->setText(QCoreApplication::translate("UIDemo01", "\351\200\232 \351\201\223 \345\217\267:", nullptr));
        label->setText(QCoreApplication::translate("UIDemo01", "\350\212\202\347\233\256\345\220\215\347\247\260:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("UIDemo01", "0", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("UIDemo01", "1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("UIDemo01", "\351\241\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("UIDemo01", "\351\241\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QCoreApplication::translate("UIDemo01", "\351\241\265", nullptr));
        label_6->setText(QCoreApplication::translate("UIDemo01", "\346\222\255\346\224\276\345\231\250", nullptr));
        commandLinkButton->setText(QCoreApplication::translate("UIDemo01", "ReadConfigSysCards", nullptr));
        lab_ReadConfig->setText(QCoreApplication::translate("UIDemo01", "... ...", nullptr));
        label_skinblack->setText(QCoreApplication::translate("UIDemo01", "TextLabel", nullptr));
        checkBox_black->setText(QCoreApplication::translate("UIDemo01", "\351\273\221\350\211\262\344\270\273\351\242\230", nullptr));
        label_skinwhite->setText(QCoreApplication::translate("UIDemo01", "TextLabel", nullptr));
        checkBox_white->setText(QCoreApplication::translate("UIDemo01", "\347\201\260\347\272\242\344\270\273\351\242\230", nullptr));
        label_4->setText(QString());
        lab3->setText(QCoreApplication::translate("UIDemo01", "0", nullptr));
        lab4->setText(QCoreApplication::translate("UIDemo01", "\350\260\203\350\257\225\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UIDemo01: public Ui_UIDemo01 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UIDEMO01_H
