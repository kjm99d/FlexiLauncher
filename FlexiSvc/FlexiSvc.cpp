/* Copyright (C) 2016-2020 Thomas Hauck - All Rights Reserved.

   Distributed under MIT license.
   See file LICENSE for detail or copy at https://opensource.org/licenses/MIT

   The author would be happy if changes and
   improvements were reported back to him.

   Author:  Thomas Hauck
   Email:   Thomas@fam-hauck.de
*/
#include "pch.h"

#include <string>
#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#else
#include <codecvt>
#include <locale>
#include <syslog.h>
#include <unistd.h>
#endif

#include "Service.h"

#include "CApplication.h"

constexpr const WCHAR* STR_SERVICE_DISPLAY_NAME = L"FlexiLauncher Service";
constexpr const WCHAR* STR_SERVICE_DESCRIPTION  = L"FlexiLauncher Service";
constexpr const WCHAR* STR_SERVICE_SERVICE_NAME = L"FlexiSvc";


CApplication * g_Application = nullptr;

int main(int argc, const char* argv[])
{
    SrvParam svParam;
#if defined(_WIN32) || defined(_WIN64)
    svParam.szDspName = STR_SERVICE_DISPLAY_NAME;                 // Servicename in Service control manager of windows
    svParam.szDescribe = STR_SERVICE_DESCRIPTION;   // Description in Service control manager of windows
#endif
    svParam.szSrvName = STR_SERVICE_SERVICE_NAME;                      // Service name (service id)

    std::wstring m_strModulePath;

    svParam.fnStartCallBack = [&m_strModulePath]()
    {
        m_strModulePath = std::wstring(FILENAME_MAX, 0);
#if defined(_WIN32) || defined(_WIN64)
        if (GetModuleFileName(nullptr, &m_strModulePath[0], FILENAME_MAX) > 0)
            m_strModulePath.erase(m_strModulePath.find_last_of(L'\\') + 1); // Sollte der Backslash nicht gefunden werden wird der ganz String gelöscht

        if (_wchdir(m_strModulePath.c_str()) != 0)
            m_strModulePath = L"./";
#else
        std::string strTmpPath(FILENAME_MAX, 0);
        if (readlink(std::string("/proc/" + std::to_string(getpid()) + "/exe").c_str(), &strTmpPath[0], FILENAME_MAX) > 0)
            strTmpPath.erase(strTmpPath.find_last_of('/'));

        //Change Directory
        //If we cant find the directory we exit with failure.
        if ((chdir(strTmpPath.c_str())) < 0) // if ((chdir("/")) < 0)
            strTmpPath = ".";
        m_strModulePath = std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().from_bytes(strTmpPath) + L"/";
#endif
        PlugCoreCtrl.Link(LINK_ID::Service::START_SERVICE);

        if (nullptr == g_Application)
            g_Application = new CApplication();

    };
    svParam.fnStopCallBack = []() noexcept
    {
        PlugCoreCtrl.Link(LINK_ID::Service::STOP_SERVICE);
        OutputDebugString(L"Service STOP");
#if 1
        if (g_Application)
        {
            delete g_Application;
            g_Application = nullptr;
        }
#endif
    };
    svParam.fnSignalCallBack = []() noexcept
    {
        // what ever you do with this callback, maybe reload the configuration
#if defined(_WIN32) || defined(_WIN64)
        OutputDebugString(L"Signal Callback\r\n");
#else
        syslog(LOG_NOTICE, "SignalCallBack called ");
#endif
    };

    return ServiceMain(argc, argv, svParam);
}
