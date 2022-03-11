// ПЕРЕДАТЧИК
#include <iostream>
#include <vector>
#include <cstring> 
#include <windows.h>
#include <string>
#include "tchar.h"
using namespace std;
TCHAR szName[] = L"testtesttest";
#define BUF_SIZE 256
const char* eventName = "eventnumberone";

int _tmain()
{
    HANDLE hMapFile;
    LPCTSTR pBuf;
    HANDLE hEvent = CreateEventA(NULL, TRUE, FALSE, eventName);
    hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, BUF_SIZE, szName);
    pBuf = (LPTSTR)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, BUF_SIZE);

    string str;
    cout << "transmitter started!" << endl;
    while (true)
    {
        cin >> str;
        TCHAR* szMsg = new TCHAR[str.size() + 1];
        szMsg[str.size()] = 0;
        std::copy(str.begin(), str.end(), szMsg);
        CopyMemory((PVOID)pBuf, szMsg, (_tcslen(szMsg) * sizeof(TCHAR)));
        SetEvent(hEvent);
        Sleep(2000);
    }
    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);
    return 1;
}

// ПРИЕМНИК

#include <iostream>
#include <vector>
#include <cstring>
#include <windows.h>
#include <string>
#include "tchar.h"
using namespace std;
const char* eventName = "eventnumberone";
#define BUF_SIZE 256
TCHAR szName[] = L"testtesttest";

int main(int argc, char* argv[])
{
    HANDLE hMapFile;
    LPCTSTR pBuf = nullptr;
    HANDLE hEvent = CreateEventA(NULL, TRUE, FALSE, eventName);
    hMapFile = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, szName);
    std::cout << "Reciever started!" << std::endl;
    while (WaitForSingleObject(hEvent, 5000000) == WAIT_OBJECT_0)
    {
        ResetEvent(hEvent);
        pBuf = (LPTSTR)MapViewOfFile(hMapFile, FILE_MAP_ALL_ACCESS, 0, 0, BUF_SIZE);
        wcout << pBuf;
        cout << endl;
    }
    UnmapViewOfFile(pBuf);
    CloseHandle(hMapFile);
    return 1;
}