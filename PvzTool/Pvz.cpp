#include "stdafx.h"
#include "Pvz.h"
#include "data.h"

CPvz::CPvz()
{
}


CPvz::~CPvz()
{
}

// 获取游戏的 PID
DWORD CPvz::GetGamePid()
{
    HWND hWnd = ::FindWindow(NULL, GAME_NAME);

    if (hWnd == NULL)
    {
        return -1;
    }

    DWORD dwPid = 0;
    ::GetWindowThreadProcessId(hWnd, &dwPid);

    return dwPid;
}


// 修改阳光的值
VOID CPvz::ModifySunValue(DWORD dwSun)
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);

    // 00731C50 00731CDC
    // 00475373 - mov edi, [esi + 00000868] ESI = 0286B490
    // 0044BA45 - add[edi + 00005578], eax EDI = 1E4A0B40

    DWORD dwNum = 0;
    ReadProcessMemory(hProcess, (LPCVOID)BASE_ADDRESS, &dwNum, sizeof(DWORD), NULL);
    ReadProcessMemory(hProcess, (LPCVOID)(dwNum + board), &dwNum, sizeof(DWORD), NULL);

    WriteProcessMemory(hProcess, (LPVOID)(dwNum + sun), &dwSun, sizeof(DWORD), NULL);

    CloseHandle(hProcess);
}


// 种植冷却
VOID CPvz::NoCd(DWORD Enable)
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
    if (hProcess == NULL)
    {
        MessageBox(NULL, L"无法打开游戏进程", L"错误", MB_OK | MB_ICONERROR);
        return;
    }

    if (Enable)
    {
        char* patch = "\x39\x47\x28";
        WriteProcessMemory(hProcess, (LPVOID)0x004958C2, patch, 3, NULL);
    }
    else
    {
        char* patch = "\x3B\x47\x28";
        WriteProcessMemory(hProcess, (LPVOID)0x004958C2, patch, 3, NULL);
    }

    CloseHandle(hProcess);
}

// 连续铲子
VOID CPvz::LockShovel(DWORD Enable)
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
    if (hProcess == NULL)
    {
        MessageBox(NULL, L"无法打开游戏进程", L"错误", MB_OK | MB_ICONERROR);
        return;
    }

    if (Enable)
    {
        BYTE patch[] = { 0x39 };
        WriteProcessMemory(hProcess, (LPVOID)0x004158b3, patch, sizeof(patch), NULL);

    }
    else
    {
        BYTE patch[] = { 0x89 };
        WriteProcessMemory(hProcess, (LPVOID)0x004158b3, patch, sizeof(patch), NULL);
    }
    CloseHandle(hProcess);
}


// 无限花肥
VOID CPvz::Fertilizer(DWORD Enable)
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
    if (hProcess == NULL)
    {
        MessageBox(NULL, L"无法打开游戏进程", L"错误", MB_OK | MB_ICONERROR);
        return;
    }

    if (Enable)
    {
        //固定数量
        BYTE patch[] = { 0x39 };
        WriteProcessMemory(hProcess, (LPVOID)0x0052da8b, patch, sizeof(patch), NULL);

        //设置数量
        DWORD value = 1000 + 20;
        DWORD dwNum = 0;
        ReadProcessMemory(hProcess, (LPCVOID)BASE_ADDRESS, &dwNum, sizeof(DWORD), NULL);
        ReadProcessMemory(hProcess, (LPCVOID)(dwNum + user_data), &dwNum, sizeof(DWORD), NULL);

        WriteProcessMemory(hProcess, (LPVOID)(dwNum + twiddydinky + 14 * 4), &value, sizeof(DWORD), NULL);
    }
    else
    {
        BYTE patch[] = { 0xff };
        WriteProcessMemory(hProcess, (LPVOID)0x0052da8b, patch, sizeof(patch), NULL);
    }
    CloseHandle(hProcess);
}

