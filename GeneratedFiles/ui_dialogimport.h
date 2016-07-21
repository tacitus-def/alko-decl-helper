/********************************************************************************
** Form generated from reading UI file 'dialogimport.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGIMPORT_H
#define UI_DIALOGIMPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogImport
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelFileName;
    QPushButton *btnBrowse;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QSpinBox *lineStart;
    QCheckBox *sepTab;
    QCheckBox *sepComma;
    QCheckBox *sepSemicolon;
    QSpacerItem *horizontalSpacer;
    QTableWidget *tblFields;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogImport)
    {
        if (DialogImport->objectName().isEmpty())
            DialogImport->setObjectName(QStringLiteral("DialogImport"));
        DialogImport->resize(646, 294);
        DialogImport->setModal(true);
        horizontalLayout = new QHBoxLayout(DialogImport);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, 20, -1);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, -1, 5);
        labelFileName = new QLabel(DialogImport);
        labelFileName->setObjectName(QStringLiteral("labelFileName"));
        labelFileName->setTextFormat(Qt::PlainText);

        horizontalLayout_3->addWidget(labelFileName);

        btnBrowse = new QPushButton(DialogImport);
        btnBrowse->setObjectName(QStringLiteral("btnBrowse"));
        btnBrowse->setMinimumSize(QSize(120, 0));
        btnBrowse->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_3->addWidget(btnBrowse);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, -1, 20);
        label = new QLabel(DialogImport);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_4->addWidget(label);

        lineStart = new QSpinBox(DialogImport);
        lineStart->setObjectName(QStringLiteral("lineStart"));
        lineStart->setMinimum(1);
        lineStart->setMaximum(10);
        lineStart->setValue(1);

        horizontalLayout_4->addWidget(lineStart);

        sepTab = new QCheckBox(DialogImport);
        sepTab->setObjectName(QStringLiteral("sepTab"));

        horizontalLayout_4->addWidget(sepTab);

        sepComma = new QCheckBox(DialogImport);
        sepComma->setObjectName(QStringLiteral("sepComma"));

        horizontalLayout_4->addWidget(sepComma);

        sepSemicolon = new QCheckBox(DialogImport);
        sepSemicolon->setObjectName(QStringLiteral("sepSemicolon"));

        horizontalLayout_4->addWidget(sepSemicolon);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_4);

        tblFields = new QTableWidget(DialogImport);
        tblFields->setObjectName(QStringLiteral("tblFields"));
        tblFields->setContextMenuPolicy(Qt::CustomContextMenu);
        tblFields->setSelectionMode(QAbstractItemView::SingleSelection);
        tblFields->setSelectionBehavior(QAbstractItemView::SelectColumns);
        tblFields->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(tblFields);


        horizontalLayout->addLayout(verticalLayout);

        buttonBox = new QDialogButtonBox(DialogImport);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Vertical);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout->addWidget(buttonBox);


        retranslateUi(DialogImport);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogImport, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogImport, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogImport);
    } // setupUi

    void retranslateUi(QDialog *DialogImport)
    {
        DialogImport->setWindowTitle(QApplication::translate("DialogImport", "\320\230\320\274\320\277\320\276\321\200\321\202 \320\264\320\260\320\275\320\275\321\213\321\205", 0));
        labelFileName->setText(QApplication::translate("DialogImport", "<\320\244\320\260\320\271\320\273 \320\275\320\265 \320\262\321\213\320\261\321\200\320\260\320\275>", 0));
        btnBrowse->setText(QApplication::translate("DialogImport", "\320\236\320\261\320\267\320\276\321\200", 0));
        label->setText(QApplication::translate("DialogImport", "\320\241\320\276 \321\201\321\202\321\200\320\276\320\272\320\270", 0));
        sepTab->setText(QApplication::translate("DialogImport", "\321\202\320\260\320\261\321\203\320\273\321\217\321\206\320\270\321\217", 0));
        sepComma->setText(QApplication::translate("DialogImport", "\320\267\320\260\320\277\321\217\321\202\320\260\321\217", 0));
        sepSemicolon->setText(QApplication::translate("DialogImport", "\321\202\320\276\321\207\320\272\320\260 \321\201 \320\267\320\260\320\277\321\217\321\202\320\276\320\271", 0));
    } // retranslateUi

};

namespace Ui {
    class DialogImport: public Ui_DialogImport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGIMPORT_H
