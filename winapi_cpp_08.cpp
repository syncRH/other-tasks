#include <iostream>
#include <Windows.h>
#include <memoryapi.h>
#include <sstream>
#include <tchar.h>

#include <string>
#include <vector>


using namespace std;

string deCode(DWORD pr) {
    string str;
    if (pr & PAGE_EXECUTE)
        str += "EXECUTE";
    if (pr & PAGE_EXECUTE_READ)
        str += "EXECUTE READ";
    if (pr & PAGE_EXECUTE_READWRITE)
        str += "EXECUTE READWRITE";
    if (pr & PAGE_EXECUTE_WRITECOPY)
        str += "EXECUTE WRITECOPY";
    if (pr & PAGE_NOACCESS)
        str += "EXECUTE NOACCESS";
    if (pr & PAGE_READONLY)
        str += " READONLY ";
    if (pr & PAGE_READWRITE)
        str += " READWRITE ";
    if (pr & PAGE_WRITECOPY)
        str += " WRITECOPY ";
    if (pr & PAGE_TARGETS_INVALID)
        str += " TARGETS_INVALID ";
    if (pr & PAGE_TARGETS_NO_UPDATE)
        str += " TARGETS NO UPDATE ";
    if (pr & PAGE_GUARD)
        str += " GUARD ";
    if (pr & PAGE_NOCACHE)
        str += " NOCACHE ";
    if (pr & PAGE_WRITECOMBINE)
        str += " WRITECOMBINE ";
    return str;
}



void findfile(BYTE* pFind, DWORD mbi) {
    char* lib = 0;
    lib = (char*)pFind;
    WCHAR buffer[MAX_PATH];
    if ((int(pFind) % (0x10000) == 0) && ((mbi & MEM_COMMIT) == MEM_COMMIT)) {
        if (lib[0] == 'M' && lib[1] == 'Z') {
            DWORD res = GetModuleFileName(HMODULE((pFind)), buffer, sizeof(buffer));
            //  wcout << (pFind) << endl;
            wcout << buffer << endl;

        }
    }
}

int main()
{
    MEMORY_BASIC_INFORMATION mbi;
    BYTE* pCur = NULL;
    SIZE_T  res = VirtualQuery(LPCVOID(pCur), &mbi, sizeof(MEMORY_BASIC_INFORMATION));
    while (res > 0) {
        if (sizeof(MEMORY_BASIC_INFORMATION) == res) {
            findfile(pCur, mbi.State);
            pCur += mbi.RegionSize;
            cout << int(pCur) << "   " << mbi.BaseAddress << "   " << mbi.AllocationBase << "   " << mbi.AllocationProtect << "   " << mbi.RegionSize << "   " << mbi.State << "   " << mbi.Type << "   " << mbi.Protect << "   " << deCode(mbi.Protect) << endl;
            res = VirtualQuery((pCur), &mbi, sizeof(MEMORY_BASIC_INFORMATION));

        }
        else {
            break;
            //  GetLastError;
        }

    }
}