#include "pch.h"
#include "UpdaterHTTP.h"

CUpdaterHTTP::CUpdaterHTTP(std::string url)
{
	m_url = url;
}

CUpdaterHTTP::~CUpdaterHTTP()
{

}

UpdateFiles CUpdaterHTTP::Update()
{
	return UpdateFiles();
}

DownloadFiles CUpdaterHTTP::Download()
{
	return DownloadFiles();
}

