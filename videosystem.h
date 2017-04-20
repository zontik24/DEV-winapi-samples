#include <windows.h>
#include <QDebug>

class VideoSystem
{
public:

    //static void systemParametersInfo();

    static double getScreenHeight() {
        return GetSystemMetrics(SM_CYSCREEN);
    }

    static double getScreenWidth() {
        return GetSystemMetrics(SM_CXSCREEN);
    }

    static void screenSizeInInches()
    {
        HDC hdc = GetDC(GetDesktopWindow());
        DWORD ret = GetDeviceCaps(hdc, HORZSIZE);
        DWORD ret2 = GetDeviceCaps(hdc, VERTSIZE);
        qDebug() << "Your screen size in inches is " << ret/25.4 << " x " << ret2/25.4;
        ReleaseDC(GetDesktopWindow(), hdc);
    }

    static void screenSizeInPixels()
    {
        HDC hdc = GetDC(GetDesktopWindow());
        DWORD ret = GetDeviceCaps(hdc, HORZRES);
        DWORD ret2 = GetDeviceCaps(hdc, VERTRES);
        qDebug() << "Your screen size in pixels is " << ret << " x " << ret2;
        ReleaseDC(GetDesktopWindow(), hdc);
    }

    static bool enterFullscreen()
    {
        DEVMODE newSettings;
        EnumDisplaySettings ( NULL, 0, &newSettings );
        newSettings.dmPelsWidth  = 1024;
        newSettings.dmPelsHeight = 768;
        newSettings.dmBitsPerPel = 32;
        newSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
        ChangeDisplaySettings ( &newSettings, CDS_FULLSCREEN );
    }

    static void getScreenShot(void)
    {
        int x1, y1, x2, y2, w, h;

        // get screen dimensions
        x1  = GetSystemMetrics(SM_XVIRTUALSCREEN);
        y1  = GetSystemMetrics(SM_YVIRTUALSCREEN);
        x2  = GetSystemMetrics(SM_CXVIRTUALSCREEN);
        y2  = GetSystemMetrics(SM_CYVIRTUALSCREEN);
        w   = x2 - x1;
        h   = y2 - y1;

        // copy screen to bitmap
        HDC     hScreen = GetDC(NULL);
        HDC     hDC     = CreateCompatibleDC(hScreen);
        HBITMAP hBitmap = CreateCompatibleBitmap(hScreen, w, h);
        HGDIOBJ old_obj = SelectObject(hDC, hBitmap);
        BOOL    bRet    = BitBlt(hDC, 0, 0, w, h, hScreen, x1, y1, SRCCOPY);

        // save bitmap to clipboard
        OpenClipboard(NULL);
        EmptyClipboard();
        SetClipboardData(CF_BITMAP, hBitmap);
        CloseClipboard();

        // clean up
        SelectObject(hDC, old_obj);
        DeleteDC(hDC);
        ReleaseDC(NULL, hScreen);
        DeleteObject(hBitmap);
    }

    static void shadowOfDesktopIcons(bool value)
    {
        (value)
        ? SystemParametersInfo(SPI_SETDROPSHADOW, 0, FALSE, SPIF_SENDCHANGE)
        : SystemParametersInfo(SPI_SETDROPSHADOW, 0, (void*)TRUE, SPIF_SENDCHANGE);
    }
};
