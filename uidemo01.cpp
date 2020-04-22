#pragma execution_character_set("utf-8")
#include "uidemo01.h"
#include "ui_uidemo01.h"
#include <vlc/vlc.h>
#include "iconhelper.h"
#include "qttcpsocekt.h"
#include "circleprogress.h"
UIDemo01::UIDemo01(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UIDemo01),
    m_nIndex(1)
{
    ui->setupUi(this);
    this->initForm();
    this->initskin();
    this->init_ProList_TableView();
    this->init_TV();
    this->init_TabWidget_Monitor_TV_TableView();
    this->init_ReadConfigSysCardIP();

    HWND SCRE = (HWND)ui->widget_VLCPlayer->winId();
    m_vlc.SetOutputWindow(SCRE);
    ui->widget_VLCPlayer->show();
//    m_pLoadingLabel = new QLabel(this);
//    m_pLoadingLabel->setText(tr("我是进度等待图片"));
//    m_pLoadingLabel->setGeometry(rect().x() + 400, rect().y()/2 + 200,200, 200);
//    m_pLoadingLabel->setAttribute(Qt::WA_TranslucentBackground);//背景透明
//    timer = new QTimer(this);
//    timer->setInterval(100);
//    connect(timer, &QTimer::timeout, this, &UIDemo01::ShowWaitPic);
}
UIDemo01::~UIDemo01()
{
    delete ui;
}
bool UIDemo01::eventFilter(QObject *watched, QEvent *event)
{
    if (event->type() == QEvent::MouseButtonDblClick) {
        if (watched == ui->widgetTitle) {
            on_btnMenu_Max_clicked();
            return true;
        }
    }
    return QWidget::eventFilter(watched, event);
}

void UIDemo01::initskin()
{
    QImage* imgskinblack = new QImage;
    if(!(imgskinblack->load("../skin/skinblack.png"))) //加载图像
    {
        QMessageBox::information(this,
                                 tr("皮肤加载警告"),
                                 tr("黑色主题皮肤加载失败!"));
        delete imgskinblack;
        imgskinblack = NULL;
    }
    if(imgskinblack)
        ui->label_skinblack->setPixmap(QPixmap::fromImage(*imgskinblack));
    ui->checkBox_black->setChecked(true);
    QImage* imgskinwhite = new QImage;
    if(!(imgskinwhite->load("../skin/skinwhite.png"))) //加载图像
    {
        QMessageBox::information(this,
                                 tr("皮肤加载警告"),
                                 tr("灰红主题皮肤加载失败!"));
        delete imgskinwhite;
        imgskinwhite = NULL;
    }
    if(imgskinwhite)
        ui->label_skinwhite->setPixmap(QPixmap::fromImage(*imgskinwhite));
    ui->checkBox_white->setChecked(false);
}

