set(GTEST_SRC googletest-release-1.8.0)

include(ExternalProject)

set(GTEST_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
STRING(REPLACE "-Werror" "" GTEST_CXX_FLAGS ${GTEST_CXX_FLAGS})

ExternalProject_Add(googletest
        PREFIX 3rdparty/googletest-src
        URL "${CMAKE_SOURCE_DIR}/3rdparty/${GTEST_SRC}.zip"
        INSTALL_COMMAND ""
        LOG_DOWNLOAD ON
        LOG_CONFIGURE ON
        LOG_BUILD ON
        CMAKE_ARGS
        -DBUILD_SHARED_LIBS=FALSE
        -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
        -Dgtest_force_shared_crt=ON
        -DCMAKE_CXX_FLAGS=${GTEST_CXX_FLAGS}
        -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
        -DCMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG=${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}
        -DCMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE=${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}
        -DCMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG=${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG}
        -DCMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE=${CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE}
        -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG=${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG}
        -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE=${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE})

ExternalProject_Get_Property(googletest binary_dir)
ExternalProject_Get_Property(googletest source_dir)

macro(add_gtest_lib NAME PATH)
    add_library(${NAME} UNKNOWN IMPORTED)
    set_target_properties(${NAME} PROPERTIES IMPORTED_LOCATION
            ${PATH}/${CMAKE_STATIC_LIBRARY_PREFIX}${NAME}${CMAKE_STATIC_LIBRARY_SUFFIX})
    add_dependencies(${NAME} googletest)
endmacro()
set(GTEST_PATH ${binary_dir}/googlemock/gtest)
if(MSVC_COMPILER)
    set(GTEST_PATH ${CMAKE_BINARY_DIR}/Publish/lib)
endif()
add_gtest_lib(gtest ${GTEST_PATH})
add_gtest_lib(gtest_main ${GTEST_PATH})

macro(add_gmock_lib NAME PATH)
    add_library(${NAME} UNKNOWN IMPORTED)
    set_target_properties(gmock PROPERTIES IMPORTED_LOCATION
            ${PATH}/${CMAKE_STATIC_LIBRARY_PREFIX}${NAME}${CMAKE_STATIC_LIBRARY_SUFFIX})
    add_dependencies(${NAME} googletest)
endmacro()
set(GMOCK_PATH ${binary_dir}/googlemock/${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
if(MSVC_COMPILER)
    set(GMOCK_PATH ${CMAKE_BINARY_DIR}/Publish/lib)
endif()
add_gmock_lib(gmock ${GMOCK_PATH})
add_gmock_lib(gmock_main ${GMOCK_PATH})

include_directories(${source_dir}/googlemock/include ${source_dir}/googletest/include)
enable_testing()
