#pragma once
class CLogin;
extern CLogin g_Login;

class CLogin
{
public:
	CLogin();
	~CLogin();

public:
	void CreateMainWindow();

private:
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void Render(HWND hWnd);
	void Action(WPARAM wParam, LPARAM lParam);

private:
	HWND m_hwnd;
	HWND m_hEditID;
	HWND m_hEditPW;
	HWND m_hBtnLogin;
};

