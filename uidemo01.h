#ifndef UIDEMO01_H
#define UIDEMO01_H

#include <QDialog>
#include <QStringListModel>
#include <QStandardItemModel>
#include <QNetworkAccessManager>//包含QNetworkAccessManager类
#include <QNetworkRequest>//包含QNetworkRequest类
#include <QNetworkReply>//包含QNetworkReply类
#include <QModelIndex>
#include <QTableView>
#include <QMultiMap>
#include <QVector>
#include <QDebug>
#include <QLabel>
#include "XmlParser.h"
#include "StrUtil.h"
#include "VLCWrapper.h"

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
    QMap<string,string> Prolist_map;
    QVector<moniter_paramset> ChannelSet_vector;
    QLabel *m_pLoadingLabel;
    int  m_nIndex;
    VLCWrapper m_vlc;
    QTimer *timer;

private slots:
    void initskin();
    void initForm();
    void buttonClick();
    void init_TV();
    void init_ProList_TableView();
    void init_TabWidget_Monitor_TV_TableView();/*操作界面---模拟电视*/
    void init_ReadConfigSysCardIP();/*系统配置项*/
    void ParaChannelRetXML(string ChannelXml,QStringList &QListVecFreq);
    bool ReadConfigSysCardIP(std::string fileConfigIp);
    bool SaveFile_TV_ProList();
    std::string PostHttpHeader(string strip,int len);
    void ShowWaitPic();
    void timeStart();
    void timeStop();
private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();
    void on_pushButton_add_clicked();/*电视选配节目添加事件*/
    void on_commandLinkButton_clicked();/*获取配置事件*/
    void on_pushButton_5_clicked();/*电视节目del事件*/
    void on_checkBox_black_clicked();
    void on_checkBox_white_clicked();
    void on_pushButton_channelscan_clicked();/*电视频道扫描*/
    void on_pushButton_ChannelSet_clicked();/*电视频道设置*/

    void onTableClicked(const QModelIndex &index);/*频道列表点击切换事件*/
};
#endif // UIDEMO01_H