void UIDemo01::initForm()
{
    this->setProperty("form", true);
    this->setProperty("canMove", true);
    this->setWindowFlags(Qt::FramelessWindowHint /*无边框*/| Qt::WindowSystemMenuHint /**/| Qt::WindowMinMaxButtonsHint/*窗口最小化*/);

    IconHelper::Instance()->setIcon(ui->labIco, QChar(0xf099), 30);
    IconHelper::Instance()->setIcon(ui->btnMenu_Min, QChar(0xf068));
    IconHelper::Instance()->setIcon(ui->btnMenu_Max, QChar(0xf067));
    IconHelper::Instance()->setIcon(ui->btnMenu_Close, QChar(0xf00d));

    //ui->widgetMenu->setVisible(false);
    ui->widgetTitle->installEventFilter(this);
    ui->widgetTitle->setProperty("form", "title");
    ui->widgetTop->setProperty("nav", "top");
    ui->labTitle->setText("边境遥控监测平台");
    ui->labTitle->setFont(QFont("Microsoft Yahei", 22));
    this->setWindowTitle(ui->labTitle->text());

    ui->stackedWidget->setStyleSheet("QLabel{font:60pt;}");

    //单独设置指示器大小
    int addWidth = 20;
    int addHeight = 10;
    int rbtnWidth = 15;
    int ckWidth = 13;
    int scrWidth = 12;
    int borderWidth = 3;

    QStringList qss;
    qss.append(QString("QComboBox::drop-down,QDateEdit::drop-down,QTimeEdit::drop-down,QDateTimeEdit::drop-down{width:%1px;}").arg(addWidth));
    qss.append(QString("QComboBox::down-arrow,QDateEdit[calendarPopup=\"true\"]::down-arrow,QTimeEdit[calendarPopup=\"true\"]::down-arrow,"
                       "QDateTimeEdit[calendarPopup=\"true\"]::down-arrow{width:%1px;height:%1px;right:2px;}").arg(addHeight));
    qss.append(QString("QRadioButton::indicator{width:%1px;height:%1px;}").arg(rbtnWidth));
    qss.append(QString("QCheckBox::indicator,QGroupBox::indicator,QTreeWidget::indicator,QListWidget::indicator{width:%1px;height:%1px;}").arg(ckWidth));
    qss.append(QString("QScrollBar:horizontal{min-height:%1px;border-radius:%2px;}QScrollBar::handle:horizontal{border-radius:%2px;}"
                       "QScrollBar:vertical{min-width:%1px;border-radius:%2px;}QScrollBar::handle:vertical{border-radius:%2px;}").arg(scrWidth).arg(scrWidth / 2));
    qss.append(QString("QWidget#widget_top>QToolButton:pressed,QWidget#widget_top>QToolButton:hover,"
                       "QWidget#widget_top>QToolButton:checked,QWidget#widget_top>QLabel:hover{"
                       "border-width:0px 0px %1px 0px;}").arg(borderWidth));
    qss.append(QString("QWidget#widgetleft>QPushButton:checked,QWidget#widgetleft>QToolButton:checked,"
                       "QWidget#widgetleft>QPushButton:pressed,QWidget#widgetleft>QToolButton:pressed{"
                       "border-width:0px 0px 0px %1px;}").arg(borderWidth));
    this->setStyleSheet(qss.join(""));
    QSize icoSize(32, 32);
    int icoWidth = 85;

    //标签控件的布局
    ui->tabWidget->setTabText(0,"模拟电视");
    ui->tabWidget->setTabText(1,"调频广播");
    ui->tabWidget->setTabText(2,"中短波");
    ui->tabWidget->setTabText(3,"地面数字");
    ui->tabWidget->setTabText(4,"数字广播");

    //设置顶部导航按钮
    QList<QToolButton *> tbtns = ui->widgetTop->findChildren<QToolButton *>();
    foreach (QToolButton *btn, tbtns) {
        btn->setIconSize(icoSize);
        btn->setMinimumWidth(icoWidth);
        btn->setCheckable(true);
        connect(btn, SIGNAL(clicked()), this, SLOT(buttonClick()));
    }
    ui->btnMain->click();
}
void UIDemo01::buttonClick()
{
    QToolButton *b = (QToolButton *)sender();
    QString name = b->text();

    QList<QToolButton *> tbtns = ui->widgetTop->findChildren<QToolButton *>();
    foreach (QToolButton *btn, tbtns)
    {
        if (btn == b)
        {
            btn->setChecked(true);
        }
        else
        {
            btn->setChecked(false);
        }
    }
    if (name == "操作界面")
    {
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if (name == "系统设置")
    {
        ui->stackedWidget->setCurrentIndex(1);
    }
    else if (name == "报警查询")
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
    else if (name == "调试帮助")
    {
        ui->stackedWidget->setCurrentIndex(3);
    }
    else if (name == "用户退出")
    {
        exit(0);
    }
}
void UIDemo01::init_TV()
{
    QStringList QList;
    QList.clear();
    QList <<tr("200250")<<tr("184250");
    ui->comboBox_TV_FREQ->clear();
    ui->comboBox_TV_FREQ->addItems(QList);
    ui->comboBox_TV_FREQ->setCurrentIndex(0);

    QList.clear();
    QList <<tr("0")<<tr("1")<<tr("2")<<tr("3")<<tr("4")<<tr("5")<<tr("6")<<tr("7");
    ui->comboBox_TV_CHANNEL->clear();
    ui->comboBox_TV_CHANNEL->addItems(QList);
    ui->comboBox_TV_CHANNEL->setCurrentIndex(0);
}

void UIDemo01::init_ProList_TableView()
{
    Prolist_Model = new QStandardItemModel();
    Prolist_Model->setColumnCount(1);
    Prolist_Model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("频道列表"));
    ui->tableView_PROLIST->setModel(Prolist_Model);
    ui->tableView_PROLIST->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter);
    ui->tableView_PROLIST->setShowGrid(true);
    ui->tableView_PROLIST->resizeColumnsToContents();
    ui->tableView_PROLIST->setEditTriggers(/*QAbstractItemView::DoubleClicked | */QAbstractItemView::NoEditTriggers);
    ui->tableView_PROLIST->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView_PROLIST->verticalHeader()->hide();

    connect(ui->tableView_PROLIST, SIGNAL(clicked(const QModelIndex &)), this, SLOT(onTableClicked(const QModelIndex &)));
}
void UIDemo01::onTableClicked(const QModelIndex &index)
{
    if (index.isValid())
    {
        QString cellText = index.data().toString();
        string UDPSTR;
        QMap<string,string>::iterator pIter = Prolist_map.begin();;
        while (pIter != Prolist_map.end())
        {
            if(pIter.key() == cellText.toStdString())
            {
                UDPSTR = pIter.value();
                break;
            }
            ++pIter;
        }
        if(UDPSTR.size()>0)
        {
            QString strurl(UDPSTR.c_str());
            m_vlc.OpenMedia(UDPSTR.c_str());
            m_vlc.Play();
        }
    }
}
void UIDemo01::init_TabWidget_Monitor_TV_TableView()
{
    /*tableview控件初始化*/
    /*
        ******* 电视录像设置参数表格---TableView*******
        ******* 表格7行5列，列宽跟随表格内容及窗口大小可变,表格内容支持可编辑
        ******* 7行--最多设置7个节目--通道范围1-7
        ******* 0通道作为实时通道保留
    */
    //表头
    ChannelSet_Model = new QStandardItemModel();
    ChannelSet_Model->setColumnCount(5);
    ChannelSet_Model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("通道"));
    ChannelSet_Model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("频道名称"));
    ChannelSet_Model->setHeaderData(2,Qt::Horizontal,QString::fromLocal8Bit("             组 播   地 址            "));
    ChannelSet_Model->setHeaderData(3,Qt::Horizontal,QString::fromLocal8Bit("频率(khz)"));
    ChannelSet_Model->setHeaderData(4,Qt::Horizontal,QString::fromLocal8Bit("码率(bit)"));
    ui->TableViewNew->setModel(ChannelSet_Model);
    //ui->TableViewNew->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->TableViewNew->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter);
    ui->TableViewNew->setShowGrid(true);
    ui->TableViewNew->resizeColumnsToContents();
    ui->TableViewNew->setEditTriggers(/*QAbstractItemView::DoubleClicked | */QAbstractItemView::NoEditTriggers);
    ui->TableViewNew->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
