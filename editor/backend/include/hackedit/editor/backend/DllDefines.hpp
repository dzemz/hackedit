#pragma once

#if defined (_WIN32)
    #if defined(HackEdit_Editor_Backend_EXPORTS)
        #define  BACKEND_EXPORT __declspec(dllexport)
    #else
        #define  BACKEND_EXPORT __declspec(dllimport)
    #endif
#else /* defined (_WIN32) */
    #define BACKEND_EXPORT
#endif
