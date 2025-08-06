#pragma once

#define GAME_NAME L"Plants vs. Zombies"

class CPvz
{
private:
    // 内部工具函数
    DWORD GetGamePid();
public:
    CPvz();
    ~CPvz();

    // 修改阳光的值
    VOID ModifySunValue(DWORD dwSun);
    // 后台模式
    VOID BgMode(DWORD Enable);
    // 免费种植
    VOID FreePlant(DWORD Enable);
    // 种植免冷却
    VOID NoCd(DWORD Enable);
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
    // 罐子透视
    VOID SeeVase(DWORD Enable);
    // 加速阳光金币
    VOID More();
    // 全屏僵尸
    VOID AllScreen();
    // 取消全屏僵尸
    VOID UnAllScreen();
    // 僵尸冰冻状态
    VOID Cool();
    // 僵尸奶油状态
    VOID Stop();
    // 僵尸死亡
    VOID Dead();
    // 吸怪
    VOID Attract();
};