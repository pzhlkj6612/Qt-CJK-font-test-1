QT += core gui widgets

CONFIG += c++11

SOURCES += \
    main.cpp


# For target, both binary and debugging symbol go to target.path .
#   See also QTBUG-81354 for MinGW.
unix:!macx {
    # For AppImage.
    #   INSTALL_ROOT=AppDir

    target.path = "/usr/bin"
} else {
    target.path = "/"
}

INSTALLS *= target

# For AppImage.
#   INSTALL_ROOT=AppDir
unix:!macx {
    appdir_desktop.path = "/usr/share/applications"
    appdir_desktop.files = "$${_PRO_FILE_PWD_}/qt-cjk-font-test-1.AppDir$${appdir_desktop.path}/qt-cjk-font-test-1.desktop"

    INSTALLS *= appdir_desktop
}
