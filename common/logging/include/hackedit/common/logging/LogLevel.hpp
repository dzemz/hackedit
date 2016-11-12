#pragma once

#include <hackedit/common/HackEditNamespace.hpp>

BEGIN_HACKEDIT_NAMESPACE2(Common, Logging)

enum class LogLevel
{
    Trace = 0,
    Debug,
    Info,
    Warning,
    Error,
    Fatal,
};

END_HACKEDIT_NAMESPACE2
