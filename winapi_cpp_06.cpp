#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#pragma hdrstop

void main() {
    char buf[1024];

    STARTUPINFO si;
    SECURITY_ATTRIBUTES sa;
    SECURITY_DESCRIPTOR sd;
    PROCESS_INFORMATION pi;

    HANDLE newstdin, newstdout, read_stdout, write_stdin;
    InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION);
    SetSecurityDescriptorDacl(&sd, true, NULL, false);
    sa.lpSecurityDescriptor = &sd;

    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.bInheritHandle = true;


    if (!CreatePipe(&newstdin, &write_stdin, &sa, 0))
    {

        return;
    }

    if (!CreatePipe(&read_stdout, &newstdout, &sa, 0))
    {

        CloseHandle(newstdin);
        CloseHandle(write_stdin);
        return;
    }

    GetStartupInfo(&si);

    si.dwFlags = STARTF_USESTDHANDLES | STARTF_USESHOWWINDOW;
    si.wShowWindow = SW_HIDE;
    si.hStdOutput = newstdout;
    si.hStdError = newstdout;
    si.hStdInput = newstdin;

    TCHAR proc[] = L"C:\\proc\\tasks.exe";
    if (!CreateProcess(proc, NULL, NULL, NULL, TRUE, 0,
        NULL, NULL, &si, &pi))
    {

        CloseHandle(newstdin);
        CloseHandle(newstdout);
        CloseHandle(read_stdout);
        CloseHandle(write_stdin);
        return;
    }

    unsigned long exit = 0;
    unsigned long bread;
    unsigned long avail;

    memset(buf, 0, sizeof(buf));

    for (;;)
    {
        PeekNamedPipe(read_stdout, &buf, 1023, &bread, &avail, NULL);
        if (bread != 0)
        {
            memset(buf, 0, sizeof(buf));
            if (avail > 1023)
            {
                while (bread >= 1023)
                {
                    if (ReadFile(read_stdout, &buf, 1023, &bread, NULL)) {
                        printf("%s", buf);

                        memset(buf, 0, sizeof(buf));
                        break;
                    }
                }
            }
            else {
                if (ReadFile(read_stdout, &buf, 1023, &bread, NULL)) {
                    printf("%s", buf);
                    memset(buf, 0, sizeof(buf));
                    break;
                }
                printf("%s", buf);
                std::cout << buf;
            }
        }
        if (_kbhit())
        {
            memset(buf, 0, sizeof(buf));
            *buf = (char)_getche();
            WriteFile(write_stdin, buf, 2, &bread, NULL);
            if (*buf == '\r') {
                *buf = '\n';
                printf("%c", *buf);
                WriteFile(write_stdin, buf, 1, &bread, NULL);
            }
        }

    }
    std::cout << buf;

    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
    CloseHandle(newstdin);
    CloseHandle(newstdout);
    CloseHandle(read_stdout);
    CloseHandle(write_stdin);
}