// 无限树肥
VOID CPvz::TreeFood(DWORD Enable)
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
    if (hProcess == NULL)
    {
        MessageBox(NULL, L"无法打开游戏进程", L"错误", MB_OK | MB_ICONERROR);
        return;
    }

    if (Enable)
    {
        //固定数量
        BYTE patch[] = { 0x39 };
        WriteProcessMemory(hProcess, (LPVOID)0x004311ed, patch, sizeof(patch), NULL);

        //设置数量
        DWORD value = 1000 + 10;
        DWORD dwNum = 0;
        ReadProcessMemory(hProcess, (LPCVOID)BASE_ADDRESS, &dwNum, sizeof(DWORD), NULL);
        ReadProcessMemory(hProcess, (LPCVOID)(dwNum + user_data), &dwNum, sizeof(DWORD), NULL);

        WriteProcessMemory(hProcess, (LPVOID)(dwNum + twiddydinky + 28 * 4), &value, sizeof(DWORD), NULL);
    }
    else
    {
        BYTE patch[] = { 0xff };
        WriteProcessMemory(hProcess, (LPVOID)0x004311ed, patch, sizeof(patch), NULL);
    }
    CloseHandle(hProcess);
}

// 无限杀虫剂
VOID CPvz::BugSpray(DWORD Enable)
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
    if (hProcess == NULL)
    {
        MessageBox(NULL, L"无法打开游戏进程", L"错误", MB_OK | MB_ICONERROR);
        return;
    }

    if (Enable)
    {
        //固定数量
        BYTE patch[] = { 0x39 };
        WriteProcessMemory(hProcess, (LPVOID)0x0052db83, patch, sizeof(patch), NULL);

        //设置数量
        DWORD value = 1000 + 20;
        DWORD dwNum = 0;
        ReadProcessMemory(hProcess, (LPCVOID)BASE_ADDRESS, &dwNum, sizeof(DWORD), NULL);
        ReadProcessMemory(hProcess, (LPCVOID)(dwNum + user_data), &dwNum, sizeof(DWORD), NULL);

        WriteProcessMemory(hProcess, (LPVOID)(dwNum + twiddydinky + 15 * 4), &value, sizeof(DWORD), NULL);
    }
    else
    {
        BYTE patch[] = { 0xff };
        WriteProcessMemory(hProcess, (LPVOID)0x0052db83, patch, sizeof(patch), NULL);
    }
    CloseHandle(hProcess);
}

// 无限巧克力
VOID CPvz::Chocolate(DWORD Enable)
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
    if (hProcess == NULL)
    {
        MessageBox(NULL, L"无法打开游戏进程", L"错误", MB_OK | MB_ICONERROR);
        return;
    }

    if (Enable)
    {
        //固定数量
        BYTE patch[] = { 0x39 };
        WriteProcessMemory(hProcess, (LPVOID)0x0052d6a5, patch, sizeof(patch), NULL);
        BYTE patch1[] = { 0x39 };
        WriteProcessMemory(hProcess, (LPVOID)0x0052d727, patch1, sizeof(patch1), NULL);

        //设置数量
        DWORD value = 1000 + 10;
        DWORD dwNum = 0;
        ReadProcessMemory(hProcess, (LPCVOID)BASE_ADDRESS, &dwNum, sizeof(DWORD), NULL);
        ReadProcessMemory(hProcess, (LPCVOID)(dwNum + user_data), &dwNum, sizeof(DWORD), NULL);

        WriteProcessMemory(hProcess, (LPVOID)(dwNum + twiddydinky + 26 * 4), &value, sizeof(DWORD), NULL);
    }
    else
    {
        BYTE patch[] = { 0xff };
        WriteProcessMemory(hProcess, (LPVOID)0x0052d6a5, patch, sizeof(patch), NULL);
        BYTE patch1[] = { 0xff };
        WriteProcessMemory(hProcess, (LPVOID)0x0052d727, patch1, sizeof(patch1), NULL);
    }
    CloseHandle(hProcess);
}


// 修改金币
VOID CPvz::ModifyCoinValue(DWORD dwCoin)
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);

    DWORD dwNum = 0;
    ReadProcessMemory(hProcess, (LPCVOID)0x731c50, &dwNum, sizeof(DWORD), NULL);
    ReadProcessMemory(hProcess, (LPCVOID)(dwNum + 0x94C), &dwNum, sizeof(DWORD), NULL);

    WriteProcessMemory(hProcess, (LPVOID)(dwNum + 0x54), &dwCoin, sizeof(DWORD), NULL);

    CloseHandle(hProcess);
}


