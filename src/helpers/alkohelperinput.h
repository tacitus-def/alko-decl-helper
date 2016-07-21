#ifndef ALKOHELPERINPUT_H
#define ALKOHELPERINPUT_H

#include <QWidget>

class AlkoHelperInput
{
public:
    AlkoHelperInput();
    static void highlightError(QWidget *widget, bool error);
};

#endif // ALKOHELPERINPUT_H
