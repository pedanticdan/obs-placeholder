/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *cancelButton;
    QPushButton *saveButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(685, 270);
        Dialog->setAcceptDrops(false);
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(40, 30, 230, 20));
        label->setMinimumSize(QSize(230, 20));
        label->setMaximumSize(QSize(230, 20));
        label->setBaseSize(QSize(220, 20));
        label->setLayoutDirection(Qt::LeftToRight);
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 80, 621, 52));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setEnabled(true);
        lineEdit->setMinimumSize(QSize(440, 50));
        lineEdit->setMaximumSize(QSize(440, 50));
        lineEdit->setBaseSize(QSize(440, 50));
        lineEdit->setCursorPosition(0);

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(140, 50));
        pushButton->setMaximumSize(QSize(140, 60));
        pushButton->setBaseSize(QSize(140, 50));

        horizontalLayout->addWidget(pushButton);

        widget = new QWidget(Dialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(230, 190, 221, 24));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(59);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        cancelButton = new QPushButton(widget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout_2->addWidget(cancelButton);

        saveButton = new QPushButton(widget);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout_2->addWidget(saveButton);


        retranslateUi(Dialog);
        QObject::connect(saveButton, SIGNAL(clicked()), Dialog, SLOT(reject()));
        QObject::connect(cancelButton, SIGNAL(clicked()), Dialog, SLOT(accept()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Placeholder.Settings.DialogTitle", nullptr));
        label->setText(QApplication::translate("Dialog", "Placeholder.Settings.TextLabel", nullptr));
        lineEdit->setText(QApplication::translate("Dialog", "file name", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "Placeholder.Settings.BrowseLabel", nullptr));
        cancelButton->setText(QApplication::translate("Dialog", "Placeholder.Settings.Cancel", nullptr));
        saveButton->setText(QApplication::translate("Dialog", "Placeholder.Settings.Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
