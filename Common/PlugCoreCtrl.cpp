#include <Windows.h>
#include "PlugCoreCtrl.h"


CPlugCoreCtrl PlugCoreCtrl;

CPlugCoreCtrl::CPlugCoreCtrl()
{
	LoadModule();
}

void CPlugCoreCtrl::Link(int nId)
{
	if (NULL != m_fpLink)
	{
		m_fpLink(nId);
	}
}

BOOL CPlugCoreCtrl::LoadModule()
{
	BOOL bResult = FALSE;
	HMODULE hModule = GetModuleHandle(STR_FLEXIPLUGCORE_NAME);
	if (NULL == hModule)
		hModule = LoadLibrary(STR_FLEXIPLUGCORE_NAME);

	if (NULL != hModule)
	{
		FARPROC fp = NULL;

		fp = GetProcAddress(hModule, "Load");
		FlexiPlugCore_API::FP_Load fp_Load = reinterpret_cast<FlexiPlugCore_API::FP_Load>(fp);

		fp = GetProcAddress(hModule, "Link");
		m_fpLink = reinterpret_cast<FlexiPlugCore_API::FP_Link>(fp);
		if (NULL != fp_Load && NULL != m_fpLink)
		{
			fp_Load();
			bResult = TRUE;
		}

	}

	return bResult;
}