// 随意放置
VOID CPvz::Build(DWORD Enable)
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
    if (hProcess == NULL)
    {
        MessageBox(NULL, L"无法打开游戏进程", L"错误", MB_OK | MB_ICONERROR);
        return;
    }

    if (Enable)
    {
        BYTE patch[] = { 0x81, 0xeb, 0x8d };
        WriteProcessMemory(hProcess, (LPVOID)0x00413350, &patch[0], sizeof(patch[0]), NULL);   // placed_anywhere
        WriteProcessMemory(hProcess, (LPVOID)0x0043d100, &patch[1], sizeof(patch[1]), NULL);   // placed_anywhere_preview
        WriteProcessMemory(hProcess, (LPVOID)0x0042dec9, &patch[2], sizeof(patch[2]), NULL);   // placed_anywhere_iz
    }
    else
    {
        BYTE patch[] = { 0x84, 0x74, 0x84 };
        WriteProcessMemory(hProcess, (LPVOID)0x00413350, &patch[0], sizeof(patch[0]), NULL);
        WriteProcessMemory(hProcess, (LPVOID)0x0043d100, &patch[1], sizeof(patch[1]), NULL);
        WriteProcessMemory(hProcess, (LPVOID)0x0042dec9, &patch[2], sizeof(patch[2]), NULL);
    }

    CloseHandle(hProcess);
}


// 自动收集
VOID CPvz::AutoCollected(DWORD Enable)
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
    if (hProcess == NULL)
    {
        MessageBox(NULL, L"无法打开游戏进程", L"错误", MB_OK | MB_ICONERROR);
        return;
    }

    if (Enable)
    {
        BYTE patch[] = { 0xEB };
        WriteProcessMemory(hProcess, (LPVOID)0x004352f2, patch, sizeof(patch), NULL);

    }
    else
    {
        BYTE patch[] = { 0x75 };
        WriteProcessMemory(hProcess, (LPVOID)0x004352f2, patch, sizeof(patch), NULL);
    }

    CloseHandle(hProcess);
}


// 加速攻击
VOID CPvz::Speed()
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);

    // 原指令：00464A96 0F85 98FEFFFF jne 00464934
    // 修改后的指令：
    //     00464A96 90 nop 
    //     00464A97 90 nop
    //     00464A98 90 nop
    //     00464A99 90 nop
    //     00464A9A 90 nop
    //     00464A9B 90 nop
    char *patch = "\x90\x90\x90\x90\x90\x90";
    WriteProcessMemory(hProcess, (LPVOID)0x00464a96, patch, 6, NULL);

    CloseHandle(hProcess);
}

// 清除浓雾
VOID CPvz::NoFog(DWORD Enable)
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
    if (hProcess == NULL)
    {
        MessageBox(NULL, L"无法打开游戏进程", L"错误", MB_OK | MB_ICONERROR);
        return;
    }

    if (Enable)
    {
        BYTE patch[] = { 0x31, 0xd2 }; // 0xd231 的低字节是 0x31，高字节是 0xd2
        WriteProcessMemory(hProcess, (LPVOID)0x0041df4d, patch, sizeof(patch), NULL);
    }
    else
    {
        BYTE patch[] = { 0x3b, 0xf2 }; // 0xf23b 拆成两个字节
        WriteProcessMemory(hProcess, (LPVOID)0x0041df4d, patch, sizeof(patch), NULL);
    }

    CloseHandle(hProcess);
}

// 核弹无坑
VOID CPvz::NoCrater(DWORD Enable)
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
    if (hProcess == NULL)
    {
        MessageBox(NULL, L"无法打开游戏进程", L"错误", MB_OK | MB_ICONERROR);
        return;
    }

    if (Enable)
    {
        BYTE patch[] = { 0x70 };
        WriteProcessMemory(hProcess, (LPVOID)0x0042136d, patch, sizeof(patch), NULL);
    }
    else
    {
        BYTE patch[] = { 0x75 };
        WriteProcessMemory(hProcess, (LPVOID)0x0042136d, patch, sizeof(patch), NULL);
    }

    CloseHandle(hProcess);
}

