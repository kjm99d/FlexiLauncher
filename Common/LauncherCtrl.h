/*****************************************************************//**
 * \file   LauncherCtrl.h
 * \brief  해당 CPP 파일 사용시 해당 CPP 파일에 `미리 컴파일된 헤더` 정보를 제거 후 사용할 것
 * 
 * \author JungminKim
 * \date   May 2023
 *********************************************************************/
#pragma once
#include <Windows.h>
#include <string>
#include <Shlwapi.h>
#pragma comment(lib, "Shlwapi.lib")

class CLauncherCtrl;
extern CLauncherCtrl LauncherCtrl;



class CLauncherCtrl
{
private:
	enum class CtrlType {
		eInstallService,
		eRemoveService,
		eStart,
		eStop,
		eClose,
	};
public:
	void SetLauncherPath(std::wstring strPath);
	BOOL InstallService();
	BOOL RemoveService();
	BOOL Start();
	BOOL Stop();

private:
	BOOL SendCommand(CtrlType type);
	std::wstring m_strPath;
};

