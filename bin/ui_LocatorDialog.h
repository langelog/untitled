/********************************************************************************
** Form generated from reading UI file 'LocatorDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOCATORDIALOG_H
#define UI_LOCATORDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LocatorDialog
{
public:
    QScrollArea *scroll_Locator;
    QWidget *scrollAreaWidgetContents;
    QLabel *label;
    QLineEdit *line_path;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *line_current;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_x;
    QLabel *label_y;
    QLabel *label_width;
    QLabel *label_height;
    QPushButton *pushButton_5;

    void setupUi(QDialog *LocatorDialog)
    {
        if (LocatorDialog->objectName().isEmpty())
            LocatorDialog->setObjectName(QStringLiteral("LocatorDialog"));
        LocatorDialog->setEnabled(true);
        LocatorDialog->resize(871, 531);
        scroll_Locator = new QScrollArea(LocatorDialog);
        scroll_Locator->setObjectName(QStringLiteral("scroll_Locator"));
        scroll_Locator->setEnabled(true);
        scroll_Locator->setGeometry(QRect(10, 40, 640, 480));
        scroll_Locator->setFrameShape(QFrame::NoFrame);
        scroll_Locator->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scroll_Locator->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scroll_Locator->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 640, 480));
        scroll_Locator->setWidget(scrollAreaWidgetContents);
        label = new QLabel(LocatorDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 71, 16));
        line_path = new QLineEdit(LocatorDialog);
        line_path->setObjectName(QStringLiteral("line_path"));
        line_path->setGeometry(QRect(70, 10, 581, 20));
        pushButton = new QPushButton(LocatorDialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(660, 10, 201, 23));
        pushButton_2 = new QPushButton(LocatorDialog);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(660, 80, 91, 23));
        pushButton_3 = new QPushButton(LocatorDialog);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setEnabled(true);
        pushButton_3->setGeometry(QRect(770, 80, 91, 23));
        pushButton_3->setCheckable(false);
        line_current = new QLineEdit(LocatorDialog);
        line_current->setObjectName(QStringLiteral("line_current"));
        line_current->setGeometry(QRect(660, 50, 201, 20));
        line_current->setAlignment(Qt::AlignCenter);
        line_current->setReadOnly(true);
        label_2 = new QLabel(LocatorDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(660, 121, 46, 13));
        label_3 = new QLabel(LocatorDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(660, 141, 46, 13));
        label_4 = new QLabel(LocatorDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(660, 161, 46, 13));
        label_5 = new QLabel(LocatorDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(660, 181, 46, 13));
        label_x = new QLabel(LocatorDialog);
        label_x->setObjectName(QStringLiteral("label_x"));
        label_x->setGeometry(QRect(704, 120, 151, 16));
        label_x->setFrameShape(QFrame::Box);
        label_y = new QLabel(LocatorDialog);
        label_y->setObjectName(QStringLiteral("label_y"));
        label_y->setGeometry(QRect(704, 140, 151, 16));
        label_y->setFrameShape(QFrame::Box);
        label_width = new QLabel(LocatorDialog);
        label_width->setObjectName(QStringLiteral("label_width"));
        label_width->setGeometry(QRect(704, 160, 151, 16));
        label_width->setFrameShape(QFrame::Box);
        label_height = new QLabel(LocatorDialog);
        label_height->setObjectName(QStringLiteral("label_height"));
        label_height->setGeometry(QRect(704, 180, 151, 16));
        label_height->setFrameShape(QFrame::Box);
        pushButton_5 = new QPushButton(LocatorDialog);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(660, 500, 201, 23));

        retranslateUi(LocatorDialog);

        QMetaObject::connectSlotsByName(LocatorDialog);
    } // setupUi

    void retranslateUi(QDialog *LocatorDialog)
    {
        LocatorDialog->setWindowTitle(QApplication::translate("LocatorDialog", "Dialog", 0));
        label->setText(QApplication::translate("LocatorDialog", "Imgs path:", 0));
        line_path->setText(QApplication::translate("LocatorDialog", "./photos", 0));
        pushButton->setText(QApplication::translate("LocatorDialog", "Open", 0));
        pushButton_2->setText(QApplication::translate("LocatorDialog", "prev", 0));
        pushButton_3->setText(QApplication::translate("LocatorDialog", "next", 0));
        line_current->setText(QApplication::translate("LocatorDialog", "x/y", 0));
        label_2->setText(QApplication::translate("LocatorDialog", "X:", 0));
        label_3->setText(QApplication::translate("LocatorDialog", "Y:", 0));
        label_4->setText(QApplication::translate("LocatorDialog", "WIDTH:", 0));
        label_5->setText(QApplication::translate("LocatorDialog", "HEIGHT:", 0));
        label_x->setText(QString());
        label_y->setText(QString());
        label_width->setText(QString());
        label_height->setText(QString());
        pushButton_5->setText(QApplication::translate("LocatorDialog", "Save Index", 0));
    } // retranslateUi

};

namespace Ui {
    class LocatorDialog: public Ui_LocatorDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOCATORDIALOG_H
