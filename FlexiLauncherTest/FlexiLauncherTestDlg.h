
// FlexiLauncherTestDlg.h: 헤더 파일
//

#pragma once
#include "IPCAPI.h"
#if _WIN64
#pragma comment(lib, "WinSysIPCx64.lib")
#else
#pragma comment(lib, "WinSysIPC.lib")
#endif

// CFlexiLauncherTestDlg 대화 상자
class CFlexiLauncherTestDlg : public CDialogEx
{
// 생성입니다.
public:
	CFlexiLauncherTestDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FLEXILAUNCHERTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CListBox m_ListHeader;
	CEdit m_EditMessage;
	CButton m_btnSend;
	afx_msg void OnBnClickedButton1();


private:
	CPipeClient* m_pClient;
};
