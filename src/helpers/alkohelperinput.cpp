#include "alkohelperinput.h"

AlkoHelperInput::AlkoHelperInput()
{
}

void AlkoHelperInput::highlightError(QWidget* widget, bool error)
{
    if (error) {
        widget->setStyleSheet("background-color: rgb(255, 200, 200);");
    }
    else {
        widget->setStyleSheet("");
    }
}

