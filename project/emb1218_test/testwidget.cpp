#include "testwidget.h"
#include "ui_testwidget.h"

#include <QPushButton>
//#include <qpushbutton.h>
#include <QDebug>
#include <QByteArray>
#include <QStack>

testWidget::testWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testWidget)
{
    ui->setupUi(this);

    //创建对象
    QPushButton *pushButton = new QPushButton(QString("测试"), this);
    str.clear();
    pushButton->setText("计算器");

    //连接信号与槽
    connect(ui->subPushButton, SIGNAL(clicked(bool)), \
            this, SLOT(on_subPushButton_clicded()));
}

testWidget::~testWidget()
{
    delete ui;
}

void testWidget::setLineEditString(QPushButton *button)
{
    //获取按钮对象pushButton的text
    QString s = button->text();
    this->str.append(s);
    //显示到lineEdit对象中
    ui->lineEdit->setText(this->str);
}

//点击按钮调用的槽函数
void testWidget::on_pushButton_clicked()
{
    //qDebug("click this button\n");
    setLineEditString(ui->pushButton);

}

void testWidget::on_twoPushButton_clicked()
{
    this->setLineEditString(ui->twoPushButton);
}

void testWidget::on_threePushButton_clicked()
{
    this->setLineEditString(ui->threePushButton);
}

void testWidget::on_plusPushButton_clicked()
{
    this->setLineEditString(ui->plusPushButton);
}

void testWidget::on_subPushButton_clicded()
{
    this->setLineEditString(ui->subPushButton);
}

void testWidget::on_equalPushButton_clicked()
{
    //将str转换为c string

    //QString--->QByteArray
    QByteArray ba = this->str.toLatin1();
    //QByteArray--->c string
    const char *s = ba.data();
    int p;

    QStack<int> stack;

    stack.push(1);
    stack.push(2);

    while (!stack.isEmpty()) {
        p = stack.pop();
        qDebug() << p;
    }


    qDebug("%s\n", s);

}

void testWidget::on_bsPushButton_clicked()
{
    //qDebug() << "click bsPushButton";
    //将str删除最后一个字符
    this->str = this->str.left(str.length()-1);
    ui->lineEdit->setText(this->str);
}

void testWidget::on_clearPushButton_clicked()
{
    this->str.clear();
    ui->lineEdit->setText(this->str);
}
