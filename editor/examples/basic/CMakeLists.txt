# Find Qt5
set(QT_MIN_VERSION 5.2)
set(QT_LIBRARIES Core Qml Quick Gui QuickControls2 Widgets)
find_package(Qt5 ${QT_MIN_VERSION} CONFIG REQUIRED COMPONENTS ${QT_LIBRARIES})
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

# Add basic example executable
project(Examples.Editor.Basic)
file(GLOB_RECURSE SOURCE_FILES *.cpp)
file(GLOB_RECURSE QRC_FILES *.qrc)
file(GLOB_RECURSE QML_FILES *.qml)
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${QRC_FILES} ${QML_FILES})
target_link_libraries(${PROJECT_NAME} HackEdit.Common.Logging)
qt5_use_modules(${PROJECT_NAME} ${QT_LIBRARIES})
