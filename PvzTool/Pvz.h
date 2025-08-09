#pragma once

#define GAME_NAME L"Plants vs. Zombies"

class CPvz
{
private:
    // 内部工具函数
    HANDLE OpenGameProcess();
public:
    CPvz();
    ~CPvz();

    // 修改阳光的值
    VOID ModifySunValue(DWORD dwSun);
    // 后台模式
    VOID BgMode(DWORD Enable);
    // 种植冷却
    VOID NoCd(DWORD Enable);
    // 锁定铲子
    VOID LockShovel(DWORD Enable);
    // 无限花肥
    VOID Fertilizer(DWORD Enable);
    // 无限树肥
    VOID TreeFood(DWORD Enable);
    // 无限杀虫剂
    VOID BugSpray(DWORD Enable);
    // 无限巧克力
    VOID Chocolate(DWORD Enable);
    // 修改金币
    VOID ModifyCoinValue(DWORD dwCoin);
    // 随意放置
    VOID Build(DWORD Enable);
    // 自动收集
    VOID AutoCollected(DWORD Enable);
    // 加速攻击
    VOID Speed();
    // 清除浓雾
    VOID NoFog(DWORD Enable);
    // 核弹无坑
    VOID NoCrater(DWORD Enable);
    // 冰车无痕
    VOID NoIceTrail(DWORD Enable);
    // 锁定黄油
    VOID LockButter(DWORD Enable);
    // 立刻装填
    VOID ReloadInstantly(DWORD Enable);
    // 罐子透视
    VOID SeeVase(DWORD Enable);
    // 蘑菇睡醒
    VOID MushroomsAwake(DWORD Enable);
    // 加速阳光金币
    VOID More();
    // 停滞不前
    VOID StopZombies(DWORD Enable);
    // 暂停刷怪
    VOID StopSpawning(DWORD Enable);
    // 小丑不爆
    VOID ZombieNotExplode(DWORD Enable);
    // 僵尸冰冻状态
    VOID Cool();
    // 僵尸奶油状态
    VOID Stop();
    // 僵尸死亡
    VOID Dead();
    // 吸怪
    VOID Attract();
    // 通知
    VOID Test(CComboBox* Plants1);
};