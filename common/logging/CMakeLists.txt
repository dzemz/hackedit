project(HackEdit.Common.Logging)

add_definitions(-Dlog4cplus_EXPORTS)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
file(GLOB_RECURSE HEADER_FILES include/*.hpp)
file(GLOB_RECURSE PRIVATE_HEADER_FILES src/*.hpp)

add_definitions(-DHackEdit_Common_Logging_EXPORTS=1)
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES} ${HEADER_FILES} ${PRIVATE_HEADER_FILES} ${COMMON_HEADERS})
set_property(TARGET ${PROJECT_NAME} PROPERTY POSITION_INDEPENDENT_CODE ON)
include_directories(include/)
target_include_directories(${PROJECT_NAME} PUBLIC include/)
target_link_libraries(${PROJECT_NAME} log4cplus ${CMAKE_THREAD_LIBS_INIT})
qt5_use_modules(${PROJECT_NAME} Core)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()
