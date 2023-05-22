#include "pch.h"
#include "CApplication.h"


CApplication::CApplication() : m_pServer(nullptr)
{
    CreatePipeThread();
}

CApplication::~CApplication()
{
    DeletePipeThread();
}

void CApplication::CreatePipeThread()
{

   m_pPipeThread = std::make_unique<std::thread>([&]()
        {
           if (nullptr == m_pServer)
                Pipe_API::Create_Server(&m_pServer);
            std::wstring strPipeName = STR_FLEXI_SERVICE_PIPE_NAME;
            m_pServer->Create(strPipeName);
            m_pServer->SetMessageReceivedCallback([&](const std::string& message) {
                OutputDebugStringA(message.c_str());
                });
            m_pServer->Start();
        }
    );
}

void CApplication::DeletePipeThread()
{
    if (m_pServer)
    {
        m_pServer->Stop();
        m_pPipeThread->join();
        Pipe_API::Delete_Server(&m_pServer);
        m_pServer = nullptr;
    }
    
}
