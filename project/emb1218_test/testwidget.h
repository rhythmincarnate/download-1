#ifndef TESTWIDGET_H
#define TESTWIDGET_H

#include <QWidget>
#include <QString>
#include <QPushButton>

namespace Ui {
class testWidget;
}

class testWidget : public QWidget
{
    Q_OBJECT

public:
    //构造方法:当创建对象时自动调用的方法
    explicit testWidget(QWidget *parent = 0);
    //析构方法:当对象销毁的时候自动方法
    ~testWidget();

    void setLineEditString(QPushButton *button);

private slots:
    void on_pushButton_clicked();

    void on_twoPushButton_clicked();

    void on_threePushButton_clicked();

    void on_plusPushButton_clicked();

    void on_subPushButton_clicded();

    void on_equalPushButton_clicked();

    void on_bsPushButton_clicked();

    void on_clearPushButton_clicked();

private:
    Ui::testWidget *ui;
    QString str;

};

#endif // TESTWIDGET_H
