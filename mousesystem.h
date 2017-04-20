#include <istream>
#include <windows.h>
#include <qdebug.h>

class MouseSystem
{
public:

    static void swapMouseButton(bool flag)
    {
        SwapMouseButton(flag);
    }

    static void clipCursorInRect(double positionX, double positionY, double width, double height)
    {
        RECT r = {positionX, positionY, width, height};
        ClipCursor( &r );
        std::cin.ignore();
    }

    static void setCursorPos(double positionX, double positionY)
    {
        SetCursorPos(positionX, positionY);
    }

    static bool setMouseSensativity(int speed)
    {
        if(speed > 0 && speed < 21)
        {
            SystemParametersInfo(SPI_SETMOUSESPEED, 0, (void*)speed, 0);
            return true;
        }
        return false;
    }
};
