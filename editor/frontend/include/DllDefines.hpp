#pragma once

#if defined (_WIN32)
    #if defined(HackEdit_Editor_Frontend_EXPORTS)
        #define FRONTEND_EXPORT __declspec(dllexport)
    #else
        #define FRONTEND_EXPORT __declspec(dllimport)
    #endif
#else /* defined (_WIN32) */
    #define FRONTEND_EXPORT
#endif
