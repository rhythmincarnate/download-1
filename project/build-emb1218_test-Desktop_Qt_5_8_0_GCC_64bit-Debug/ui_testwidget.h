/********************************************************************************
** Form generated from reading UI file 'testwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTWIDGET_H
#define UI_TESTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testWidget
{
public:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QPushButton *twoPushButton;
    QPushButton *threePushButton;
    QPushButton *subPushButton;
    QPushButton *equalPushButton;
    QPushButton *bsPushButton;
    QPushButton *clearPushButton;
    QLabel *label;
    QPushButton *plusPushButton;

    void setupUi(QWidget *testWidget)
    {
        if (testWidget->objectName().isEmpty())
            testWidget->setObjectName(QStringLiteral("testWidget"));
        testWidget->resize(400, 300);
        testWidget->setMinimumSize(QSize(400, 300));
        testWidget->setMaximumSize(QSize(400, 300));
        testWidget->setAutoFillBackground(true);
        testWidget->setStyleSheet(QStringLiteral(""));
        lineEdit = new QLineEdit(testWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(60, 60, 261, 61));
        pushButton = new QPushButton(testWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(70, 160, 71, 31));
        QIcon icon;
        icon.addFile(QStringLiteral(":/new/prefix1/img/1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(71, 31));
        pushButton->setAutoDefault(false);
        pushButton->setFlat(true);
        twoPushButton = new QPushButton(testWidget);
        twoPushButton->setObjectName(QStringLiteral("twoPushButton"));
        twoPushButton->setGeometry(QRect(150, 160, 71, 31));
        threePushButton = new QPushButton(testWidget);
        threePushButton->setObjectName(QStringLiteral("threePushButton"));
        threePushButton->setGeometry(QRect(230, 160, 71, 31));
        subPushButton = new QPushButton(testWidget);
        subPushButton->setObjectName(QStringLiteral("subPushButton"));
        subPushButton->setGeometry(QRect(100, 210, 61, 41));
        equalPushButton = new QPushButton(testWidget);
        equalPushButton->setObjectName(QStringLiteral("equalPushButton"));
        equalPushButton->setGeometry(QRect(180, 210, 61, 41));
        bsPushButton = new QPushButton(testWidget);
        bsPushButton->setObjectName(QStringLiteral("bsPushButton"));
        bsPushButton->setGeometry(QRect(250, 210, 61, 41));
        clearPushButton = new QPushButton(testWidget);
        clearPushButton->setObjectName(QStringLiteral("clearPushButton"));
        clearPushButton->setGeometry(QRect(320, 210, 61, 41));
        label = new QLabel(testWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 400, 300));
        label->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/img/jbs.jpg")));
        label->setScaledContents(true);
        plusPushButton = new QPushButton(testWidget);
        plusPushButton->setObjectName(QStringLiteral("plusPushButton"));
        plusPushButton->setGeometry(QRect(30, 210, 61, 41));
        label->raise();
        lineEdit->raise();
        pushButton->raise();
        twoPushButton->raise();
        threePushButton->raise();
        plusPushButton->raise();
        subPushButton->raise();
        equalPushButton->raise();
        bsPushButton->raise();
        clearPushButton->raise();
        plusPushButton->raise();

        retranslateUi(testWidget);

        QMetaObject::connectSlotsByName(testWidget);
    } // setupUi

    void retranslateUi(QWidget *testWidget)
    {
        testWidget->setWindowTitle(QApplication::translate("testWidget", "testWidget", Q_NULLPTR));
        lineEdit->setPlaceholderText(QApplication::translate("testWidget", "\345\257\271\346\226\271\346\255\243\345\234\250\350\276\223\345\205\245......", Q_NULLPTR));
        pushButton->setText(QApplication::translate("testWidget", "1", Q_NULLPTR));
        twoPushButton->setText(QApplication::translate("testWidget", "2", Q_NULLPTR));
        threePushButton->setText(QApplication::translate("testWidget", "3", Q_NULLPTR));
        subPushButton->setText(QApplication::translate("testWidget", "-", Q_NULLPTR));
        equalPushButton->setText(QApplication::translate("testWidget", "=", Q_NULLPTR));
        bsPushButton->setText(QApplication::translate("testWidget", "<-", Q_NULLPTR));
        clearPushButton->setText(QApplication::translate("testWidget", "c", Q_NULLPTR));
        label->setText(QString());
        plusPushButton->setText(QApplication::translate("testWidget", "+", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class testWidget: public Ui_testWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTWIDGET_H
