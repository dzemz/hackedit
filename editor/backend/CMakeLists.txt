project(HackEdit.Editor.Backend)

file(GLOB_RECURSE HEADER_FILES include/*.hpp)
file(GLOB_RECURSE SOURCE_FILES src/*.cpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${HEADER_FILES})
target_include_directories(${PROJECT_NAME} PUBLIC include)
target_include_directories(${PROJECT_NAME} PRIVATE include/hackedit/editor/backend)
target_link_libraries(${PROJECT_NAME} HackEdit.Common.Logging)
qt5_use_modules(${PROJECT_NAME} Core)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib/static
        PUBLIC_HEADER DESTINATION include)

install(DIRECTORY include/hackedit
        DESTINATION include)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()