void UIDemo01::init_ReadConfigSysCardIP()
{
    Config_Model = new QStandardItemModel();
    Config_Model->setColumnCount(2);
    Config_Model->setHeaderData(0,Qt::Horizontal,QString::fromLocal8Bit("板卡类型"));
    Config_Model->setHeaderData(1,Qt::Horizontal,QString::fromLocal8Bit("板卡个数"));
    ui->tableView_SysConfig->setModel(Config_Model);
    ui->tableView_SysConfig->horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter);
    ui->tableView_SysConfig->setShowGrid(true);
    ui->tableView_SysConfig->resizeColumnsToContents();
    ui->tableView_SysConfig->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void UIDemo01::ParaChannelRetXML(string ChannelXml,QStringList &QListVecFreq)
{
    string tmpStr = ChannelXml;
    size_t xmlPos = tmpStr.find_first_of("<");
    if (xmlPos != std::string::npos)
    {
        tmpStr = tmpStr.substr(xmlPos);
    }
    XmlParser retDeviceParser;
    retDeviceParser.Set_xml(tmpStr);
    std::string strXmlRet = retDeviceParser.GetNodeText(retDeviceParser.GetNodeFromPath((char*)"Msg/Status"));
    if( strXmlRet != std::string("SUCCESS"))
    {
        return;
    }
    else
    {
        pXMLNODE freqNode = NULL;
        pXMLNODE ScanNumNode = retDeviceParser.GetNodeFromPath((char*)"Msg/Data/ScanResult");
        string FreqNumstr,strtmpFreq;
        retDeviceParser.GetAttrNode(ScanNumNode,"FreqNum",FreqNumstr);
        if(StrUtil::Str2Int(FreqNumstr)>0)
        {
            pXMLNODELIST channelNodeList = retDeviceParser.GetNodeList(ScanNumNode);
            for (int i=0; i<channelNodeList->Size(); i++)
            {
                freqNode = retDeviceParser.GetNextNode(channelNodeList);
                string tmpFreq = retDeviceParser.GetNodeText(freqNode);
                QListVecFreq << tmpFreq.c_str();
                strtmpFreq+="\t频点:";
                strtmpFreq+=tmpFreq;
                strtmpFreq+="\n";
            }
        }
        else
        {
            return;
        }
    }
}
bool UIDemo01::ReadConfigSysCardIP(std::string fileConfigIp)
{
    std::string nodePath;
    XmlParser Parser;
    const int numIP = 7;
    std::string nodeList[numIP] = {"HostIP","ATVIP","AFMIP","AMIP","DTMBIP","TRANSCODEIP", "CDRIP"};
    bool isFlag = Parser.LoadFromFile(fileConfigIp.c_str());
    if(isFlag)
    {
        QStringList QList;
        ui->comboBox_TV_IP->clear();
        string strtmp;
        for (int k = 0;k<numIP;k++)
        {
            nodePath="Msg/"+nodeList[k];
            pXMLNODE node=Parser.GetNodeFromPath((char *)nodePath.c_str());
            if(node==NULL)
                return false;
            pXMLNODELIST nodeList=Parser.GetNodeList(node);
            int count = nodeList->Size();
            for(int i=0;i<count;i++)
            {
                pXMLNODE nodeNext=Parser.GetNextNode(nodeList);
                string strtmpIP;
                switch ( k )
                {
                case 0:
                    Parser.GetAttrNode(nodeNext,"hostIP",strtmpIP);//OSDFirmName
                    Parser.GetAttrNode(nodeNext,"OSDFirmName",osdinfo);
                    if(osdinfo=="")
                    {
                        osdinfo = "JSWS";
                    }
                    break;
                case 1:
                    Parser.GetAttrNode(nodeNext,"atvIP",strtmpIP);
                    QList << tr(strtmpIP.c_str());
                    break;
                case 2:
                    Parser.GetAttrNode(nodeNext,"afmIP",strtmpIP);
                    break;
                case 3:
                    Parser.GetAttrNode(nodeNext,"amIP",strtmpIP);
                    break;
                case 4:
                    Parser.GetAttrNode(nodeNext,"dtmbIP",strtmpIP);
                    break;
                case 5:
                    Parser.GetAttrNode(nodeNext,"transcodeIP",strtmpIP);
                    break;
                case 6:
                    Parser.GetAttrNode(nodeNext,"cdrIP",strtmpIP);
                    break;
                default:
                    break;
                }
                if(strtmpIP!="")
                    Config_Multimap.insert(k,strtmpIP);
            }
        }
        ui->comboBox_TV_IP->addItems(QList);
        ui->comboBox_TV_IP->setCurrentIndex(0);
    }
    else
    {
        return false;
    }
    return true;
}
void UIDemo01::on_btnMenu_Min_clicked()
{
    showMinimized();
}

