set(LOG4CPLUS_SRC log4cplus)

include(ExternalProject)

set(BUILD_SHARED_LIBS FALSE)
if(GCC_COMPILER)
    set(LOG4CPLUS_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-terminate")
else()
    set(LOG4CPLUS_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    if(MSVC_COMPILER)
        set(BUILD_SHARED_LIBS TRUE)
    endif()
endif()

STRING(REPLACE "-Werror" "" LOG4CPLUS_CXX_FLAGS ${LOG4CPLUS_CXX_FLAGS})
ExternalProject_Add(Log4Cplus
        PREFIX 3rdparty/log4cplus-src
        URL "${CMAKE_SOURCE_DIR}/3rdparty/${LOG4CPLUS_SRC}.tar.gz"
        INSTALL_COMMAND ""
        LOG_DOWNLOAD ON
        LOG_CONFIGURE ON
        LOG_BUILD ON
        CMAKE_ARGS
            -DLOG4CPLUS_BUILD_TESTING=OFF
            -DBUILD_SHARED_LIBS=${BUILD_SHARED_LIBS}
            -DCMAKE_POSITION_INDEPENDENT_CODE=ON
            -DCMAKE_CXX_FLAGS=${LOG4CPLUS_CXX_FLAGS}
            -DCMAKE_CXX_STANDARD=${CMAKE_CXX_STANDARD}
            -DCMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE}
            -DUNICODE=OFF
            -DCMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG=${CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG}
            -DCMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE=${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE}
            -DCMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG=${CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG}
            -DCMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE=${CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE}
            -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG=${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG}
            -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE=${CMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE}
            -DLOG4CPLUS_ENABLE_DECORATED_LIBRARY_NAME=FALSE)

ExternalProject_Get_Property(Log4Cplus binary_dir)
ExternalProject_Get_Property(Log4Cplus source_dir)
add_library(log4cplus UNKNOWN IMPORTED)

if(MSVC_COMPILER AND CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_DEBUG_POSTFIX "D")
endif()

set(LOG4CPLUS_LIB ${CMAKE_STATIC_LIBRARY_PREFIX}log4cplus${CMAKE_DEBUG_POSTFIX}${CMAKE_STATIC_LIBRARY_SUFFIX})
if(MSVC_COMPILER)
    set(LOG4CPLUS_LIB_PATH ${CMAKE_BINARY_DIR}/Publish/lib/${LOG4CPLUS_LIB})
else()
    set(LOG4CPLUS_LIB_PATH ${binary_dir}/src/${LOG4CPLUS_LIB})
endif()

set_target_properties(log4cplus PROPERTIES IMPORTED_LOCATION ${LOG4CPLUS_LIB_PATH})
add_dependencies(log4cplus Log4Cplus)
include_directories(${source_dir}/include ${binary_dir}/include)
