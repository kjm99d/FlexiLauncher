#include "pch.h"
#include "CLogin.h"


CLogin g_Login;

CLogin::CLogin() :
	m_hEditID(nullptr),
	m_hEditPW(nullptr),
	m_hBtnLogin(nullptr)
{
}

CLogin::~CLogin()
{
    if (m_hwnd != nullptr)
    {
        DestroyWindow(m_hwnd);
        UnregisterClass(L"MyWindowClass", g_hModule);
    }
}

void CLogin::Render(HWND hWnd)
{
    // ID 입력 창 생성
    m_hEditID = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
        10, 10, 200, 25, hWnd, nullptr, nullptr, nullptr);

    // PW 입력 창 생성
    m_hEditPW = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", L"", WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | ES_PASSWORD,
        10, 40, 200, 25, hWnd, nullptr, nullptr, nullptr);

    // 로그인 버튼 생성
    m_hBtnLogin = CreateWindow(L"BUTTON", L"Login", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
        10, 75, 100, 30, hWnd, nullptr, nullptr, nullptr);
}

void CLogin::Action(WPARAM wParam, LPARAM lParam)
{
    if (reinterpret_cast<HWND>(lParam) == m_hBtnLogin && HIWORD(wParam) == BN_CLICKED)
    {
        // 버튼이 클릭되었을 때의 처리
        wchar_t id[256];
        wchar_t pw[256];

        // ID 입력 창에서 텍스트 가져오기
        GetWindowText(m_hEditID, id, sizeof(id) / sizeof(wchar_t));

        // PW 입력 창에서 텍스트 가져오기
        GetWindowText(m_hEditPW, pw, sizeof(pw) / sizeof(wchar_t));

        // 가져온 ID와 PW 출력
        MessageBox(m_hwnd, (std::wstring(L"ID: ") + id + L"\nPW: " + pw).c_str(), L"Login", MB_OK);
    }
}

LRESULT CLogin::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
        g_Login.Render(hwnd);
    break;

    case WM_COMMAND:
        g_Login.Action(wParam, lParam);
    break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

void CLogin::CreateMainWindow()
{
    const wchar_t* className = L"MyWindowClass";
    WNDCLASS wc = {0,};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = g_hModule;
    wc.lpszClassName = className;
    RegisterClass(&wc);

    m_hwnd = CreateWindow(className, L"My Window", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
        300, 150, nullptr, nullptr, g_hModule, nullptr);
    if (m_hwnd != nullptr)
    {
        ShowWindow(m_hwnd, SW_SHOW);
    }
}
