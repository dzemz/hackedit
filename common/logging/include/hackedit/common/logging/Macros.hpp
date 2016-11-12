#pragma once

#define BEGIN_HE_LOGGING_NAMESPACE namespace hackedit { namespace common { namespace logging {
#define END_HE_LOGGING_NAMESPACE }}}
#define USE_HE_LOGGING_NAMESPACE using namespace hackedit::common::logging;

#if defined (_WIN32)
    #if defined(HackEdit_Common_Logging_EXPORTS)
        #define  HE_COMMON_LOGGING_EXPORT __declspec(dllexport)
    #else
        #define  HE_COMMON_LOGGING_EXPORT __declspec(dllimport)
    #endif
#else
    #define HE_COMMON_LOGGING_EXPORT
#endif
