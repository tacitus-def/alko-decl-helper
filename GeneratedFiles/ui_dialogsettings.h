/********************************************************************************
** Form generated from reading UI file 'dialogsettings.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGSETTINGS_H
#define UI_DIALOGSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogSettings
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *filePathEdit;
    QPushButton *btnBrowse;
    QLabel *label_3;
    QLineEdit *pswEdit;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogSettings)
    {
        if (DialogSettings->objectName().isEmpty())
            DialogSettings->setObjectName(QStringLiteral("DialogSettings"));
        DialogSettings->resize(603, 300);
        horizontalLayout = new QHBoxLayout(DialogSettings);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(DialogSettings);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        filePathEdit = new QLineEdit(groupBox);
        filePathEdit->setObjectName(QStringLiteral("filePathEdit"));
        filePathEdit->setReadOnly(true);

        horizontalLayout_2->addWidget(filePathEdit);

        btnBrowse = new QPushButton(groupBox);
        btnBrowse->setObjectName(QStringLiteral("btnBrowse"));

        horizontalLayout_2->addWidget(btnBrowse);


        verticalLayout_2->addLayout(horizontalLayout_2);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        pswEdit = new QLineEdit(groupBox);
        pswEdit->setObjectName(QStringLiteral("pswEdit"));
        pswEdit->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(pswEdit);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        verticalLayout->addWidget(groupBox);


        horizontalLayout->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(DialogSettings);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(DialogSettings);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogSettings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogSettings, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogSettings);
    } // setupUi

    void retranslateUi(QDialog *DialogSettings)
    {
        DialogSettings->setWindowTitle(QApplication::translate("DialogSettings", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213", 0));
        groupBox->setTitle(QApplication::translate("DialogSettings", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \320\221\320\224 \320\220\320\273\320\272\320\276-\320\224\320\265\320\272\320\273\320\260\321\200\320\260\320\275\321\202", 0));
        label->setText(QApplication::translate("DialogSettings", "\320\237\321\203\321\202\321\214 \320\272 \321\204\320\260\320\271\320\273\321\203 \320\221\320\224", 0));
        btnBrowse->setText(QApplication::translate("DialogSettings", "\320\236\320\261\320\267\320\276\321\200\342\200\246", 0));
        label_3->setText(QApplication::translate("DialogSettings", "\320\237\320\260\321\200\320\276\320\273\321\214", 0));
        pswEdit->setInputMask(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogSettings: public Ui_DialogSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGSETTINGS_H
