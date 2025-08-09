
// PvzToolDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "PvzTool.h"
#include "PvzToolDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPvzToolDlg �Ի���



CPvzToolDlg::CPvzToolDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PVZTOOL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPvzToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	// �󶨿ؼ� IDC_CHECK_DROPDOWNLIST �� Plants1 ����
	DDX_Control(pDX, IDC_CHECK_DROPDOWNLIST, Plants1);
}


BEGIN_MESSAGE_MAP(CPvzToolDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()

    ON_BN_CLICKED(IDC_BTN_SUN, &CPvzToolDlg::OnBnClickedBtnSun)
    ON_BN_CLICKED(IDC_CHECK_LOCK_SHOVEL, &CPvzToolDlg::OnCheckLockShovel)
	ON_BN_CLICKED(IDC_CHECK_FERTILIZER, &CPvzToolDlg::OnCheckFertilizer)
	ON_BN_CLICKED(IDC_CHECK_TREE_FOOD, &CPvzToolDlg::OnCheckTreeFood)
	ON_BN_CLICKED(IDC_CHECK_BUG_SPRAY, &CPvzToolDlg::OnCheckBugSpray)
	ON_BN_CLICKED(IDC_CHECK_CHOCOLATE, &CPvzToolDlg::OnCheckChocolate)
    ON_BN_CLICKED(IDC_CHECK_NO_CD, &CPvzToolDlg::OnCheckNoCd)
    ON_BN_CLICKED(IDC_BTN_COIN, &CPvzToolDlg::OnBnClickedBtnCoin)
    ON_BN_CLICKED(IDC_CHECK_BUILD, &CPvzToolDlg::OnCheckBuild)
    ON_BN_CLICKED(IDC_CHECK_AUTO_COLLECTED, &CPvzToolDlg::OnCheckAutoCollected)
    ON_BN_CLICKED(IDC_BTN_SPEED, &CPvzToolDlg::OnBnClickedBtnSpeed)
	ON_BN_CLICKED(IDC_CHECK_NO_FOG, &CPvzToolDlg::OnCheckNoFog)
	ON_BN_CLICKED(IDC_CHECK_NO_CRATER, &CPvzToolDlg::OnCheckNoCrater)
	ON_BN_CLICKED(IDC_CHECK_NO_ICE_TRAIL, &CPvzToolDlg::OnCheckNoIceTrail)
	ON_BN_CLICKED(IDC_CHECK_LOCK_BUTTER, &CPvzToolDlg::OnCheckLockButter)
	ON_BN_CLICKED(IDC_CHECK_RELOAD_INSTANTLY, &CPvzToolDlg::OnCheckReloadInstantly)
	ON_BN_CLICKED(IDC_CHECK_SEE_VASE, &CPvzToolDlg::OnCheckSeeVase)
    ON_BN_CLICKED(IDC_BTN_MORE, &CPvzToolDlg::OnBnClickedBtnMore)
    ON_BN_CLICKED(IDC_CHECK_STOP_ZOMBIES, &CPvzToolDlg::OnCheckStopZombies)
    ON_BN_CLICKED(IDC_CHECK_STOP_SPAWNING, &CPvzToolDlg::OnCheckStopSpawning)
	ON_BN_CLICKED(IDC_CHECK_ZOMBIE_NOT_EXPLODE, &CPvzToolDlg::OnCheckZombieNotExplode)
    ON_BN_CLICKED(IDC_BTN_COOL, &CPvzToolDlg::OnBnClickedBtnCool)
    ON_BN_CLICKED(IDC_BTN_STOP, &CPvzToolDlg::OnBnClickedBtnStop)
    ON_BN_CLICKED(IDC_BTN_DEAD, &CPvzToolDlg::OnBnClickedBtnDead)
    ON_BN_CLICKED(IDC_BTN_Y, &CPvzToolDlg::OnBnClickedBtnY)
	ON_BN_CLICKED(IDC_CHECK_BG_MODE, &CPvzToolDlg::OnCheckBgMode)
	ON_BN_CLICKED(IDC_BTN_TEST, &CPvzToolDlg::OnBnClickedTest)
	

END_MESSAGE_MAP()


// CPvzToolDlg ��Ϣ�������

BOOL CPvzToolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	// ����д���ֲ���б�
		CString plants[] = 
		{ 
			_T("10x"), _T("5x"), _T("2x"), _T("1x"),
			_T("0.5x"), _T("0.2x"), _T("0.1x")
		};
		for (auto& plant : plants)
		{
			Plants1.AddString(plant);
		}
		Plants1.SetCurSel(3); // Ĭ��ѡ�е�һ��


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CPvzToolDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CPvzToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CPvzToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPvzToolDlg::OnBnClickedBtnSun()
{
    DWORD dwSun = GetDlgItemInt(IDC_EDIT_SUN);

    CPvz pvz = CPvz();
    pvz.ModifySunValue(dwSun);
}

// ��ֲ��ȴ
void CPvzToolDlg::OnCheckNoCd()
{
	BOOL bChecked = IsDlgButtonChecked(IDC_CHECK_NO_CD);
	CPvz pvz = CPvz();
	pvz.NoCd(bChecked == BST_CHECKED);
}

// ��������
void CPvzToolDlg::OnCheckLockShovel()
{
	BOOL bChecked = IsDlgButtonChecked(IDC_CHECK_LOCK_SHOVEL);
	CPvz pvz = CPvz();
	pvz.LockShovel(bChecked == BST_CHECKED);
}

// ���޻���
void CPvzToolDlg::OnCheckFertilizer()
{
	BOOL bChecked = IsDlgButtonChecked(IDC_CHECK_FERTILIZER);
	CPvz pvz = CPvz();
	pvz.Fertilizer(bChecked == BST_CHECKED);
}

// ��������
void CPvzToolDlg::OnCheckTreeFood()
{
	BOOL bChecked = IsDlgButtonChecked(IDC_CHECK_TREE_FOOD);
	CPvz pvz = CPvz();
	pvz.TreeFood(bChecked == BST_CHECKED);
}

// ����ɱ���
void CPvzToolDlg::OnCheckBugSpray()
{
	BOOL bChecked = IsDlgButtonChecked(IDC_CHECK_BUG_SPRAY);
	CPvz pvz = CPvz();
	pvz.BugSpray(bChecked == BST_CHECKED);
}

// �����ɿ���
void CPvzToolDlg::OnCheckChocolate()
{
	BOOL bChecked = IsDlgButtonChecked(IDC_CHECK_CHOCOLATE);
	CPvz pvz = CPvz();
	pvz.Chocolate(bChecked == BST_CHECKED);
}

void CPvzToolDlg::OnBnClickedBtnCoin()
{
    DWORD dwCoin = GetDlgItemInt(IDC_EDIT_COIN);

    CPvz pvz = CPvz();
    pvz.ModifyCoinValue(dwCoin);
}


void CPvzToolDlg::OnCheckBuild()
{
	BOOL bChecked = IsDlgButtonChecked(IDC_CHECK_BUILD);
	CPvz pvz = CPvz();
	pvz.Build(bChecked == BST_CHECKED);
}


void CPvzToolDlg::OnCheckAutoCollected()
{
	BOOL bChecked = IsDlgButtonChecked(IDC_CHECK_AUTO_COLLECTED);
	CPvz pvz = CPvz();
	pvz.AutoCollected(bChecked == BST_CHECKED);
}


void CPvzToolDlg::OnBnClickedBtnSpeed()
{
    CPvz pvz = CPvz();
    pvz.Speed();
}

// ���Ũ��
void CPvzToolDlg::OnCheckNoFog()
{
	BOOL bChecked = IsDlgButtonChecked(IDC_CHECK_NO_FOG);
	CPvz pvz = CPvz();
	pvz.NoFog(bChecked == BST_CHECKED);
}

// �˵��޿�
void CPvzToolDlg::OnCheckNoCrater()
{
	BOOL bChecked = IsDlgButtonChecked(IDC_CHECK_NO_CRATER);
	CPvz pvz = CPvz();
	pvz.NoCrater(bChecked == BST_CHECKED);
}

// �����޺�
void CPvzToolDlg::OnCheckNoIceTrail()
{
	BOOL bChecked = IsDlgButtonChecked(IDC_CHECK_NO_ICE_TRAIL);
	CPvz pvz = CPvz();
	pvz.NoIceTrail(bChecked == BST_CHECKED);
}

// ��������
void CPvzToolDlg::OnCheckLockButter()
{
	BOOL bChecked = IsDlgButtonChecked(IDC_CHECK_LOCK_BUTTER);
	CPvz pvz = CPvz();
	pvz.LockButter(bChecked == BST_CHECKED);
}

// ����װ��
void CPvzToolDlg::OnCheckReloadInstantly()
{
	BOOL bChecked = IsDlgButtonChecked(IDC_CHECK_RELOAD_INSTANTLY);
	CPvz pvz = CPvz();
	pvz.ReloadInstantly(bChecked == BST_CHECKED);
}

// ����͸��
void CPvzToolDlg::OnCheckSeeVase()
{
	BOOL bChecked = IsDlgButtonChecked(IDC_CHECK_SEE_VASE);
	CPvz pvz = CPvz();
	pvz.SeeVase(bChecked == BST_CHECKED);
}

// ��̨ģʽ
void CPvzToolDlg::OnCheckBgMode()
{
	BOOL bChecked = IsDlgButtonChecked(IDC_CHECK_BG_MODE);
	CPvz pvz = CPvz();
	pvz.BgMode(bChecked == BST_CHECKED);
}

void CPvzToolDlg::OnBnClickedBtnMore()
{
    CPvz pvz = CPvz();
    pvz.More();
}

// ͣ�Ͳ�ǰ
void CPvzToolDlg::OnCheckStopZombies()
{
	BOOL bChecked = IsDlgButtonChecked(IDC_CHECK_STOP_ZOMBIES);
	CPvz pvz = CPvz();
	pvz.StopZombies(bChecked == BST_CHECKED);
}

// ��ͣˢ��
void CPvzToolDlg::OnCheckStopSpawning()
{
	BOOL bChecked = IsDlgButtonChecked(IDC_CHECK_STOP_SPAWNING);
	CPvz pvz = CPvz();
	pvz.StopSpawning(bChecked == BST_CHECKED);
}

// С�󲻱�
void CPvzToolDlg::OnCheckZombieNotExplode()
{
	BOOL bChecked = IsDlgButtonChecked(IDC_CHECK_ZOMBIE_NOT_EXPLODE);
	CPvz pvz = CPvz();
	pvz.ZombieNotExplode(bChecked == BST_CHECKED);
}


void CPvzToolDlg::OnBnClickedBtnCool()
{
    CPvz pvz = CPvz();
    pvz.Cool();
}


void CPvzToolDlg::OnBnClickedBtnStop()
{
    CPvz pvz = CPvz();
    pvz.Stop();
}


void CPvzToolDlg::OnBnClickedBtnDead()
{
    CPvz pvz = CPvz();
    pvz.Dead();
}


void CPvzToolDlg::OnBnClickedBtnY()
{
    CPvz pvz = CPvz();
    pvz.Attract();
}

// ֲ֪ͨ��
void CPvzToolDlg::OnBnClickedTest()
{
	CPvz pvz = CPvz();
	pvz.Test(&Plants1);
}


