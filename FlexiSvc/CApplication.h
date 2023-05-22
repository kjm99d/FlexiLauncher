#pragma once
#include <thread>


constexpr const WCHAR* STR_FLEXI_SERVICE_PIPE_NAME = L"FLEXI_SERVICE_PIPE";

class CApplication
{
public:
	CApplication();
	~CApplication();


private:
	void CreatePipeThread();
	void DeletePipeThread();
private:
	std::unique_ptr<std::thread> m_pPipeThread;
	CPipeServer* m_pServer;
};

