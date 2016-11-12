#pragma once

#define BEGIN_HE_UTILS_NAMESPACE namespace hackedit { namespace common { namespace utils {
#define END_HE_UTILS_NAMESPACE }}}
#define USE_HE_UTILS_NAMESPACE using namespace hackedit::common::utils;

#if defined (_WIN32)
    #if defined(HackEdit_Common_Utils_EXPORTS)
        #define  HE_COMMON_UTILS_EXPORT __declspec(dllexport)
    #else
        #define  HE_COMMON_UTILS_EXPORT __declspec(dllimport)
    #endif
#else /* defined (_WIN32) */
    #define HE_COMMON_UTILS_EXPORT
#endif
