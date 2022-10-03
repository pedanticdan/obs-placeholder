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
#if 0
#include <QtWidgets/QAction>
#endif
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
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *cancelButton;
    QPushButton *Reset;
    QPushButton *saveButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(685, 240);
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
        lineEdit->setMinimumSize(QSize(440, 30));
        lineEdit->setMaximumSize(QSize(440, 30));
        lineEdit->setBaseSize(QSize(440, 30));
        lineEdit->setCursorPosition(0);

        horizontalLayout->addWidget(lineEdit);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(120, 30));
        pushButton->setMaximumSize(QSize(120, 30));
        pushButton->setBaseSize(QSize(120, 30));

        horizontalLayout->addWidget(pushButton);

        layoutWidget2 = new QWidget(Dialog);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(120, 160, 453, 32));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setSpacing(59);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        cancelButton = new QPushButton(layoutWidget2);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setMinimumSize(QSize(80, 30));
        cancelButton->setMaximumSize(QSize(80, 30));
        cancelButton->setBaseSize(QSize(80, 30));

        horizontalLayout_2->addWidget(cancelButton);

        Reset = new QPushButton(layoutWidget2);
        Reset->setObjectName(QStringLiteral("Reset"));
        Reset->setMinimumSize(QSize(140, 30));
        Reset->setMaximumSize(QSize(140, 30));
        Reset->setBaseSize(QSize(140, 30));

        horizontalLayout_2->addWidget(Reset);

        saveButton = new QPushButton(layoutWidget2);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setMinimumSize(QSize(0, 30));
        saveButton->setMaximumSize(QSize(16777215, 30));
        saveButton->setBaseSize(QSize(0, 30));

        horizontalLayout_2->addWidget(saveButton);


        retranslateUi(Dialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), Dialog, SLOT(reject()));
        QObject::connect(saveButton, SIGNAL(clicked()), Dialog, SLOT(accept()));
        QObject::connect(Reset, SIGNAL(clicked()), lineEdit, SLOT(clear()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Placeholder.Settings.DialogTitle", nullptr));
        label->setText(QApplication::translate("Dialog", "Placeholder.Settings.TextLabel", nullptr));
        lineEdit->setText(QString());
        pushButton->setText(QApplication::translate("Dialog", "Placeholder.Settings.BrowseLabel", nullptr));
        cancelButton->setText(QApplication::translate("Dialog", "Placeholder.Settings.Cancel", nullptr));
        Reset->setText(QApplication::translate("Dialog", "Placeholder.Settings.Reset", nullptr));
        saveButton->setText(QApplication::translate("Dialog", "Placeholder.Settings.Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
