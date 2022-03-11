// ПЕРВАЯ ЧАСТЬ - ПРОГРАММА КОТОРАЯ ОТПРАВЛЯЕТ

#include <Windows.h>
#include <tchar.h>

int CALLBACK wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR    szCmdLine, int       nCmdShow)
{
    MSG msg{};
    HWND hwnd{};
    WNDCLASSEX wc{ sizeof(WNDCLASSEX) };
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hInstance = hInstance;
    wc.lpfnWndProc = [](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) -> LRESULT
    {
        HWND Find = FindWindowA(0, "OS_LASTLAB_YLOV");
        switch (uMsg)
        {
        case WM_DESTROY:
        {
            PostQuitMessage(EXIT_SUCCESS);
        }
        case WM_CREATE:
            CreateWindowW(L"EDIT", L"", WS_BORDER | WS_CHILD | WS_VISIBLE, 10, 10, 300, 20, hWnd, (HMENU)2, NULL, NULL);

            CreateWindow(L"BUTTON",
                L"жмяк",
                WS_VISIBLE | WS_CHILD | WS_BORDER,
                300, 10, 70, 20,
                hWnd, (HMENU)1, NULL, NULL);
            break;

        case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            switch (wmId)
            {
            case 1: {
                int len = GetWindowTextLengthW(GetDlgItem(hWnd, 2)) + 1;
                wchar_t* text = new wchar_t[len];
                GetWindowTextW(GetDlgItem(hWnd, 2), text, int(GetWindowTextLengthW(GetDlgItem(hWnd, 2)) + 1));

                LPCTSTR lpszString = text;
                COPYDATASTRUCT cds;
                cds.dwData = 1;
                cds.cbData = sizeof(TCHAR) * (_tcslen(lpszString) + 1);
                cds.lpData = (PVOID)lpszString;
                SendMessage(Find, WM_COPYDATA, (WPARAM)Find, (LPARAM)(LPVOID)&cds);
            }
            }
        }

        return 0;
        }
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    };
    wc.lpszClassName = L"OS_LASTLAB";
    wc.lpszMenuName = nullptr;
    wc.style = CS_VREDRAW | CS_HREDRAW;

    if (!RegisterClassEx(&wc))
        return EXIT_FAILURE;

    hwnd = CreateWindow(wc.lpszClassName, L"OS_LASTLAB", WS_OVERLAPPEDWINDOW, 0, 0, 600, 600, nullptr, nullptr, wc.hInstance, nullptr);
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}

// ВТОРАЯ ЧАСТЬ - ПРОГРАММА КОТОРАЯ ПРИНИМАЕТ 

#include <Windows.h>

LRESULT APIENTRY    WndProc(HWND, UINT, WPARAM, LPARAM);
int CALLBACK wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR    szCmdLine, int       nCmdShow)
{

    MSG msg{};
    HWND hwnd{};
    WNDCLASSEX wc{ sizeof(WNDCLASSEX) };
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hInstance = hInstance;
    wc.lpfnWndProc = [](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) -> LRESULT
    {
        switch (uMsg)
        {
        case WM_DESTROY:
        {
            PostQuitMessage(EXIT_SUCCESS);
        }
        case WM_COPYDATA: {
            COPYDATASTRUCT* pcds = (COPYDATASTRUCT*)lParam;
            if (pcds->dwData == 1)
            {
                LPCTSTR lpszString = (LPCTSTR)(pcds->lpData);
                MessageBoxW(NULL, lpszString, L"MsgFromTextBox", MB_OK);
            }
        }
                        return 0;
        }
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    };
    wc.lpszClassName = L"OS_LASTLAB_YLOV";
    wc.lpszMenuName = nullptr;
    wc.style = CS_VREDRAW | CS_HREDRAW;

    if (!RegisterClassEx(&wc))
        return EXIT_FAILURE;

    hwnd = CreateWindow(wc.lpszClassName, L"OS_LASTLAB_YLOV", WS_OVERLAPPEDWINDOW, 0, 0, 600, 600, nullptr, nullptr, wc.hInstance, nullptr);
    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);

    while (GetMessage(&msg, nullptr, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (int)msg.wParam;
}