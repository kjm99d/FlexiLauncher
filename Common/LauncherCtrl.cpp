#include "LauncherCtrl.h"

void CLauncherCtrl::SetLauncherPath(std::wstring strPath)
{
	m_strPath = strPath;
}

BOOL CLauncherCtrl::InstallService()
{
	return SendCommand(CtrlType::eInstallService);
}

BOOL CLauncherCtrl::RemoveService()
{
	return SendCommand(CtrlType::eRemoveService);
}

BOOL CLauncherCtrl::Start()
{
	return SendCommand(CtrlType::eStart);
}

BOOL CLauncherCtrl::Stop()
{
	return SendCommand(CtrlType::eStop);
}


BOOL CLauncherCtrl::SendCommand(CtrlType type)
{
	BOOL bResult = FALSE;
	
	const WCHAR* cmd = nullptr;

	switch (type)
	{
	case CtrlType::eInstallService:
		cmd = L"-i";
		break;

	case CtrlType::eRemoveService:
		cmd = L"-r";
		break;

	case CtrlType::eStart:
		cmd = L"-s";
		break;

	case CtrlType::eStop:
		cmd = L"-p";
		break;
		
	default:
		cmd = nullptr;
		break;
	}

	if (nullptr != cmd)
	{
		STARTUPINFOW startupInfo = { sizeof(startupInfo) };
		PROCESS_INFORMATION processInfo;

		if (0 != CreateProcessW(m_strPath.c_str(), const_cast<WCHAR *>(cmd),
			NULL, NULL, FALSE, 0, NULL, NULL, &startupInfo, &processInfo))
		{

			// Wait for the process to exit
			//WaitForSingleObject(processInfo.hProcess, INFINITE);

			// Close process and thread handles
			CloseHandle(processInfo.hProcess);
			CloseHandle(processInfo.hThread);
			
			bResult = TRUE;
		}
		
	}

	return bResult;

}
