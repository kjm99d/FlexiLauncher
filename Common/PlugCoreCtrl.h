/*****************************************************************//**
 * \file   LauncherCtrl.h
 * \brief  해당 CPP 파일 사용시 해당 CPP 파일에 `미리 컴파일된 헤더` 정보를 제거 후 사용할 것
 *
 * \author JungminKim
 * \date   May 2023
 *********************************************************************/
#pragma once
#include "FlexiPlugCore_API.h"

#if _WIN64
constexpr const WCHAR* STR_FLEXIPLUGCORE_NAME = L"FlexiPlugCorex64.dll";
#else
constexpr const WCHAR* STR_FLEXIPLUGCORE_NAME = L"FlexiPlugCore.dll";
#endif

class CPlugCoreCtrl;
extern CPlugCoreCtrl PlugCoreCtrl;
class CPlugCoreCtrl
{
public:
	CPlugCoreCtrl();

public:
	void Link(int nId);

private:
	BOOL LoadModule();

private:
	FlexiPlugCore_API::FP_Link m_fpLink;
};