// 冰车无痕
VOID CPvz::NoIceTrail(DWORD Enable)
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
    if (hProcess == NULL)
    {
        MessageBox(NULL, L"无法打开游戏进程", L"错误", MB_OK | MB_ICONERROR);
        return;
    }

    if (Enable)
    {
        BYTE patch[] = { 0xc3 };
        WriteProcessMemory(hProcess, (LPVOID)0x0053f1b0, patch, sizeof(patch), NULL);
        BYTE patch1[] = { 0xeb };
        WriteProcessMemory(hProcess, (LPVOID)0x0042333a, patch1, sizeof(patch1), NULL);

        DWORD value = 1;
        for (size_t i = 0; i < 6; ++i)
        {
            DWORD dwNum = 0;
            ReadProcessMemory(hProcess, (LPCVOID)BASE_ADDRESS, &dwNum, sizeof(DWORD), NULL);
            ReadProcessMemory(hProcess, (LPCVOID)(dwNum + board), &dwNum, sizeof(DWORD), NULL);

            WriteProcessMemory(hProcess, (LPVOID)(dwNum + ice_trail_cd + i * 4), &value, sizeof(DWORD), NULL);
        }     
    }
    else
    {
        BYTE patch[] = { 0x51 };
        WriteProcessMemory(hProcess, (LPVOID)0x0053f1b0, patch, sizeof(patch), NULL);
        BYTE patch1[] = { 0x75 };
        WriteProcessMemory(hProcess, (LPVOID)0x0042333a, patch1, sizeof(patch1), NULL);
    }

    CloseHandle(hProcess);
}

// 罐子透视
VOID CPvz::SeeVase(DWORD Enable)
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
    if (hProcess == NULL)
    {
        MessageBox(NULL, L"无法打开游戏进程", L"错误", MB_OK | MB_ICONERROR);
        return;
    }

    if (Enable)
    {
        BYTE patch[] = { 0x66, 0xB8, 0x33, 0x00 };
        WriteProcessMemory(hProcess, (LPVOID)0x004531ca, patch, sizeof(patch), NULL);
    }
    else
    {
        BYTE patch[] = { 0x85, 0xC0, 0x7E, 0x04 };
        WriteProcessMemory(hProcess, (LPVOID)0x004531ca, patch, sizeof(patch), NULL);
    }

    CloseHandle(hProcess);
}


// 加速阳光金币
VOID CPvz::More()
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);

    // 原指令：0045FA48 83 47 58 FF add dword ptr [edi+58],-01 { 255 }
    // 修改后的指令：0045FA48 83 47 58 9C add dword ptr [edi+58],-64 { 156 }
    char *patch = "\x83\x47\x58\x9c";
    WriteProcessMemory(hProcess, (LPVOID)0x0045FA48, patch, 4, NULL);

    CloseHandle(hProcess);
}


// 停滞不前
VOID CPvz::StopZombies(DWORD Enable)
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
    if (hProcess == NULL)
    {
        MessageBox(NULL, L"无法打开游戏进程", L"错误", MB_OK | MB_ICONERROR);
        return;
    }

    if (Enable)
    {
        BYTE patch[] = { 0x54 };
        WriteProcessMemory(hProcess, (LPVOID)0x0053f533, patch, sizeof(patch), NULL);
        BYTE patch1[] = { 0x54 };
        WriteProcessMemory(hProcess, (LPVOID)0x0053f53c, patch1, sizeof(patch1), NULL);
    }
    else
    {
        BYTE patch[] = { 0x64 };
        WriteProcessMemory(hProcess, (LPVOID)0x0053f533, patch, sizeof(patch), NULL);
        BYTE patch1[] = { 0x44 };
        WriteProcessMemory(hProcess, (LPVOID)0x0053f53c, patch1, sizeof(patch1), NULL);
    }

    CloseHandle(hProcess);
}


