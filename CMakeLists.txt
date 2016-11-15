cmake_minimum_required(VERSION 3.2)

# get build number from number of commits
execute_process(COMMAND git rev-list --count HEAD
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
                OUTPUT_VARIABLE BUILD_NUMBER
                OUTPUT_STRIP_TRAILING_WHITESPACE)
project(HackEdit
        VERSION 0.1.0.${BUILD_NUMBER})

add_definitions(-DHACKEDIT_VERSION_MAJOR=${HackEdit_VERSION_MAJOR})
add_definitions(-DHACKEDIT_VERSION_MINOR=${HackEdit_VERSION_MINOR})

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/scripts/cmake" ${CMAKE_MODULE_PATH})
include(scripts/cmake/Macros.cmake)
include(scripts/cmake/Config.cmake)
include(scripts/cmake/Qt5Config.cmake)
include(scripts/cmake/Log4Cplus.cmake)

# Options
set_option(CMAKE_BUILD_TYPE Release STRING "Choose the type of build (Debug or Release).")
set_option(BUILD_EXAMPLES TRUE BOOL "TRUE to build the examples, FALSE to ignore them.")
set_option(BUILD_TESTS TRUE BOOL "TRUE to build the tests, FALSE to ignore them.")
set_option(BUILD_EDITOR TRUE BOOL "TRUE to build the editor component, FALSE to skip it.")
set_option(BUILD_APPLICATION TRUE BOOL "TRUE to build the application component, FALSE to skip it.")
set_option(ENABLE_COVERAGE FALSE BOOL "True to build code coverage targerts")

# enable test
if(BUILD_TESTS)
    include(scripts/cmake/GTest.cmake)
    if(ENABLE_COVERAGE AND GCC_COMPILER)
        include(scripts/cmake/CodeCoverage.cmake)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")        # debug, no optimisation
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --coverage")    # enabling coverage
        setup_target_for_coverage(coverage "make test" coverage)
    endif()
endif()

# sub-projects
file(GLOB_RECURSE COMMON_HEADERS common/include/*hpp)
include_directories(common/include)  # common header only library
add_subdirectory(common)
if(BUILD_EDITOR)
    add_subdirectory(editor)
endif()

# Summary
message(STATUS "Building HackEdit v${HackEdit_VERSION}")
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Build examples: ${BUILD_EXAMPLES}")
message(STATUS "Build tests: ${BUILD_TESTS}")
