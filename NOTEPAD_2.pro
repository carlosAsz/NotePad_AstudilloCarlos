QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    acerca.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    acerca.h \
    mainwindow.h

FORMS += \
    acerca.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recursos/resource.qrc \
    recursos/resource.qrc \
    resources.qrc

DISTFILES += \
    recursos/392530_add_create_cross_new_plus_icon.png \
    recursos/4831037_cancel_circle_close_delete_exit_icon.png \
    recursos/8664907_folder_open_document_icon.png \
    recursos/9054919_bx_save_icon.png \
    recursos/abrir-documento.png \
    recursos/disco-flexible.png \
    recursos/icons8-bloc-50.png \
    recursos/nuevo-documento.png \
    recursos/salida.png
