#include "stdafx.h"
#include "Pvz.h"
#include "data.h"

CPvz::CPvz()
{
}


CPvz::~CPvz()
{
}

// �ڲ����ߺ���
HANDLE CPvz::OpenGameProcess()
{
    // ��ȡ��Ϸ PID
    HWND hWnd = ::FindWindowW(NULL, GAME_NAME);
    if (!hWnd)
    {
        MessageBox(NULL, L"��Ϸδ�ҵ�", L"��ʾ", MB_OK);
        return NULL;
    }

    DWORD dwPid = 0;
    ::GetWindowThreadProcessId(hWnd, &dwPid);

    // ����Ϸ����
    HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);
    if (!hProcess)
    {
        MessageBox(NULL, L"�޷�����Ϸ����", L"����", MB_OK | MB_ICONERROR);
        return NULL;
    }

    return hProcess;
}


// �޸������ֵ
VOID CPvz::ModifySunValue(DWORD dwSun)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

    // 00731C50 00731CDC
    // 00475373 - mov edi, [esi + 00000868] ESI = 0286B490
    // 0044BA45 - add[edi + 00005578], eax EDI = 1E4A0B40

    DWORD dwNum = 0;
    ReadProcessMemory(hProcess, (LPCVOID)BASE_ADDRESS, &dwNum, sizeof(DWORD), NULL);
    ReadProcessMemory(hProcess, (LPCVOID)(dwNum + board), &dwNum, sizeof(DWORD), NULL);
    WriteProcessMemory(hProcess, (LPVOID)(dwNum + sun), &dwSun, sizeof(DWORD), NULL);

    CloseHandle(hProcess);
}


// ��ֲ��ȴ
VOID CPvz::NoCd(DWORD Enable)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

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

// ��������
VOID CPvz::LockShovel(DWORD Enable)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

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


// ���޻���
VOID CPvz::Fertilizer(DWORD Enable)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

    if (Enable)
    {
        //�̶�����
        BYTE patch[] = { 0x39 };
        WriteProcessMemory(hProcess, (LPVOID)0x0052da8b, patch, sizeof(patch), NULL);

        //��������
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

// ��������
VOID CPvz::TreeFood(DWORD Enable)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

    if (Enable)
    {
        //�̶�����
        BYTE patch[] = { 0x39 };
        WriteProcessMemory(hProcess, (LPVOID)0x004311ed, patch, sizeof(patch), NULL);

        //��������
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

// ����ɱ���
VOID CPvz::BugSpray(DWORD Enable)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

    if (Enable)
    {
        //�̶�����
        BYTE patch[] = { 0x39 };
        WriteProcessMemory(hProcess, (LPVOID)0x0052db83, patch, sizeof(patch), NULL);

        //��������
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

// �����ɿ���
VOID CPvz::Chocolate(DWORD Enable)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

    if (Enable)
    {
        //�̶�����
        BYTE patch[] = { 0x39 };
        WriteProcessMemory(hProcess, (LPVOID)0x0052d6a5, patch, sizeof(patch), NULL);
        BYTE patch1[] = { 0x39 };
        WriteProcessMemory(hProcess, (LPVOID)0x0052d727, patch1, sizeof(patch1), NULL);

        //��������
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


// �޸Ľ��
VOID CPvz::ModifyCoinValue(DWORD dwCoin)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

    DWORD dwNum = 0;
    ReadProcessMemory(hProcess, (LPCVOID)BASE_ADDRESS, &dwNum, sizeof(DWORD), NULL);
    ReadProcessMemory(hProcess, (LPCVOID)(dwNum + user_data), &dwNum, sizeof(DWORD), NULL);
    WriteProcessMemory(hProcess, (LPVOID)(dwNum + money), &dwCoin, sizeof(DWORD), NULL);

    CloseHandle(hProcess);
}


// �������
VOID CPvz::Build(DWORD Enable)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

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


// �Զ��ռ�
VOID CPvz::AutoCollected(DWORD Enable)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

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


// ���ٹ���
VOID CPvz::Speed()
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

    char *patch = "\x90\x90\x90\x90\x90\x90";
    WriteProcessMemory(hProcess, (LPVOID)0x00464a96, patch, 6, NULL);

    CloseHandle(hProcess);
}

// ���Ũ��
VOID CPvz::NoFog(DWORD Enable)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

    if (Enable)
    {
        BYTE patch[] = { 0x31, 0xd2 }; // 0xd231 �ĵ��ֽ��� 0x31�����ֽ��� 0xd2
        WriteProcessMemory(hProcess, (LPVOID)0x0041df4d, patch, sizeof(patch), NULL);
    }
    else
    {
        BYTE patch[] = { 0x3b, 0xf2 }; // 0xf23b ��������ֽ�
        WriteProcessMemory(hProcess, (LPVOID)0x0041df4d, patch, sizeof(patch), NULL);
    }

    CloseHandle(hProcess);
}

// �˵��޿�
VOID CPvz::NoCrater(DWORD Enable)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

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

// �����޺�
VOID CPvz::NoIceTrail(DWORD Enable)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

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

// ��������
VOID CPvz::LockButter(DWORD Enable)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

    if (Enable)
    {
        BYTE patch[] = { 0x70 };
        WriteProcessMemory(hProcess, (LPVOID)0x00465522, patch, sizeof(patch), NULL);
    }
    else
    {
        BYTE patch[] = { 0x75 };
        WriteProcessMemory(hProcess, (LPVOID)0x00465522, patch, sizeof(patch), NULL);
    }

    CloseHandle(hProcess);
}

