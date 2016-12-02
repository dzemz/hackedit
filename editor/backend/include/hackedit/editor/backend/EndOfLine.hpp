#pragma once

#include <hackedit/common/HackEditNamespace.hpp>
#include <QtCore/QObject>

BEGIN_HACKEDIT_NAMESPACE2(Editor, Backend)

class EndOfLine: public QObject
{
    Q_OBJECT
public:
    enum Convention {
        System,
        Linux,
        Mac,
        Windows
    }; Q_ENUM(Convention)

    static QString separator(Convention convention) {
        QString retVal;
        switch (convention) {
            case System:
                #if defined(Q_OS_WIN32)
                    retVal = lineSeparator(Windows);
                #elif defined(Q_OS_MAC)
                    retVal = lineSeparator(Mac);
                #else
                    retVal = separator(Linux);
                #endif
                break;
            case Linux:
                retVal = "\n";
                break;
            case Mac:
                retVal = "\r";
                break;
            case Windows:
                retVal = "\r\n";
                break;
        }
        return retVal;
    }
};

END_HACKEDIT_NAMESPACE2
