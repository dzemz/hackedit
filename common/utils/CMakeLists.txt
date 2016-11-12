project(HackEdit.Common.Utils)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.hpp)

add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${HEADER_FILES})
include_directories(include)
target_include_directories(${PROJECT_NAME} PUBLIC include/)

install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
        PUBLIC_HEADER DESTINATION include)

install(DIRECTORY include/hackedit
        DESTINATION include)

