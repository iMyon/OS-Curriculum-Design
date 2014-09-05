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
    QAction *actionAuthor;
    QAction *actionVersion;
    QAction *actionSwitchUser;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_3;
    QTabWidget *tabs;
    QWidget *process;
    QTableWidget *tableProcess;
    QWidget *file;
    QTableWidget *tableFile;
    QWidget *deadlock;
    QLabel *LableDeadlock;
    QWidget *tableDeadlock;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuHelp;
    QMenu *menuAbout;
    QMenu *menuUser;

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
        actionAuthor = new QAction(osDesignClass);
        actionAuthor->setObjectName(QStringLiteral("actionAuthor"));
        actionVersion = new QAction(osDesignClass);
        actionVersion->setObjectName(QStringLiteral("actionVersion"));
        actionSwitchUser = new QAction(osDesignClass);
        actionSwitchUser->setObjectName(QStringLiteral("actionSwitchUser"));
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
        tableProcess = new QTableWidget(process);
        if (tableProcess->columnCount() < 4)
            tableProcess->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableProcess->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableProcess->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableProcess->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableProcess->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        tableProcess->setObjectName(QStringLiteral("tableProcess"));
        tableProcess->setGeometry(QRect(-1, -1, 521, 231));
        tableProcess->setFrameShape(QFrame::NoFrame);
        tableProcess->setLineWidth(0);
        tabs->addTab(process, QString());
        file = new QWidget();
        file->setObjectName(QStringLiteral("file"));
        tableFile = new QTableWidget(file);
        if (tableFile->columnCount() < 4)
            tableFile->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableFile->setHorizontalHeaderItem(0, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableFile->setHorizontalHeaderItem(1, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableFile->setHorizontalHeaderItem(2, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableFile->setHorizontalHeaderItem(3, __qtablewidgetitem7);
        tableFile->setObjectName(QStringLiteral("tableFile"));
        tableFile->setGeometry(QRect(-1, -1, 521, 231));
        tableFile->setContextMenuPolicy(Qt::CustomContextMenu);
        tabs->addTab(file, QString());
        deadlock = new QWidget();
        deadlock->setObjectName(QStringLiteral("deadlock"));
        LableDeadlock = new QLabel(deadlock);
        LableDeadlock->setObjectName(QStringLiteral("LableDeadlock"));
        LableDeadlock->setGeometry(QRect(3, 11, 132, 16));
        tableDeadlock = new QWidget(deadlock);
        tableDeadlock->setObjectName(QStringLiteral("tableDeadlock"));
        tableDeadlock->setGeometry(QRect(3, 30, 509, 191));
        tabs->addTab(deadlock, QString());

        verticalLayout_3->addWidget(tabs);

        osDesignClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(osDesignClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 539, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuUser = new QMenu(menuBar);
        menuUser->setObjectName(QStringLiteral("menuUser"));
        osDesignClass->setMenuBar(menuBar);
        QWidget::setTabOrder(tableProcess, tableFile);
        QWidget::setTabOrder(tableFile, tabs);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuUser->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionOpen);
        menuAbout->addAction(actionAuthor);
        menuAbout->addAction(actionVersion);
        menuUser->addAction(actionNew_user);
        menuUser->addAction(actionSwitchUser);

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
        actionAuthor->setText(QApplication::translate("osDesignClass", "\344\275\234\350\200\205(&A)", 0));
        actionVersion->setText(QApplication::translate("osDesignClass", "\347\211\210\346\234\254(&V)", 0));
        actionSwitchUser->setText(QApplication::translate("osDesignClass", "\345\210\207\346\215\242\347\224\250\346\210\267(&S)", 0));
        QTableWidgetItem *___qtablewidgetitem = tableProcess->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("osDesignClass", "\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableProcess->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("osDesignClass", "\347\212\266\346\200\201", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableProcess->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("osDesignClass", "\345\206\205\345\255\230", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableProcess->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("osDesignClass", "\347\224\250\346\210\267", 0));
        tabs->setTabText(tabs->indexOf(process), QApplication::translate("osDesignClass", "\350\277\233\347\250\213(&P)", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableFile->horizontalHeaderItem(0);
        ___qtablewidgetitem4->setText(QApplication::translate("osDesignClass", "\345\220\215\347\247\260", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableFile->horizontalHeaderItem(1);
        ___qtablewidgetitem5->setText(QApplication::translate("osDesignClass", "\346\227\245\346\234\237", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableFile->horizontalHeaderItem(2);
        ___qtablewidgetitem6->setText(QApplication::translate("osDesignClass", "\347\224\250\346\210\267", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableFile->horizontalHeaderItem(3);
        ___qtablewidgetitem7->setText(QApplication::translate("osDesignClass", "\346\235\203\351\231\220", 0));
        tabs->setTabText(tabs->indexOf(file), QApplication::translate("osDesignClass", "\346\226\207\344\273\266(&F)", 0));
        LableDeadlock->setText(QApplication::translate("osDesignClass", "\350\277\233\347\250\213\350\265\204\346\272\220\344\275\277\347\224\250\346\203\205\345\206\265\350\276\223\345\207\272\357\274\232", 0));
        tabs->setTabText(tabs->indexOf(deadlock), QApplication::translate("osDesignClass", "\346\255\273\351\224\201\346\250\241\346\213\237(&D)", 0));
        menuFile->setTitle(QApplication::translate("osDesignClass", "\346\226\207\344\273\266", 0));
        menuHelp->setTitle(QApplication::translate("osDesignClass", "\345\270\256\345\212\251", 0));
        menuAbout->setTitle(QApplication::translate("osDesignClass", "\345\205\263\344\272\216", 0));
        menuUser->setTitle(QApplication::translate("osDesignClass", "\347\224\250\346\210\267", 0));
    } // retranslateUi

};

namespace Ui {
    class osDesignClass: public Ui_osDesignClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSDESIGN_H
