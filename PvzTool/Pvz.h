#pragma once

#define GAME_NAME L"Plants vs. Zombies"

class CPvz
{
private:
    // �ڲ����ߺ���
    DWORD GetGamePid();
public:
    CPvz();
    ~CPvz();

    // �޸������ֵ
    VOID ModifySunValue(DWORD dwSun);
    // ��̨ģʽ
    VOID BgMode(DWORD Enable);
    // �����ֲ
    VOID FreePlant(DWORD Enable);
    // ��ֲ����ȴ
    VOID NoCd(DWORD Enable);
    // �޸Ľ��
    VOID ModifyCoinValue(DWORD dwCoin);
    // �������
    VOID Build(DWORD Enable);
    // �Զ��ռ�
    VOID AutoCollected(DWORD Enable);
    // ���ٹ���
    VOID Speed();
    // ���Ũ��
    VOID NoFog(DWORD Enable);
    // ����͸��
    VOID SeeVase(DWORD Enable);
    // ����������
    VOID More();
    // ȫ����ʬ
    VOID AllScreen();
    // ȡ��ȫ����ʬ
    VOID UnAllScreen();
    // ��ʬ����״̬
    VOID Cool();
    // ��ʬ����״̬
    VOID Stop();
    // ��ʬ����
    VOID Dead();
    // ����
    VOID Attract();
};