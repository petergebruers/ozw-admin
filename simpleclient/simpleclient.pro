QT += widgets remoteobjects

SOURCES = main.cpp \
    dialog.cpp

CONFIG   -= app_bundle
DEFINES  += remote

LIBS += ../qt-openzwave/libqt-openzwave_remote.a
INCLUDEPATH += ../qt-openzwave ../open-zwave/cpp/src

REPC_REPLICA = ../qt-openzwave/OZWNodes.rep ../qt-openzwave/qtozwmanager.rep

# install
#target.path = $$[QT_INSTALL_EXAMPLES]/remoteobjects/modelviewclient
#INSTALLS += target

requires(qtConfig(treeview))

macx {
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.14
}

FORMS += \
    dialog.ui

HEADERS += \
    dialog.h
