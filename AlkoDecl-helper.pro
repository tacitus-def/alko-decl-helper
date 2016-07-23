#-------------------------------------------------
#
# Project created by QtCreator 2014-01-20T21:52:05
#
#-------------------------------------------------

QT       += core gui sql xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AlkoDecl-helper
TEMPLATE = app

SOURCES += src/main.cpp\
    src/mainwindow.cpp \
    src/dialogimport.cpp \
    src/csvreader.cpp \
    src/contragent.cpp \
    src/product.cpp \
    src/license.cpp \
    src/processdata.cpp \
    src/productcode.cpp \
    src/db.cpp \
    src/inputdata.cpp \
    src/dialogsettings.cpp \
    src/settings.cpp \
    src/wizardexport.cpp \
    src/export/wizardpagedeclproperties.cpp \
    src/helpers/alkohelperinput.cpp \
    src/oborot.cpp \
    src/qtablecontragentswidgetitem.cpp \
    src/exportcontragents.cpp \
    src/summary.cpp \
    src/calculator.cpp \
    src/qtablesummarywidgetitem.cpp \
    src/dialognewcontragent.cpp \
    src/dialognewsummary.cpp \
    src/alkodb.cpp \
    src/qtablefloatwidgetitem.cpp \
    src/alkodata.cpp

HEADERS  += src/mainwindow.h \
    src/dialogimport.h \
    src/csvreader.h \
    src/contragent.h \
    src/product.h \
    src/license.h \
    src/processdata.h \
    src/productcode.h \
    src/db.h \
    src/inputdata.h \
    src/dialogsettings.h \
    src/settings.h \
    src/wizardexport.h \
    src/export/wizardpagedeclproperties.h \
    src/helpers/alkohelperinput.h \
    src/oborot.h \
    src/nonedittablecolumndelegate.h \
    src/qtablecontragentswidgetitem.h \
    src/exportcontragents.h \
    src/summary.h \
    src/calculator.h \
    src/qtablesummarywidgetitem.h \
    src/dialognewcontragent.h \
    src/dialognewsummary.h \
    src/alkodb.h \
    src/qtablefloatwidgetitem.h \
    src/alkodata.h

FORMS    += src/mainwindow.ui \
    src/dialogimport.ui \
    src/dialogsettings.ui \
    src/wizardexport.ui \
    src/export/wizardpagedeclproperties.ui \
    src/dialognewcontragent.ui \
    src/dialognewsummary.ui

OTHER_FILES += \
    res/db.sqlite

RESOURCES +=

copydata.commands = $(COPY_FILE) \"$$PWD/res/db.sqlite\" \"$$OUT_PWD\"
first.depends = all copydata
export(first.depends)
export(copydata.commands)
QMAKE_EXTRA_TARGETS += first copydata