// ����װ��
VOID CPvz::ReloadInstantly(DWORD Enable)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

    if (Enable)
    {
        // reload_instantly
        BYTE patch[] = { 0x80 };
        WriteProcessMemory(hProcess, (LPVOID)0x004673eb, patch, sizeof(patch), NULL);
        // grow_up_quickly
        BYTE patch1[] = { 0x80 };
        WriteProcessMemory(hProcess, (LPVOID)0x00466204, patch1, sizeof(patch1), NULL);
        BYTE patch2[] = { 0x70 };
        WriteProcessMemory(hProcess, (LPVOID)0x00465f53, patch2, sizeof(patch2), NULL);
        // no_cooldown
        BYTE patch3[] = { 0x70 };
        WriteProcessMemory(hProcess, (LPVOID)0x00467905, patch3, sizeof(patch3), NULL);
        BYTE patch4[] = { 0x80 };
        WriteProcessMemory(hProcess, (LPVOID)0x004681f7, patch4, sizeof(patch4), NULL);
    }
    else
    {
        BYTE patch[] = { 0x85 };
        WriteProcessMemory(hProcess, (LPVOID)0x004673eb, patch, sizeof(patch), NULL);
        // grow_up_quickly
        BYTE patch1[] = { 0x85 };
        WriteProcessMemory(hProcess, (LPVOID)0x00466204, patch1, sizeof(patch1), NULL);
        BYTE patch2[] = { 0x75 };
        WriteProcessMemory(hProcess, (LPVOID)0x00465f53, patch2, sizeof(patch2), NULL);
        // no_cooldown
        BYTE patch3[] = { 0x75 };
        WriteProcessMemory(hProcess, (LPVOID)0x00467905, patch3, sizeof(patch3), NULL);
        BYTE patch4[] = { 0x85 };
        WriteProcessMemory(hProcess, (LPVOID)0x004681f7, patch4, sizeof(patch4), NULL);
    }

    CloseHandle(hProcess);
}

// ����͸��
VOID CPvz::SeeVase(DWORD Enable)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

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

// Ģ��˯�� (�´���ֲ��Ч)
VOID CPvz::MushroomsAwake(DWORD Enable)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

    if (Enable)
    {
        BYTE patch[] = { 0xeb };
        WriteProcessMemory(hProcess, (LPVOID)0x004641a2, patch, sizeof(patch), NULL);
    }
    else
    {
        BYTE patch[] = { 0x74 };
        WriteProcessMemory(hProcess, (LPVOID)0x004641a2, patch, sizeof(patch), NULL);
    }

    CloseHandle(hProcess);
}


// ����������
VOID CPvz::More()
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

    char *patch = "\x83\x47\x58\x9c";
    WriteProcessMemory(hProcess, (LPVOID)0x0045FA48, patch, 4, NULL);

    CloseHandle(hProcess);
}


// ͣ�Ͳ�ǰ
VOID CPvz::StopZombies(DWORD Enable)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

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


// ��ͣˢ��
VOID CPvz::StopSpawning(DWORD Enable)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

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

// С�󲻱�
VOID CPvz::ZombieNotExplode(DWORD Enable)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

    if (Enable)
    {
        BYTE patch[] = { 0x81 };
        WriteProcessMemory(hProcess, (LPVOID)0x0053b2ec, patch, sizeof(patch), NULL);
        BYTE patch1[] = { 0x81 };
        WriteProcessMemory(hProcess, (LPVOID)0x0053bdcd, patch1, sizeof(patch1), NULL);
    }
    else
    {
        BYTE patch[] = { 0x8f };
        WriteProcessMemory(hProcess, (LPVOID)0x0053b2ec, patch, sizeof(patch), NULL);
        BYTE patch1[] = { 0x85 };
        WriteProcessMemory(hProcess, (LPVOID)0x0053bdcd, patch1, sizeof(patch1), NULL);
    }

    CloseHandle(hProcess);
}


