#pragma once

#if defined (_WIN32)
    #if defined(HackEdit_Common_Icons_EXPORTS)
        #define HACKEDIT_COMMON_ICONS_EXPORT __declspec(dllexport)
    #else
        #define HACKEDIT_COMMON_ICONS_EXPORT __declspec(dllimport)
    #endif
#else /* defined (_WIN32) */
    #define HACKEDIT_COMMON_ICONS_EXPORT
#endif
