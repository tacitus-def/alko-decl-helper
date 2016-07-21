/********************************************************************************
** Form generated from reading UI file 'wizardexport.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIZARDEXPORT_H
#define UI_WIZARDEXPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWizard>
#include <QtWidgets/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_WizardExport
{
public:
    QWizardPage *orgPage;
    QVBoxLayout *verticalLayout_4;
    QListView *orgList;
    QWizardPage *selectPage;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *decl11;
    QRadioButton *decl12;
    QWizardPage *declPage;
    QVBoxLayout *verticalLayout;
    QListView *declList;
    QWizardPage *exportPage;
    QVBoxLayout *verticalLayout_2;
    QListView *logView;

    void setupUi(QWizard *WizardExport)
    {
        if (WizardExport->objectName().isEmpty())
            WizardExport->setObjectName(QStringLiteral("WizardExport"));
        WizardExport->resize(593, 352);
        orgPage = new QWizardPage();
        orgPage->setObjectName(QStringLiteral("orgPage"));
        verticalLayout_4 = new QVBoxLayout(orgPage);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        orgList = new QListView(orgPage);
        orgList->setObjectName(QStringLiteral("orgList"));

        verticalLayout_4->addWidget(orgList);

        WizardExport->addPage(orgPage);
        selectPage = new QWizardPage();
        selectPage->setObjectName(QStringLiteral("selectPage"));
        verticalLayout_3 = new QVBoxLayout(selectPage);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        decl11 = new QRadioButton(selectPage);
        decl11->setObjectName(QStringLiteral("decl11"));

        verticalLayout_3->addWidget(decl11);

        decl12 = new QRadioButton(selectPage);
        decl12->setObjectName(QStringLiteral("decl12"));

        verticalLayout_3->addWidget(decl12);

        WizardExport->addPage(selectPage);
        declPage = new QWizardPage();
        declPage->setObjectName(QStringLiteral("declPage"));
        verticalLayout = new QVBoxLayout(declPage);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        declList = new QListView(declPage);
        declList->setObjectName(QStringLiteral("declList"));

        verticalLayout->addWidget(declList);

        WizardExport->addPage(declPage);
        exportPage = new QWizardPage();
        exportPage->setObjectName(QStringLiteral("exportPage"));
        verticalLayout_2 = new QVBoxLayout(exportPage);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        logView = new QListView(exportPage);
        logView->setObjectName(QStringLiteral("logView"));

        verticalLayout_2->addWidget(logView);

        WizardExport->addPage(exportPage);

        retranslateUi(WizardExport);

        QMetaObject::connectSlotsByName(WizardExport);
    } // setupUi

    void retranslateUi(QWizard *WizardExport)
    {
        WizardExport->setWindowTitle(QApplication::translate("WizardExport", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202 \320\264\320\260\320\275\320\275\321\213\321\205", 0));
        orgPage->setTitle(QApplication::translate("WizardExport", "\320\222\321\213\320\261\320\276\321\200 \320\276\321\200\320\263\320\260\320\275\320\270\320\267\320\260\321\206\320\270\320\270", 0));
        selectPage->setTitle(QApplication::translate("WizardExport", "\320\222\321\213\320\261\320\276\321\200 \320\262\320\270\320\264\320\260 \320\264\320\265\320\272\320\273\320\260\321\200\320\260\321\206\320\270\320\270", 0));
        selectPage->setSubTitle(QString());
        decl11->setText(QApplication::translate("WizardExport", "\320\224\320\265\320\272\320\273\320\260\321\200\320\260\321\206\320\270\321\217 \320\276\320\261 \320\276\320\261\321\212\320\265\320\274\320\260\321\205 \321\200\320\276\320\267\320\275\320\270\321\207\320\275\320\276\320\271 \320\277\321\200\320\276\320\264\320\260\320\266\320\270\n"
"\320\260\320\273\320\272\320\276\320\263\320\276\320\273\321\214\320\275\320\276\320\271 \320\270 \321\201\320\277\320\270\321\200\321\202\320\276\321\201\320\276\320\264\320\265\321\200\320\266\320\260\321\211\320\265\320\271 \320\277\321\200\320\276\320\264\321\203\320\272\321\206\320\270\320\270 (\321\204\320\276\321\200\320\274\320\260 \342\204\22611)", 0));
        decl12->setText(QApplication::translate("WizardExport", "\320\224\320\265\320\272\320\273\320\260\321\200\320\260\321\206\320\270\321\217 \320\276\320\261 \320\276\320\261\321\212\320\265\320\274\320\260\321\205 \320\277\321\200\320\276\320\264\320\260\320\266\320\270 \320\277\320\270\320\262\320\260\n"
"\320\270 \320\277\320\270\320\262\320\275\321\213\321\205 \320\275\320\260\320\277\320\270\321\202\320\272\320\276\320\262 (\321\204\320\276\321\200\320\274\320\260 \342\204\22612)", 0));
        declPage->setTitle(QApplication::translate("WizardExport", "\320\222\321\213\320\261\320\276\321\200 \320\264\320\265\320\272\320\273\320\260\321\200\320\260\321\206\320\270\320\270 \320\270\320\267 \320\220\320\273\320\272\320\276-\320\224\320\265\320\272\320\273\320\260\321\200\320\260\320\275\321\202", 0));
        exportPage->setTitle(QApplication::translate("WizardExport", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202 \320\262 \320\220\320\273\320\272\320\276-\320\224\320\265\320\272\320\273\320\260\321\200\320\260\320\275\321\202", 0));
    } // retranslateUi

};

namespace Ui {
    class WizardExport: public Ui_WizardExport {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIZARDEXPORT_H
