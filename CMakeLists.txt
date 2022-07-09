cmake_minimum_required(VERSION 3.5)

set(TARGET_NAME Chess_v2)

project(${TARGET_NAME} VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    dev/main.cpp
    dev/UserInterface/MainWindow.cpp
    dev/UserInterface/MainWindow.h
    dev/UserInterface/MainWindow.ui
    dev/UserInterface/GameField/GameField.h
    dev/UserInterface/GameField/GameField.cpp
    dev/Core/Core.cpp
    dev/Core/Core.h
    dev/Core/Types/ChessCoordinate/ChessCoordinate.cpp
    dev/Core/Types/ChessCoordinate/ChessCoordinate.h
    dev/Core/Types/ChessFigureAbstract/ChessFigureAbstract.cpp
    dev/Core/Types/ChessFigureAbstract/ChessFigureAbstract.h
    dev/Core/Types/ChessFigurePawn/ChessFigurePawn.cpp
    dev/Core/Types/ChessFigurePawn/ChessFigurePawn.h
    dev/Core/Types/BaseTypes.h
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${TARGET_NAME}
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET Chess_v2 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(${TARGET_NAME} SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(${TARGET_NAME}
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(${TARGET_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(${TARGET_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${TARGET_NAME})
endif()

target_include_directories(${TARGET_NAME} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/dev
    ${CMAKE_CURRENT_SOURCE_DIR}/dev/Core
    ${CMAKE_CURRENT_SOURCE_DIR}/dev/Core/Types
    ${CMAKE_CURRENT_SOURCE_DIR}/dev/Core/Types/ChessCoordinate
    ${CMAKE_CURRENT_SOURCE_DIR}/dev/Core/Types/ChessFigureAbstract
    ${CMAKE_CURRENT_SOURCE_DIR}/dev/Core/Types/ChessFigurePawn
    ${CMAKE_CURRENT_SOURCE_DIR}/dev/UserInterface
    ${CMAKE_CURRENT_SOURCE_DIR}/dev/UserInterface/GameField
    ${CMAKE_CURRENT_SOURCE_DIR}/dev/Resources
    ${CMAKE_CURRENT_SOURCE_DIR}/dev/Resources/Pictures
)