// 暂停刷怪
VOID CPvz::StopSpawning(DWORD Enable)
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
    if (hProcess == NULL)
    {
        MessageBox(NULL, L"无法打开游戏进程", L"错误", MB_OK | MB_ICONERROR);
        return;
    }

    if (Enable)
    {    
        BYTE patch[] = { 0xeb };
        WriteProcessMemory(hProcess, (LPVOID)0x0042a12c, patch, sizeof(patch), NULL);
    }
    else
    {
        BYTE patch[] = { 0x74 };
        WriteProcessMemory(hProcess, (LPVOID)0x0042a12c, patch, sizeof(patch), NULL);
    }

    CloseHandle(hProcess);
}


// 僵尸冰冻状态
VOID CPvz::Cool()
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);

    // 原指令：0052AB3E 0F85 A4000000 jne 0052ABE8
    // 修改后的指令：0052AB3E E9 BD63EDFF jmp 00400F00
    char *patch1 = "\xe9\xbd\x63\xed\xff\x90";
    WriteProcessMemory(hProcess, (LPVOID)0x0052AB3E, patch1, 6, NULL);

    // 申请新的空间
    DWORD dwOldProtect = 0;
    VirtualProtectEx(hProcess, (LPVOID)0x00400f00, 64, PAGE_EXECUTE_READWRITE, &dwOldProtect);

    // 在新申请的空间写入的指令
    //     00400F00 C7 86 AC000000 00100000 mov [esi+000000AC],00001000 { 4096 }
    //     00400F0A 0F85 D89C1200 jne 0052ABE8
    //     00400F10 E9 2F9C1200 jmp 0052AB44
    char *patch2 = "\xc7\x86\xac\x00\x00\x00\x00\x10\x00\x00\x0F\x85\xD8\x9C\x12\x00\xE9\x2F\x9C\x12\x00";
    WriteProcessMemory(hProcess, (LPVOID)0x00400f00, patch2, 21, NULL);

    CloseHandle(hProcess);
}


// 僵尸奶油状态
VOID CPvz::Stop()
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);

    // 原指令：0052AB3E 0F85 A4000000 jne 0052ABE8
    // 修改后的指令：
    //    0052AB3E E9 BD63EDFF jmp 00400F00
    //    0052AB43 90          nop
    char *patch1 = "\xe9\xbd\x63\xed\xff\x90";
    WriteProcessMemory(hProcess, (LPVOID)0x0052AB3E, patch1, 6, NULL);

    DWORD dwOldProtect = 0;
    VirtualProtectEx(hProcess, (LPVOID)0x00400f00, 64, PAGE_EXECUTE_READWRITE, &dwOldProtect);


    // 在新申请的空间写入的指令
    // 00400F00 60 pushad 
    // 00400F01 9C pushfd
    // 00400F02 D9 46 2C fld dword ptr[esi + 2C]
    // 00400F05 C7 46 2C 56FB4843 mov[esi + 2C], 4348FB56{ 200.98 }
    // 00400F0C D8 56 2C fcom dword ptr[esi + 2C]
    // 00400F0F 9BDFE0 wait:fstsw ax
    // 00400F12 9E sahf
    // 00400F13 77 0A ja 00400F1F
    // 00400F15 C7 86 B0000000 00010000 mov[esi + 000000B0], 00000100 { 256 }
    // 00400F1F D9 5E 2C fstp dword ptr[esi + 2C]
    // 00400F22 9D popfd
    // 00400F23 61 popad
    // 00400F24 0F85 BE9C1200 jne 0052ABE8
    // 00400F2A E9 159C1200 jmp 0052AB44
    char *patch2 = "\x60"
        "\x9c"
        "\xd9\x46\x2c"
        "\xc7\x46\x2c\x56\xFB\x48\x43"
        "\xD8\x56\x2C"
        "\x9B\xDF\xE0"
        "\x9E"
        "\x77\x0A"
        "\xC7\x86\xB0\x00\x00\x00\x00\x01\x00\x00"
        "\xD9\x5E\x2C"
        "\x9D"
        "\x61"
        "\x0F\x85\xBE\x9C\x12\x00"
        "\xE9\x15\x9C\x12\x00";
    WriteProcessMemory(hProcess, (LPVOID)0x00400f00, patch2, 47, NULL);

    CloseHandle(hProcess);
}


