#ifndef DIALOGNEWCONTRAGENT_H
#define DIALOGNEWCONTRAGENT_H

#include <QDialog>
#include "contragent.h"

namespace Ui {
class DialogNewContragent;
}

class DialogNewContragent : public QDialog
{
    Q_OBJECT

public:
    explicit DialogNewContragent(QWidget *parent = 0);
    ~DialogNewContragent();

    Contragent *getContragent();

private:
    Ui::DialogNewContragent *ui;
};

#endif // DIALOGNEWCONTRAGENT_H
