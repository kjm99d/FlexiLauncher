#include "pch.h"
#include "CApplication.h"


CApplication::CApplication() : m_pServer(nullptr)
{
    m_pPipeThread = nullptr;
    CreatePipeThread();
}

CApplication::~CApplication()
{
    DeletePipeThread();
}

void CApplication::PipeServerCallback(const std::vector<BYTE>& packet)
{
    int nSize = packet.size();
    if (nSize > 4)
    {
        int nCmd = *(reinterpret_cast<const int *>(packet.data()));
        switch (nCmd)
        {
        case ProtocolHeader::kNONE:
            break;
        case ProtocolHeader::kStringA:
            OutputDebugStringA(reinterpret_cast<LPCSTR>(packet.data() + 4));
            break;
        case ProtocolHeader::kStringW:
            OutputDebugStringA(reinterpret_cast<LPCSTR>(packet.data() + 4));
            break;
        default:
            break;
        }

    }
}

void CApplication::CreatePipeThread()
{
    OutputDebugString(L">>>>> New Pipe Create ");
   m_pPipeThread = std::make_unique<std::thread>([&]()
        {
           if (nullptr == m_pServer)
                Pipe_API::Create_Server(&m_pServer);
            std::wstring strPipeName = STR_FLEXI_SERVICE_PIPE_NAME;
            if (false == m_pServer->Create(strPipeName))
            {
                WCHAR szDbgMsg[1024] = { 0, };
                swprintf_s(szDbgMsg, _countof(szDbgMsg), L"Pipe Create Failed ! Error Code [0x%X]", GetLastError());
                OutputDebugString(szDbgMsg);
            }
            else
            {
                OutputDebugString(L">>>>> SERVER PIPE CREATE SUCCESS !");
            }
            m_pServer->SetMessageReceivedCallback(PipeServerCallback);
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
