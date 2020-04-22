#ifndef MAINWINDOWCESHI_H
#define MAINWINDOWCESHI_H

#include <QMainWindow>

namespace Ui {
class MainWindowCeshi;
}

class MainWindowCeshi : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowCeshi(QWidget *parent = nullptr);
    ~MainWindowCeshi();

private:
    Ui::MainWindowCeshi *ui;
};

#endif // MAINWINDOWCESHI_H
