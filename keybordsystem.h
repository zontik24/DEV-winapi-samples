#include <QString>
#include <windows.h>

class KeybordSystem
{
private:

    QString keybordTypes[7] = {
       "IBM PC/XT or compatible (83-key) keyboard",
       "Olivetti 'ICO' (102-key) keyboard",
       "IBM PC/AT (84-key) or similar keyboard",
       "IBM enhanced (101- or 102-key) keyboard",
       "Nokia 1050 and similar keyboards",
       "Nokia 9140 and similar keyboards",
       "Japanese keyboard"
    };

public:

    QString getKeybordType()
    {
        return this->keybordTypes[GetKeyboardType(0)-1];
    }

    static bool getKeyStateCapsLock()
    {
        if(0 != (GetKeyState(VK_CAPITAL) & 0x0001)) {
            return true;
        }
        return false;
    }

    static bool getAsyncKeyStateLShift()
    {
        if(GetAsyncKeyState(VK_LSHIFT)) {
            return true;
        }
        return false;
    }
};