// 僵尸死亡
VOID CPvz::Dead()
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);


    // 原指令：0052AB3E 0F85 A4000000 jne 0052ABE8
    // 修改后的指令：
    //    0052AB3E E9 BD63EDFF jmp 00400F00
    //    0052AB43 90          nop
    char *patch1 = "\xe9\xbd\x63\xed\xff\x90";
    WriteProcessMemory(hProcess, (LPVOID)0x0052AB3E, patch1, 6, NULL);

    DWORD dwOldProtect = 0;
    VirtualProtectEx(hProcess, (LPVOID)0x00400f00, 64, PAGE_EXECUTE_READWRITE, &dwOldProtect);

    // 在新申请的空间写入的指令
    //     00400F00 C7 46 28 01000000 mov [esi+28],00000001 { 1 }
    //     00400F07 0F85 DB9C1200     jne 0052ABE8
    //     00400F0D E9 329C1200       jmp 0052AB44
    char *patch2 = "\xc7\x46\x28\x01\x00\x00\x00\x0F\x85\xdb\x9C\x12\x00\xE9\x32\x9C\x12\x00";
    WriteProcessMemory(hProcess, (LPVOID)0x00400f00, patch2, 18, NULL);

    CloseHandle(hProcess);
}


// 吸怪
VOID CPvz::Attract()
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }

    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);

    // 原指令：0052AB3E 0F85 A4000000 jne 0052ABE8
    // 修改后的指令：
    //    0052AB3E E9 BD63EDFF jmp 00400F00
    //    0052AB43 90          nop
    char *patch1 = "\xe9\xbd\x63\xed\xff\x90";
    WriteProcessMemory(hProcess, (LPVOID)0x0052AB3E, patch1, 6, NULL);

    DWORD dwOldProtect = 0;
    VirtualProtectEx(hProcess, (LPVOID)0x00400f00, 64, PAGE_EXECUTE_READWRITE, &dwOldProtect);
    
    // 在新申请的空间写入的指令
    //     00400F00 C7 46 1C 02000000 mov [esi+1C],00000002 { 2 }
    //     00400F07 0F85 DB9C1200     jne 0052ABE8
    //     00400F0D E9 329C1200       jmp 0052AB44
    char *patch2 = "\xc7\x46\x1c\x02\x00\x00\x00\x0F\x85\xdb\x9C\x12\x00\xE9\x32\x9C\x12\x00";
    WriteProcessMemory(hProcess, (LPVOID)0x00400f00, patch2, 18, NULL);

    CloseHandle(hProcess);
}

// 后台模式
VOID CPvz::BgMode(DWORD Enable)
{
    DWORD dwPid = GetGamePid();
    if (dwPid == -1)
    {
        MessageBox(NULL, L"游戏未找到", L"提示", MB_OK);
        return;
    }
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
    if (hProcess == NULL)
    {
        MessageBox(NULL, L"无法打开游戏进程", L"错误", MB_OK | MB_ICONERROR);
        return;
    }

    if (Enable)
    {
        BYTE patch1[] = { 0xEB, 0x0F };
        WriteProcessMemory(hProcess, (LPVOID)0x004540DA, patch1, sizeof(patch1), NULL);

        BYTE patch2[] = { 0xEB, 0x06 };
        WriteProcessMemory(hProcess, (LPVOID)0x004540E3, patch2, sizeof(patch2), NULL);
    }
    else
    {
        BYTE original1[] = { 0x7C, 0x0F };  // 举例：原始是 JL +0F
        WriteProcessMemory(hProcess, (LPVOID)0x004540DA, original1, sizeof(original1), NULL);

        BYTE original2[] = { 0x75, 0x06 };  // 举例：原始是 JNZ +06
        WriteProcessMemory(hProcess, (LPVOID)0x004540E3, original2, sizeof(original2), NULL);
    }

    CloseHandle(hProcess);
}