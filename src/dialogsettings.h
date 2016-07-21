#ifndef DIALOGSETTINGS_H
#define DIALOGSETTINGS_H

#include <QDialog>
#include <QVariant>
#include <QFileInfo>
#include <QFileDialog>
#include "settings.h"

namespace Ui {
class DialogSettings;
}

class DialogSettings : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSettings(QWidget *parent = 0);
    ~DialogSettings();

private slots:
    void on_btnBrowse_clicked();
    void on_buttonBox_accepted();

private:
    Ui::DialogSettings *ui;
};

#endif // DIALOGSETTINGS_H
