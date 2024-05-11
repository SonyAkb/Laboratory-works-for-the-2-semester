QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    change_the_directory.cpp \
    main.cpp \
    main_window_1.cpp \
    save_data_window.cpp

HEADERS += \
    change_the_directory.h \
    house.h \
    main_window_1.h \
    other_functoins.h \
    prices.h \
    save_data_window.h

FORMS += \
    change_the_directory.ui \
    main_window_1.ui \
    save_data_window.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    all_the_prices
