#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtWidgetsApplicationGraphicForTheOperator.h"

class QtWidgetsApplicationGraphicForTheOperator : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplicationGraphicForTheOperator(QWidget *parent = nullptr);
    ~QtWidgetsApplicationGraphicForTheOperator();

private:
    Ui::QtWidgetsApplicationGraphicForTheOperatorClass ui;
};
