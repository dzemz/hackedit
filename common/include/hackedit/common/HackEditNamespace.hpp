#pragma once

#define BEGIN_HACKEDIT_NAMESPACE2(n1, n2) namespace HackEdit { namespace n1 { namespace n2 {
#define END_HACKEDIT_NAMESPACE2 }}}
#define USE_HACKEDIT_NAMESPACE2(n1, n2) using namespace HackEdit::n1::n2;