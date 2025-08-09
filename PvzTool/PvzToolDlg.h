
// PvzToolDlg.h : 头文件
//

#pragma once


// CPvzToolDlg 对话框
class CPvzToolDlg : public CDialogEx
{
// 构造
public:
	CPvzToolDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PVZTOOL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
    // 绑定 ComboBox 控件变量
    CComboBox Plants1;

    // 点击事件函数声明
    // button
    afx_msg void OnBnClickedBtnSun();
    afx_msg void OnBnClickedBtnCoin();
    afx_msg void OnBnClickedBtnSpeed();
    afx_msg void OnBnClickedBtnMore();
    afx_msg void OnBnClickedBtnCool();
    afx_msg void OnBnClickedBtnStop();
    afx_msg void OnBnClickedBtnDead();
    afx_msg void OnBnClickedBtnY();
    afx_msg void OnBnClickedTest();
    // check
    afx_msg void OnCheckBgMode();
    afx_msg void OnCheckStopZombies();
    afx_msg void OnCheckStopSpawning();
    afx_msg void OnCheckNoFog();
    afx_msg void OnCheckNoCrater();
    afx_msg void OnCheckNoIceTrail();
    afx_msg void OnCheckSeeVase();
    afx_msg void OnCheckAutoCollected();
    afx_msg void OnCheckBuild();
    afx_msg void OnCheckLockShovel();
    afx_msg void OnCheckFertilizer();
    afx_msg void OnCheckTreeFood();
    afx_msg void OnCheckBugSpray();
    afx_msg void OnCheckChocolate();
    afx_msg void OnCheckNoCd();
    afx_msg void OnCheckLockButter();
    afx_msg void OnCheckReloadInstantly();
    afx_msg void OnCheckZombieNotExplode();
    afx_msg void OnCheckMushroomsAwake();
};
