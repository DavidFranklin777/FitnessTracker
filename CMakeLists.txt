cmake_minimum_required(VERSION 3.5)

project(MyFirstQt LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#${CMAKE_SOURCE_DIR} /D:/Softwares/Practice/QtGui/MyFirstQt/FindMQSQL.cmake

#list(CMAKE_MODULE_PATH APPEND "D:/Softwares/Practice/QtGui/MyFirstQt/FindMQSQL.cmake")

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Sql REQUIRED)
#find_package(Qt$ REQUIRED COMPONENTS Core Quick Sql)
#find_package(FindMYSQL.cmake)

file(GLOB_RECURSE SRCS *.cpp)
file(GLOB_RECURSE HDRS *.h)
file(GLOB_RECURSE UIS *.ui)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        SecondWindow.cpp
        SecondWindow.h
        SecondWindow.ui
        loginscreen.cpp
        loginscreen.h
        loginscreen.ui
        datacontroller.cpp
        datacontroller.h
        database.cpp
        database.h
        displayinformation.cpp
        displayinformation.h
        displayinformation.ui
        trackingmenu.cpp
        trackingmenu.h
        trackingmenu.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MyFirstQt
        ${SRCS} ${HDRS} ${UIS}
    )
else()
    if(ANDROID)
        add_library(MyFirstQt SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(MyFirstQt
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(MyFirstQt PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql )
