cmake_minimum_required(VERSION 3.16)

project(XML-EDITOR VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        ../external/Validity.cpp
        ../external/pretty.cpp
        ../external/treeparse.cpp
        ../external/Tree.cpp
        ../external/minifier.cpp
        ../external/Convert.cpp
        ../external/CompDec.cpp
        ../external/socialGraph.cpp
        ../external/graphParsing.cpp
        ../external/graphAnalysis.cpp
        ../external/postGraph.cpp
        ../external/Search.cpp
        ../external/drawGraph/drawGraph.cpp
)

# set(EXTERNAL_SOURCES

# )

set(EXTERNAL_HEADERS
    ../external/headers.h
    ../external/Validity.h
    ../external/pretty.h
    ../external/treeparse.h
    ../external/Tree.h
    ../external/minifier.hpp
    ../external/Convert.h
    ../external/CompDec.h
    ../external/socialGraph.h
    ../external/graphAnalysis.h
    ../external/graphParsing.hpp
    ../external/graph.hpp
    ../external/postGraph.h
    ../external/Search.h
    ../external/drawGraph/drawGraph.hpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(XML-EDITOR
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        leveltwo.cpp
        leveltwo.h
        leveltwo.ui
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET GUI-xml APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(XML-EDITOR SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(XML-EDITOR
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(XML-EDITOR PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.XML-EDITOR)
endif()
set_target_properties(XML-EDITOR PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS XML-EDITOR
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(XML-EDITOR)
endif()
