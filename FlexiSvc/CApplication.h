#pragma once
#include <thread>
#include "PipeProtocol.h"


constexpr const WCHAR* STR_FLEXI_SERVICE_PIPE_NAME = L"FLEXI_SERVICE_PIPE";

class CApplication
{
public:
	CApplication();
	~CApplication();


private:
	static void PipeServerCallback(const std::vector<BYTE>& packet);
	void CreatePipeThread();
	void DeletePipeThread();

private:
	std::unique_ptr<std::thread> m_pPipeThread;
	CPipeServer* m_pServer;
};

