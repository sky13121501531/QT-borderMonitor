#ifndef UIDEMO01_H
#define UIDEMO01_H

#include <QDialog>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QTableView>
#include <QMultiMap>
#include<QVector>
#include "XmlParser.h"
#include "StrUtil.h"

namespace Ui {
class UIDemo01;
}

class UIDemo01 : public QDialog
{
    Q_OBJECT

public:
    explicit UIDemo01(QWidget *parent = 0);
    ~UIDemo01();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    std::string osdinfo;
    Ui::UIDemo01 *ui;
    QStandardItemModel *ChannelSet_Model;
    QStandardItemModel *Config_Model;
    QStandardItemModel *Prolist_Model;
    QMultiMap<int,std::string> Config_Multimap;
    QVector<moniter_paramset> ChannelSet_vector;

private slots:
    void initskin();
    void initForm();
    void buttonClick();
    void init_TV();
    void init_ProList_TableView();
    void init_TabWidget_Monitor_TV_TableView();/*操作界面---模拟电视*/
    void init_ReadConfigSysCardIP();/*系统配置项*/
    bool ReadConfigSysCardIP(std::string fileConfigIp);
    bool SaveFile_TV_ProList();
private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();
    void on_pushButton_add_clicked();/*电视选配节目添加事件*/
    void on_commandLinkButton_clicked();/*获取配置事件*/
    void on_pushButton_clicked();/*电视频道扫描*/
    void on_pushButton_5_clicked();/*电视节目del事件*/
    void on_checkBox_black_clicked();
    void on_checkBox_white_clicked();
};
#endif // UIDEMO01_H
