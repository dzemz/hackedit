#pragma once

#if defined (_WIN32)
    #if defined(HackEdit_Common_Logging_EXPORTS)
        #define  HE_COMMON_LOGGING_EXPORT __declspec(dllexport)
    #else
        #define  HE_COMMON_LOGGING_EXPORT __declspec(dllimport)
    #endif
#else
    #define HE_COMMON_LOGGING_EXPORT
#endif