void UIDemo01::on_btnMenu_Max_clicked()
{
    static bool max = false;
    static QRect location = this->geometry();

    if (max) {
        this->setGeometry(location);
    } else {
        location = this->geometry();
        this->setGeometry(qApp->desktop()->availableGeometry());
    }
    this->setProperty("canMove", max);
    max = !max;
}

void UIDemo01::on_btnMenu_Close_clicked()
{
    close();
}
void UIDemo01::on_pushButton_add_clicked()
{
    /*
        ******* 模拟电视频道表选择添加---TableView*******
    */

    moniter_paramset tmpSet;
    QString QstrDevHttpIP,Qfreq,Qchannel,QstrChannel,QstrUdpAddr,QstrProName;
    QstrDevHttpIP = ui->comboBox_TV_IP->itemText(ui->comboBox_TV_IP->currentIndex());

    string Chassid,slotID;
    StrUtil::GetIPNumID(QstrDevHttpIP.toStdString(),Chassid,slotID);

    Qfreq = ui->comboBox_TV_FREQ->itemText(ui->comboBox_TV_FREQ->currentIndex());
    Qchannel = ui->comboBox_TV_CHANNEL->itemText(ui->comboBox_TV_CHANNEL->currentIndex());
    if(!ChannelSet_vector.isEmpty())
    {
        for(int i =0;i<ChannelSet_vector.size();i++)
        {
            if(Qchannel.toStdString() == ChannelSet_vector[i].Channel)
            {
                QMessageBox::information(NULL, "警告", "此通道已经存在", QMessageBox::Yes, QMessageBox::Yes);
                return;
            }
        }
    }
    tmpSet.Type = "TV";
    tmpSet.TsIP = string("238") + string(".") + Chassid + string(".") + slotID + string(".") +  Qchannel.toStdString();
    tmpSet.TsPort = StrUtil::Int2Str(ATVMOREPORT);
    tmpSet.ModulationType = "PALDK";
    tmpSet.Channel = Qchannel.toStdString();

    string tmpOSDText = ui->lineEdit_TV_SERNAME->text().toStdString();
    if(tmpOSDText=="")
    {
        tmpSet.text = string("TV_") + tmpSet.Frequency + tmpSet.Channel;
    }
    else
    {
        tmpSet.text = tmpOSDText+tmpSet.Channel;
    }
    tmpSet.Frequency = Qfreq.toStdString();
    tmpSet.UDPAddr = string("udp://@") + tmpSet.TsIP + string(":") + tmpSet.TsPort;
    tmpSet.VideoBitrate = "1500000";
    ChannelSet_vector.push_back(tmpSet);

    ChannelSet_Model->removeRows(0,ChannelSet_Model->rowCount());
    if(!ChannelSet_vector.isEmpty())
    {
        for(int i = 0;i< ChannelSet_vector.size();i++)
        {
            moniter_paramset tmpChannelSet = ChannelSet_vector[i];
            ChannelSet_Model->setItem(i,0,new QStandardItem(QString(tmpChannelSet.Channel.c_str())));
            ChannelSet_Model->setItem(i,1,new QStandardItem(QString(tmpChannelSet.text.c_str())));
            ChannelSet_Model->setItem(i,2,new QStandardItem(QString(tmpChannelSet.UDPAddr.c_str())));
            ChannelSet_Model->setItem(i,3,new QStandardItem(QString(tmpChannelSet.Frequency.c_str())));
            ChannelSet_Model->setItem(i,4,new QStandardItem(QString(tmpChannelSet.VideoBitrate.c_str())));
            for(int j =0;j<5;j++)
            {
                //设置字符颜色
                ChannelSet_Model->item(i,j)->setForeground(QBrush(QColor(255, 255, 255)));
                //设置字符位置
                ChannelSet_Model->item(i,j)->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
}

void UIDemo01::on_pushButton_ChannelSet_clicked()
{ 
    if(!ChannelSet_vector.isEmpty())
    {
        Prolist_Model->removeRows(0,Prolist_Model->rowCount());
        for(int i = 0;i< ChannelSet_vector.size();i++)
        {
            string tmpXMLChannelSet = StrUtil::MonitorCardTs_paramset(ChannelSet_vector[i]);
            string sendmsg = PostHttpHeader(ui->comboBox_TV_IP->currentText().toStdString(),tmpXMLChannelSet.length());
            sendmsg += tmpXMLChannelSet;
            QString qstring;
            qstring = QString(QString::fromLocal8Bit(sendmsg.c_str()));
            QByteArray strRet = qstring.toUtf8();
            XSocketClient tmpSocket;
            if(tmpSocket.ConnectTo(ui->comboBox_TV_IP->currentText(),MONICARDPORT,strRet)==ERROR_NO)
            {
                if(tmpSocket.read()==ERROR_NO)
                {
                    QByteArray recvdata = tmpSocket.GetRecvData();
                    QString strtmp(recvdata);
                    if(strtmp.indexOf("SUCCESS")==-1)
                    {
                        QMessageBox::information(NULL, "警告", "设置失败", QMessageBox::Yes, QMessageBox::Yes);
                        return;
                    }
                    else
                    {
                        Prolist_Model->setItem(i,0,new QStandardItem(QString(ChannelSet_vector[i].text.c_str())));
                        //设置字符颜色
                        Prolist_Model->item(i,0)->setForeground(QBrush(QColor(187, 255, 255)));
                        //设置字符位置
                        Prolist_Model->item(i,0)->setTextAlignment(Qt::AlignCenter);

                        Prolist_map.insert(ChannelSet_vector[i].text,ChannelSet_vector[i].UDPAddr);
                    }
                }
                else if(tmpSocket.read()==ERROR_TIMEOUT)
                {
                    QMessageBox::information(NULL, "警告", "电视频道设置时连接超时", QMessageBox::Yes, QMessageBox::Yes);
                    return;
                }
            }
        }
    }
}

bool UIDemo01::SaveFile_TV_ProList()
{
    /*保存到磁盘*/
    QString QstrDevHttpIP,Qfreq,Qchannel,QstrChannel,QstrUdpAddr,QstrProName;
    QstrDevHttpIP = ui->comboBox_TV_IP->itemText(ui->comboBox_TV_IP->currentIndex());
    string Chassid,slotID;
    StrUtil::GetIPNumID(QstrDevHttpIP.toStdString(),Chassid,slotID);
    if(!ChannelSet_vector.isEmpty())
    {
        XmlParser Parser;
        pXMLNODE headRootNode;
        pXMLNODE proInfonode;
        string strSrcXml = "<?xml version=\"1.0\" encoding=\"GB2312\"?>\
                <Msg Version=\"1.0\" MsgID=\"10000\" SrcUrl=\"http://";
        strSrcXml += QstrDevHttpIP.toStdString();
        strSrcXml += ":8080\"";
        strSrcXml += ">\"\
                </Msg>";
                Parser.Set_xml(strSrcXml);
        for(int i = 0;i< ChannelSet_vector.size();i++)
        {
            moniter_paramset tmpChannelSet = ChannelSet_vector[i];
            headRootNode = Parser.GetNodeFromPath((char*)"Msg");
            proInfonode = Parser.CreateNodePtr(headRootNode,(char*)"ProInfo");
            Parser.SetAttrNode("ServiceID",tmpChannelSet.Channel,proInfonode);
            Parser.SetAttrNode("Freq",tmpChannelSet.Frequency,proInfonode);
            Parser.SetAttrNode("TsIP",tmpChannelSet.TsIP,proInfonode);
            Parser.SetAttrNode("TsPort",tmpChannelSet.TsPort,proInfonode);
            Parser.SetAttrNode("Bitrate",tmpChannelSet.VideoBitrate,proInfonode);
            Parser.SetAttrNode("ProName",tmpChannelSet.text,proInfonode);
            Parser.SetAttrNode("URL",tmpChannelSet.UDPAddr,proInfonode);
        }
        string tmpIndexID = string("TV_") + Chassid + slotID;
        string Filename = string("d:\\skyLog\\") + tmpIndexID + string(".xml");
        Parser.SaveAsFile(Filename.c_str());
    }
    return true;
}

string UIDemo01::PostHttpHeader(string strip, int len)
{
    //构造post http请求头
        std::string strHeader = "";
        strHeader += "POST /";
        strHeader += "perform";
        strHeader += " HTTP/1.1\r\n";
        strHeader += "Host: ";
        strHeader += strip;
        strHeader += ":";
        strHeader += "8080";
        strHeader += "\r\n";
        strHeader += "Cache-Control: no-cache\r\n";
        std::string strLen = StrUtil::Int2Str(len);
        strHeader += "Content-Length: ";
        strHeader += strLen;
        strHeader += " \r\n";
        strHeader += "Content-Type:text/xml \r\n";
        strHeader += "\r\n";
        return strHeader;
}

void UIDemo01::ShowWaitPic()
{
    m_nIndex++;
    if (m_nIndex > 8)
        m_nIndex = 1;

    QPixmap pixmap(QString("C:/Users/Administrator/Desktop/QTJSWStool/uidemo01/image/blackprogress%1").arg(m_nIndex));
    m_pLoadingLabel->setPixmap(pixmap);
}
void UIDemo01::on_commandLinkButton_clicked()
{
    //读取配置文件
    QString s = QFileDialog::getOpenFileName(
                    this, "选择机箱板卡IP配置文件",
                    "/",
                    "配置文件 (*.xml *.txt *.ini);; 所有文件 (*.*);; ");
    string tmpPath = s.toStdString();
    if(Config_Multimap.size()>0)
    {
        Config_Multimap.clear();
    }
    if(ReadConfigSysCardIP(tmpPath))
    {
        int RetCount = 0;
        QString tmpCount;
        for(int i=0;i<7;i++)
        {
            QList<string> rList;
            rList.clear();
            rList = Config_Multimap.values(i);
            QString tmpNum = QString::number(rList.size());
            switch(i)
            {
            case 0:
                break;
            case 1:
                Config_Model->setItem(i,0,new QStandardItem("模拟电视板卡"));
                Config_Model->setItem(i,1,new QStandardItem(tmpNum));
                break;
            case 2:
                Config_Model->setItem(i,0,new QStandardItem("调频广播板卡"));
                Config_Model->setItem(i,1,new QStandardItem(tmpNum));
                break;
            case 3:
                Config_Model->setItem(i,0,new QStandardItem("中短波板卡"));
                Config_Model->setItem(i,1,new QStandardItem(tmpNum));
                break;
            case 4:
                Config_Model->setItem(i,0,new QStandardItem("地面数字板卡"));
                Config_Model->setItem(i,1,new QStandardItem(tmpNum));
                break;
            case 5:
                Config_Model->setItem(i,0,new QStandardItem("转码板卡"));
                Config_Model->setItem(i,1,new QStandardItem(tmpNum));
                break;
            case 6:
                Config_Model->setItem(i,0,new QStandardItem("数字广播板卡"));
                Config_Model->setItem(i,1,new QStandardItem(tmpNum));
                break;
            default:
                break;
            }
            if(i!=0)
            {
                RetCount = RetCount + rList.size();
                for(int j = 0; j < 2; j++)
                {
                    //设置字符颜色
                    Config_Model->item(i,j)->setForeground(QBrush(QColor(255, 255, 255)));
                    //设置字符位置
                    Config_Model->item(i,j)->setTextAlignment(Qt::AlignCenter);
                }
            }
        }
        /*最后插入总数---0序号*/
        tmpCount = QString::number(RetCount);
        Config_Model->setItem(0,0,new QStandardItem("板卡总数"));
        Config_Model->setItem(0,1,new QStandardItem(tmpCount));
        for(int j = 0; j < 2; j++)
        {
            //设置字符颜色
            Config_Model->item(0,j)->setForeground(QBrush(QColor(64, 224, 208)));
            //设置字符位置
            Config_Model->item(0,j)->setTextAlignment(Qt::AlignCenter);
        }
    }
}
void UIDemo01::on_pushButton_channelscan_clicked()
{
    /*
        ******* 模拟电视频道扫描---TableView*******
    */
    moniter_channelscan mTv_channelscan;
    mTv_channelscan.Type = "TV";
    mTv_channelscan.Channel = ui->comboBox_TV_CHANNEL->currentText().toStdString();
    string xmlContent = StrUtil::MonitorCardTs_ChannelScan(mTv_channelscan);
    string sendmsg = PostHttpHeader(ui->comboBox_TV_IP->currentText().toStdString(),xmlContent.length());
    sendmsg += xmlContent;
    QString qstring;
    qstring = QString(QString::fromLocal8Bit(sendmsg.c_str()));
    QByteArray strRet = qstring.toUtf8();
    XSocketClient tmpSocket;
    if(tmpSocket.ConnectTo(ui->comboBox_TV_IP->currentText(),MONICARDPORT,strRet)==ERROR_NO)
    {
        if(tmpSocket.read()==ERROR_NO)
        {
            QByteArray recvdata = tmpSocket.GetRecvData();
            QString strtmp(recvdata);
            QStringList QList;
            QList.clear();
            ParaChannelRetXML(strtmp.toStdString(),QList);
            if(QList.size()>0)
            {
                ui->comboBox_TV_FREQ->clear();
                ui->comboBox_TV_FREQ->addItems(QList);
                ui->comboBox_TV_FREQ->setCurrentIndex(0);
            }
        }
        else if(tmpSocket.read()==ERROR_TIMEOUT)
        {
            qDebug()<<"频道扫描指令超时";
        }
    }
    //timer->stop();
}
void UIDemo01::on_pushButton_5_clicked()
{
    /*
        ******* 模拟电视频道表删除---TableView*******
    */
    QModelIndex index = ui->TableViewNew->selectionModel()->currentIndex();
    int iSel = index.row();
    if (iSel < 0){
        return;
    }
    else{
        QModelIndex index = ChannelSet_Model->index(iSel,0);//选中行第一列的内容
        QVariant data = ChannelSet_Model->data(index);
        string Channel = data.toString().toStdString();
        ChannelSet_Model->removeRow(iSel);
        //ChannelSet_Model->removeRows(0,ChannelSet_Model->rowCount());
        QVector<moniter_paramset>::iterator pTViter;
        for(pTViter = ChannelSet_vector.begin();pTViter != ChannelSet_vector.end();pTViter++)
        {
            moniter_paramset tmpChannelSet = *pTViter;
            if(tmpChannelSet.Channel == Channel)
            {
                ChannelSet_vector.erase(pTViter);
                break;
            }
        }
    }
}
void UIDemo01::on_checkBox_black_clicked()
{
    //加载样式表
    QFile fileblack(":/qss/psblack.css");
    if (fileblack.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(fileblack.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        fileblack.close();
    }
    ui->checkBox_black->setChecked(true);
    ui->checkBox_white->setChecked(false);
}
void UIDemo01::on_checkBox_white_clicked()
{
    //加载样式表
    QFile filewhite(":/qss/pswhite.css");
    if (filewhite.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(filewhite.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        filewhite.close();
    }
    ui->checkBox_black->setChecked(false);
    ui->checkBox_white->setChecked(true);
}

void UIDemo01::timeStart()
{
    timer->start();
}

void UIDemo01::timeStop()
{
    timer->stop();
}
