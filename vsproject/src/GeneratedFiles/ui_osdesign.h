/********************************************************************************
** Form generated from reading UI file 'osdesign.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSDESIGN_H
#define UI_OSDESIGN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_osDesignClass
{
public:
    QAction *actionOpen;
    QAction *actionNew_user;
    QAction *actionA;
    QAction *actionV;
    QAction *actionS;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabs;
    QWidget *process;
    QTableWidget *tableWidget_2;
    QWidget *file;
    QTableWidget *tableWidget;
    QWidget *deadlock;
    QLabel *label;
    QWidget *widget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;

    void setupUi(QMainWindow *osDesignClass)
    {
        if (osDesignClass->objectName().isEmpty())
            osDesignClass->setObjectName(QStringLiteral("osDesignClass"));
        osDesignClass->resize(539, 292);
        osDesignClass->setMinimumSize(QSize(539, 292));
        osDesignClass->setMaximumSize(QSize(539, 292));
        actionOpen = new QAction(osDesignClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionNew_user = new QAction(osDesignClass);
        actionNew_user->setObjectName(QStringLiteral("actionNew_user"));
        actionA = new QAction(osDesignClass);
        actionA->setObjectName(QStringLiteral("actionA"));
        actionV = new QAction(osDesignClass);
        actionV->setObjectName(QStringLiteral("actionV"));
        actionS = new QAction(osDesignClass);
        actionS->setObjectName(QStringLiteral("actionS"));
        centralWidget = new QWidget(osDesignClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setMinimumSize(QSize(539, 269));
        centralWidget->setMaximumSize(QSize(539, 269));
        verticalLayout_3 = new QVBoxLayout(centralWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        tabs = new QTabWidget(centralWidget);
        tabs->setObjectName(QStringLiteral("tabs"));
        tabs->setMinimumSize(QSize(521, 251));
        tabs->setMaximumSize(QSize(521, 251));
        process = new QWidget();
        process->setObjectName(QStringLiteral("process"));
        tableWidget_2 = new QTableWidget(process);
        if (tableWidget_2->columnCount() < 4)
            tableWidget_2->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(-1, -1, 521, 231));
        tableWidget_2->setFrameShape(QFrame::NoFrame);
        tableWidget_2->setLineWidth(0);
        tabs->addTab(process, QString());
        file = new QWidget();
        file->setObjectName(QStringLiteral("file"));
        tableWidget = new QTableWidget(file);
        if (tableWidget->columnCount() < 4)
            tableWidget->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(-1, -1, 521, 231));
        tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        tabs->addTab(file, QString());
        deadlock = new QWidget();
        deadlock->setObjectName(QStringLiteral("deadlock"));
        label = new QLabel(deadlock);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(3, 11, 132, 16));
        widget = new QWidget(deadlock);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(3, 30, 509, 191));
        tabs->addTab(deadlock, QString());

        verticalLayout_3->addWidget(tabs);

        osDesignClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(osDesignClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 539, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        osDesignClass->setMenuBar(menuBar);
        QWidget::setTabOrder(tableWidget_2, tableWidget);
        QWidget::setTabOrder(tableWidget, tabs);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(actionOpen);
        menu_3->addAction(actionA);
        menu_3->addAction(actionV);
        menu_4->addAction(actionNew_user);
        menu_4->addAction(actionS);

        retranslateUi(osDesignClass);

        tabs->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(osDesignClass);
    } // setupUi

    void retranslateUi(QMainWindow *osDesignClass)
    {
        osDesignClass->setWindowTitle(QApplication::translate("osDesignClass", "osDesign", 0));
        actionOpen->setText(QApplication::translate("osDesignClass", "\346\211\223\345\274\200(&O)", 0));
        actionOpen->setIconText(QApplication::translate("osDesignClass", "\346\211\223\345\274\200", 0));
        actionNew_user->setText(QApplication::translate("osDesignClass", "\346\226\260\345\273\272\347\224\250\346\210\267(&N)", 0));
        actionNew_user->setIconText(QApplication::translate("osDesignClass", "\346\226\260\345\273\272\347\224\250\346\210\267", 0));
        actionA->setText(QApplication::translate("osDesignClass", "\344\275\234\350\200\205(&A)", 0));
        actionV->setText(QApplication::translate("osDesignClass", "\347\211\210\346\234\254(&V)", 0));
        actionS->setText(QApplication::translate("osDesignClass", "\345\210\207\346\215\242\347\224\250\346\210\267(&S)", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("osDesignClass", "\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_2->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("osDesignClass", "\347\212\266\346\200\201", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_2->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("osDesignClass", "\345\206\205\345\255\230", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_2->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("osDesignClass", "\347\224\250\346\210\267", 0));
        tabs->setTabText(tabs->indexOf(process), QApplication::translate("osDesignClass", "\350\277\233\347\250\213(&P)", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("osDesignClass", "\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("osDesignClass", "\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("osDesignClass", "\347\224\250\346\210\267", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("osDesignClass", "\346\235\203\351\231\220", 0));
        tabs->setTabText(tabs->indexOf(file), QApplication::translate("osDesignClass", "\346\226\207\344\273\266(&F)", 0));
        label->setText(QApplication::translate("osDesignClass", "\350\277\233\347\250\213\350\265\204\346\272\220\344\275\277\347\224\250\346\203\205\345\206\265\350\276\223\345\207\272\357\274\232", 0));
        tabs->setTabText(tabs->indexOf(deadlock), QApplication::translate("osDesignClass", "\346\255\273\351\224\201\346\250\241\346\213\237", 0));
        menu->setTitle(QApplication::translate("osDesignClass", "\346\226\207\344\273\266", 0));
        menu_2->setTitle(QApplication::translate("osDesignClass", "\345\270\256\345\212\251", 0));
        menu_3->setTitle(QApplication::translate("osDesignClass", "\345\205\263\344\272\216", 0));
        menu_4->setTitle(QApplication::translate("osDesignClass", "\347\224\250\346\210\267", 0));
    } // retranslateUi

};

namespace Ui {
    class osDesignClass: public Ui_osDesignClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSDESIGN_H
