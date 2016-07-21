/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_import;
    QAction *action_exit;
    QAction *action_clear;
    QAction *action_params;
    QAction *action_export;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *summaryTab;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *summaryTable;
    QWidget *detailTab;
    QVBoxLayout *verticalLayout;
    QTableWidget *detailTable;
    QWidget *tab;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *contragentsTable;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_4;
    QTableWidget *licensesTable;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(620, 370);
        action_import = new QAction(MainWindow);
        action_import->setObjectName(QStringLiteral("action_import"));
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QStringLiteral("action_exit"));
        action_clear = new QAction(MainWindow);
        action_clear->setObjectName(QStringLiteral("action_clear"));
        action_params = new QAction(MainWindow);
        action_params->setObjectName(QStringLiteral("action_params"));
        action_export = new QAction(MainWindow);
        action_export->setObjectName(QStringLiteral("action_export"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        summaryTab = new QWidget();
        summaryTab->setObjectName(QStringLiteral("summaryTab"));
        verticalLayout_2 = new QVBoxLayout(summaryTab);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        summaryTable = new QTableWidget(summaryTab);
        summaryTable->setObjectName(QStringLiteral("summaryTable"));

        verticalLayout_2->addWidget(summaryTable);

        tabWidget->addTab(summaryTab, QString());
        detailTab = new QWidget();
        detailTab->setObjectName(QStringLiteral("detailTab"));
        verticalLayout = new QVBoxLayout(detailTab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        detailTable = new QTableWidget(detailTab);
        detailTable->setObjectName(QStringLiteral("detailTable"));

        verticalLayout->addWidget(detailTable);

        tabWidget->addTab(detailTab, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout_3 = new QVBoxLayout(tab);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        contragentsTable = new QTableWidget(tab);
        contragentsTable->setObjectName(QStringLiteral("contragentsTable"));

        verticalLayout_3->addWidget(contragentsTable);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        verticalLayout_4 = new QVBoxLayout(tab_2);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        licensesTable = new QTableWidget(tab_2);
        licensesTable->setObjectName(QStringLiteral("licensesTable"));

        verticalLayout_4->addWidget(licensesTable);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 620, 21));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addSeparator();
        menu->addAction(action_exit);
        menu_2->addAction(action_import);
        menu_2->addSeparator();
        menu_2->addAction(action_clear);
        menu_3->addAction(action_export);
        menu_3->addSeparator();
        menu_3->addAction(action_params);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\237\320\276\320\274\320\276\321\211\320\275\320\270\320\272 \320\220\320\273\320\272\320\276-\320\224\320\265\320\272\320\273\320\260\321\200\320\260\320\275\321\202", 0));
        action_import->setText(QApplication::translate("MainWindow", "\320\230\320\274\320\277\320\276\321\200\321\202 \320\264\320\260\320\275\320\275\321\213\321\205\342\200\246", 0));
        action_exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", 0));
        action_clear->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", 0));
        action_params->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213\342\200\246", 0));
        action_export->setText(QApplication::translate("MainWindow", "\320\255\320\272\321\201\320\277\320\276\321\200\321\202", 0));
        tabWidget->setTabText(tabWidget->indexOf(summaryTab), QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260 \342\204\2261", 0));
        tabWidget->setTabText(tabWidget->indexOf(detailTab), QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260 \342\204\2262", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\232\320\276\320\275\321\202\321\200\320\260\320\263\320\265\320\275\321\202\321\213", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\320\233\320\270\321\206\320\265\320\275\320\267\320\270\320\270", 0));
        menu->setTitle(QApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", 0));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\224\320\260\320\275\320\275\321\213\320\265", 0));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\241\320\265\321\200\320\262\320\270\321\201", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
