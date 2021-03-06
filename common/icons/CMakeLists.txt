project(HackEdit.Common.Icons)

set(QML_DIR ${QML_IMPORT_PATH}/HackEdit/Common/Icons)
make_directory(${QML_DIR})

file(GLOB_RECURSE HEADER_FILES include/*.hpp)
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
file(GLOB_RECURSE QML_FILES qml/*.qml)
file(GLOB_RECURSE QRC_FILES *.qrc)

configure_file(qmldir.in ${QML_DIR}/qmldir)
copy_qml_files(HackEdit.Common.Icons.CopyQml "${QML_FILES}" ${QML_DIR})

if(WIN32)
    set(OUTPUT_DIRECTORY ${QML_DIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIRECTORY}")
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIRECTORY}")
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG "${OUTPUT_DIRECTORY}")
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE "${OUTPUT_DIRECTORY}")
else()
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${QML_DIR})
endif()

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${HEADER_FILES} ${QML_FILES} ${QRC_FILES})
target_include_directories(${PROJECT_NAME} PRIVATE include)
qt5_use_modules(${PROJECT_NAME} Core Qml Quick)

install(TARGETS ${PROJECT_NAME} DESTINATION ${QML_INSTALL_DIR})
install(FILES ${QML_DIR}/qmldir DESTINATION ${QML_INSTALL_DIR})
install(FILES ${QML_FILES} DESTINATION ${QML_INSTALL_DIR})
