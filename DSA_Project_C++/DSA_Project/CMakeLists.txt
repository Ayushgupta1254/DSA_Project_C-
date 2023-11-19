cmake_minimum_required(VERSION 3.5)

project(DSA_Project VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Sql)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Sql)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        kathihomepage.cpp
        kathihomepage.h
        kathihomepage.ui
        laundryhomepage.cpp
        laundryhomepage.h
        laundryhomepage.ui
        databaseheader.h
        kathiorderingpage.cpp
        kathiorderingpage.h
        kathiorderingpage.ui
        adminlogin.cpp
        adminlogin.h
        adminlogin.ui
        adminpage.cpp
        adminpage.h
        adminpage.ui
        adminregstd.cpp
        adminregstd.h
        adminregstd.ui
        adminhistory.cpp
        adminhistory.h
        adminhistory.ui
        laundrydropver.cpp
        laundrydropver.h
        laundrydropver.ui
        databasemanager.h
        databasemanager.cpp
        laundryclothesstd.cpp
        laundryclothesstd.h
        laundryclothesstd.ui
        adminverlaundry.cpp
        adminverlaundry.h
        adminverlaundry.ui
        kathiadminlogin.cpp
        kathiadminlogin.h
        kathiadminlogin.ui
        kathiadminpage.cpp
        kathiadminpage.h
        kathiadminpage.ui
        kathiadminvieworders.cpp
        kathiadminvieworders.h
        kathiadminvieworders.ui
        kathiadminpendingorder.cpp
        kathiadminpendingorder.h
        kathiadminpendingorder.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(DSA_Project
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        kathihomepage.h kathihomepage.cpp kathihomepage.ui
        laundryhomepage.h laundryhomepage.cpp laundryhomepage.ui
        databaseheader.h
        kathiorderingpage.h kathiorderingpage.cpp kathiorderingpage.ui
        adminlogin.h adminlogin.cpp adminlogin.ui
        adminpage.h adminpage.cpp adminpage.ui
        adminregstd.h adminregstd.cpp adminregstd.ui
        adminhistory.h adminhistory.cpp adminhistory.ui
        laundrydropver.h laundrydropver.cpp laundrydropver.ui
        databasemanager.h
        databasemanager.cpp
        laundryclothesstd.h laundryclothesstd.cpp laundryclothesstd.ui
        adminverlaundry.h adminverlaundry.cpp adminverlaundry.ui
        kathiadminlogin.h kathiadminlogin.cpp kathiadminlogin.ui
        kathiadminpage.h kathiadminpage.cpp kathiadminpage.ui
        kathiadminvieworders.h kathiadminvieworders.cpp kathiadminvieworders.ui
        kathiadminpendingorder.h kathiadminpendingorder.cpp kathiadminpendingorder.ui


    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET DSA_Project APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(DSA_Project SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(DSA_Project
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(DSA_Project PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Sql)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.DSA_Project)
endif()
set_target_properties(DSA_Project PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS DSA_Project
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(DSA_Project)
endif()
