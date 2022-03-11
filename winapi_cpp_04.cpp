#include <windows.h>
#include <iostream>
#include <dbt.h>

const GUID GUID_CLASS_USB_DEVICE =
{ 0x4d1e55b2, 0xf16f, 0x11cf, {0x88, 0xcb, 0x00, 0x11, 0x11, 0x00, 0x00, 0x30 } };

LRESULT CALLBACK messageDeviceChanged(HWND m_hwnd, UINT Message, WPARAM wParam, LPARAM lParam)
{

    switch (Message)
    {
    case WM_DEVICECHANGE: {
        switch (wParam)
        {
        case DBT_CONFIGCHANGECANCELED:
            MessageBox(m_hwnd, TEXT("DBT_CONFIGCHANGECANCELED"), TEXT("USBNotifyWin"), MB_OK);
            return true;
        case DBT_CONFIGCHANGED:
            MessageBox(m_hwnd, TEXT("DBT_CONFIGCHANGED"), TEXT("USBNotifyWin"), MB_OK);
            return true;
        case DBT_CUSTOMEVENT:
            MessageBox(m_hwnd, TEXT("DBT_CUSTOMEVENT"), TEXT("USBNotifyWin"), MB_OK);
            return true;
        case DBT_DEVICEARRIVAL:
            MessageBox(m_hwnd, TEXT("DBT_DEVICEARRIVAL"), TEXT("USBNotifyWin"), MB_OK);
            return true;
        case DBT_DEVICEQUERYREMOVE:
            MessageBox(m_hwnd, TEXT("DBT_DEVICEQUERYREMOVE"), TEXT("USBNotifyWin"), MB_OK);
            return BROADCAST_QUERY_DENY;                                 // посылаем win запрет на действие удаление устройства.
        case DBT_DEVICEQUERYREMOVEFAILED:
            MessageBox(m_hwnd, TEXT("DBT_DEVICEQUERYREMOVEFAILED"), TEXT("USBNotifyWin"), MB_OK);
            return true;
        case DBT_DEVICEREMOVEPENDING:
            MessageBox(m_hwnd, TEXT("DBT_DEVICEREMOVEPENDING"), TEXT("USBNotifyWin"), MB_OK);
            return true;
        case DBT_DEVICEREMOVECOMPLETE:
            MessageBox(m_hwnd, TEXT("DBT_DEVICEREMOVECOMPLETE"), TEXT("USBNotifyWin"), MB_OK);
            return true;
        case DBT_DEVICETYPESPECIFIC:
            MessageBox(m_hwnd, TEXT("DBT_DEVICETYPESPECIFIC"), TEXT("USBNotifyWin"), MB_OK);
            return true;
        case DBT_QUERYCHANGECONFIG:
            MessageBox(m_hwnd, TEXT("DBT_QUERYCHANGECONFIG"), TEXT("USBNotifyWin"), MB_OK);
            return true;
        case DBT_DEVNODES_CHANGED:
            MessageBox(m_hwnd, TEXT("DBT_DEVNODES_CHANGED"), TEXT("USBNotifyWin"), MB_OK);
            return true;
        case DBT_USERDEFINED:
            MessageBox(m_hwnd, TEXT("DBT_USERDEFINED"), TEXT("USBNotifyWin"), MB_OK);
            return true;
        default:
            MessageBox(m_hwnd, TEXT("WM_DEVICECHANGE received"), TEXT("USBNotifyWin"), MB_OK);
            return true;
        }
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(m_hwnd, Message, wParam, lParam);
    }
    return 0;

}

int main()
{
    HINSTANCE hInst = 0;
    WNDCLASSEX  WndClass;
    HWND m_hwnd;
    TCHAR szClassName[] = L"USBNotify";
    WndClass.cbSize = sizeof(WNDCLASSEX);
    WndClass.style = CS_HREDRAW | CS_VREDRAW;
    WndClass.lpfnWndProc = messageDeviceChanged;
    WndClass.cbClsExtra = 0;
    WndClass.cbWndExtra = 0;
    WndClass.hInstance = hInst;
    WndClass.hIcon = 0l;
    WndClass.hCursor = NULL;
    WndClass.hbrBackground = NULL;
    WndClass.lpszMenuName = NULL;
    WndClass.lpszClassName = szClassName;
    WndClass.hIconSm = 0l;

    DEV_BROADCAST_DEVICEINTERFACE DevDesc;
    DevDesc.dbcc_size = sizeof(DevDesc);
    DevDesc.dbcc_devicetype = DBT_DEVTYP_DEVICEINTERFACE;
    DevDesc.dbcc_classguid = GUID_CLASS_USB_DEVICE;

    RegisterClassEx(&WndClass);

    m_hwnd = CreateWindow(szClassName, szClassName, WS_OVERLAPPEDWINDOW, 0, 0, 1, 1, NULL, NULL, hInst, NULL);
    HDEVNOTIFY deviceNotify = RegisterDeviceNotification(&m_hwnd, &DevDesc, DEVICE_NOTIFY_WINDOW_HANDLE); // регистрируем USB устройство

    ShowWindow(m_hwnd, SW_SHOW);
    UpdateWindow(m_hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        //  TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return 0;
}