// ��ʬ����״̬
VOID CPvz::Cool()
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

    char *patch1 = "\xe9\xbd\x63\xed\xff\x90";
    WriteProcessMemory(hProcess, (LPVOID)0x0052AB3E, patch1, 6, NULL);

    // �����µĿռ�
    DWORD dwOldProtect = 0;
    VirtualProtectEx(hProcess, (LPVOID)0x00400f00, 64, PAGE_EXECUTE_READWRITE, &dwOldProtect);

    char *patch2 = "\xc7\x86\xac\x00\x00\x00\x00\x10\x00\x00\x0F\x85\xD8\x9C\x12\x00\xE9\x2F\x9C\x12\x00";
    WriteProcessMemory(hProcess, (LPVOID)0x00400f00, patch2, 21, NULL);

    CloseHandle(hProcess);
}


// ��ʬ����״̬
VOID CPvz::Stop()
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

    char *patch1 = "\xe9\xbd\x63\xed\xff\x90";
    WriteProcessMemory(hProcess, (LPVOID)0x0052AB3E, patch1, 6, NULL);

    DWORD dwOldProtect = 0;
    VirtualProtectEx(hProcess, (LPVOID)0x00400f00, 64, PAGE_EXECUTE_READWRITE, &dwOldProtect);

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


// ��ʬ����
VOID CPvz::Dead()
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

    // ԭָ�0052AB3E 0F85 A4000000 jne 0052ABE8
    // �޸ĺ��ָ�
    //    0052AB3E E9 BD63EDFF jmp 00400F00
    //    0052AB43 90          nop
    char *patch1 = "\xe9\xbd\x63\xed\xff\x90";
    WriteProcessMemory(hProcess, (LPVOID)0x0052AB3E, patch1, 6, NULL);

    DWORD dwOldProtect = 0;
    VirtualProtectEx(hProcess, (LPVOID)0x00400f00, 64, PAGE_EXECUTE_READWRITE, &dwOldProtect);

    // ��������Ŀռ�д���ָ��
    //     00400F00 C7 46 28 01000000 mov [esi+28],00000001 { 1 }
    //     00400F07 0F85 DB9C1200     jne 0052ABE8
    //     00400F0D E9 329C1200       jmp 0052AB44
    char *patch2 = "\xc7\x46\x28\x01\x00\x00\x00\x0F\x85\xdb\x9C\x12\x00\xE9\x32\x9C\x12\x00";
    WriteProcessMemory(hProcess, (LPVOID)0x00400f00, patch2, 18, NULL);

    CloseHandle(hProcess);
}


// ����
VOID CPvz::Attract()
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

    // ԭָ�0052AB3E 0F85 A4000000 jne 0052ABE8
    // �޸ĺ��ָ�
    //    0052AB3E E9 BD63EDFF jmp 00400F00
    //    0052AB43 90          nop
    char *patch1 = "\xe9\xbd\x63\xed\xff\x90";
    WriteProcessMemory(hProcess, (LPVOID)0x0052AB3E, patch1, 6, NULL);

    DWORD dwOldProtect = 0;
    VirtualProtectEx(hProcess, (LPVOID)0x00400f00, 64, PAGE_EXECUTE_READWRITE, &dwOldProtect);
    
    // ��������Ŀռ�д���ָ��
    //     00400F00 C7 46 1C 02000000 mov [esi+1C],00000002 { 2 }
    //     00400F07 0F85 DB9C1200     jne 0052ABE8
    //     00400F0D E9 329C1200       jmp 0052AB44
    char *patch2 = "\xc7\x46\x1c\x02\x00\x00\x00\x0F\x85\xdb\x9C\x12\x00\xE9\x32\x9C\x12\x00";
    WriteProcessMemory(hProcess, (LPVOID)0x00400f00, patch2, 18, NULL);

    CloseHandle(hProcess);
}

// ��̨ģʽ
VOID CPvz::BgMode(DWORD Enable)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

    if (Enable)
    {
        WORD patch[] = { 0x00eb };
        WriteProcessMemory(hProcess, (LPVOID)0x005d87c9, patch, sizeof(patch), NULL);
    }
    else
    {
        WORD patch[] = { 0x4074 };
        WriteProcessMemory(hProcess, (LPVOID)0x005d87c9, patch, sizeof(patch), NULL);
    }

    CloseHandle(hProcess);
}


// ��Ϸ�ٶ�
VOID CPvz::Test(CComboBox* Plants1)
{
    HANDLE hProcess = OpenGameProcess();
    if (!hProcess) return;

    int nIndex = Plants1->GetCurSel();
    const int time_ms[] = {
        1,   // 10x
        2,   // 5x
        5,   // 2x
        10,  // 1x
        20,  // 0.5x
        50,  // 0.2x
        100, // 0.1x
    };

    //��������
    int value = time_ms[nIndex];
    DWORD dwNum = 0;
    ReadProcessMemory(hProcess, (LPCVOID)BASE_ADDRESS, &dwNum, sizeof(DWORD), NULL);

    WriteProcessMemory(hProcess, (LPVOID)(dwNum + 0x454 + 0x60), &value, sizeof(value), NULL);

    CloseHandle(hProcess);
}

