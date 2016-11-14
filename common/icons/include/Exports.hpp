#pragma once

#if defined (_WIN32)
    #if defined(HackEdit_Common_Controls_EXPORTS)
        #define HACKEDIT_COMMON_CONTROLS_EXPORT __declspec(dllexport)
    #else
        #define HACKEDIT_COMMON_CONTROLS_EXPORT __declspec(dllimport)
    #endif
#else /* defined (_WIN32) */
    #define HACKEDIT_COMMON_CONTROLS_EXPORT
#endif
