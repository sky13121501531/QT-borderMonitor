#ifndef QCIRCLEPROGRESS_H
#define QCIRCLEPROGRESS_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QPixmap>
#include <QRect>
#include <QFont>
#include <QPointF>

class QCircleProgress : public QWidget
{
    Q_OBJECT
public:
    explicit QCircleProgress(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void setPen(QPen pen);
    QPen getPen();
    void setProgressPen(QPen pen);
    QPen getProgressPen();

    int getProgress();
signals:

public slots:
    void setProgress(int value);
private:
    QPainter *painter;
    QPixmap *cacheMap;
    QPen *pen;
    QPen *progressPen;
    int progress;
};

#endif // QCIRCLEPROGRESS_H
