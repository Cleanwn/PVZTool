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
    // ��ֲ��ȴ
    VOID NoCd(DWORD Enable);
    // ��������
    VOID LockShovel(DWORD Enable);
    // ���޻���
    VOID Fertilizer(DWORD Enable);
    // ��������
    VOID TreeFood(DWORD Enable);
    // ����ɱ���
    VOID BugSpray(DWORD Enable);
    // �����ɿ���
    VOID Chocolate(DWORD Enable);
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
    // �˵��޿�
    VOID NoCrater(DWORD Enable);
    // �����޺�
    VOID NoIceTrail(DWORD Enable);
    // ����͸��
    VOID SeeVase(DWORD Enable);
    // ����������
    VOID More();
    // ͣ�Ͳ�ǰ
    VOID StopZombies(DWORD Enable);
    // ��ͣˢ��
    VOID StopSpawning(DWORD Enable);
    // ��ʬ����״̬
    VOID Cool();
    // ��ʬ����״̬
    VOID Stop();
    // ��ʬ����
    VOID Dead();
    // ����
    VOID Attract();
};