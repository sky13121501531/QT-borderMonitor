#include "uidemo01.h"
#include "appinit.h"
#include <QApplication>
#include <QTextCodec>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
#if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
#if _MSC_VER
    QTextCodec *codec = QTextCodec::codecForName("gbk");
#else
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
#endif
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
#else
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
#endif
    QFile fileblack(":/qss/psblack.css");
    if (fileblack.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(fileblack.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        fileblack.close();
    }
    a.setFont(QFont("Microsoft Yahei", 9));
    AppInit::Instance()->start();

    UIDemo01 w;
    w.show();
    return a.exec();
}
