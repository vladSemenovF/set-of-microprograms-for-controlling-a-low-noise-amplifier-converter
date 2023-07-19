/********************************************************************************
** Form generated from reading UI file 'QtWidgetsApplicationGraphicForTheOperator.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETSAPPLICATIONGRAPHICFORTHEOPERATOR_H
#define UI_QTWIDGETSAPPLICATIONGRAPHICFORTHEOPERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsApplicationGraphicForTheOperatorClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtWidgetsApplicationGraphicForTheOperatorClass)
    {
        if (QtWidgetsApplicationGraphicForTheOperatorClass->objectName().isEmpty())
            QtWidgetsApplicationGraphicForTheOperatorClass->setObjectName(QStringLiteral("QtWidgetsApplicationGraphicForTheOperatorClass"));
        QtWidgetsApplicationGraphicForTheOperatorClass->resize(600, 400);
        menuBar = new QMenuBar(QtWidgetsApplicationGraphicForTheOperatorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtWidgetsApplicationGraphicForTheOperatorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtWidgetsApplicationGraphicForTheOperatorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtWidgetsApplicationGraphicForTheOperatorClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtWidgetsApplicationGraphicForTheOperatorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtWidgetsApplicationGraphicForTheOperatorClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtWidgetsApplicationGraphicForTheOperatorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtWidgetsApplicationGraphicForTheOperatorClass->setStatusBar(statusBar);

        retranslateUi(QtWidgetsApplicationGraphicForTheOperatorClass);

        QMetaObject::connectSlotsByName(QtWidgetsApplicationGraphicForTheOperatorClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtWidgetsApplicationGraphicForTheOperatorClass)
    {
        QtWidgetsApplicationGraphicForTheOperatorClass->setWindowTitle(QApplication::translate("QtWidgetsApplicationGraphicForTheOperatorClass", "QtWidgetsApplicationGraphicForTheOperator", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsApplicationGraphicForTheOperatorClass: public Ui_QtWidgetsApplicationGraphicForTheOperatorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETSAPPLICATIONGRAPHICFORTHEOPERATOR_H
