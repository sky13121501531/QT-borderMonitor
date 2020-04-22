#include "circleprogress.h"


QCircleProgress::QCircleProgress(QWidget *parent) : QWidget(parent)
{
    this->progress = 0;
    this->setGeometry(0, 0, 300, 300);
    QRect winSize = this->geometry();
    this->cacheMap = new QPixmap(winSize.width(), winSize.height());
    this->painter = new QPainter(cacheMap);
    this->painter->setRenderHint(QPainter::Antialiasing);
}

void QCircleProgress::setPen(QPen pen){
    this->pen = &pen;
    update();
}

QPen QCircleProgress::getPen(){
    return *pen;
}

void QCircleProgress::setProgressPen(QPen pen){
    this->progressPen = &pen;
    update();
}

QPen QCircleProgress::getProgressPen(){
    return *progressPen;
}

void QCircleProgress::setProgress(int value){
    this->progress = value;
    update();
}

int QCircleProgress::getProgress(){
    return progress;
}

void QCircleProgress::paintEvent(QPaintEvent *){
    QPainter painter(this);
    this->cacheMap->fill(Qt::white);
    if(pen != NULL){
        this->painter->setPen(*pen);
        this->painter->drawArc(100, 100, 100, 100, 360 * -8, 360 * 16);
    }
    if(progressPen != NULL){
        this->painter->setPen(*progressPen);
        this->painter->drawArc(100, 100, 100, 100, 4 * 360, int((progress / 100.0f) * 360 * -16.0f));
    }
    QString progressPercent;
    progressPercent.sprintf("%d", progress);
    progressPercent.append("%");
    this->painter->drawText(QRectF(100.0f, 100.0f, 100.0f, 100.0f), progressPercent, QTextOption(Qt::AlignCenter));
    painter.drawPixmap(0, 0, *cacheMap);
}
