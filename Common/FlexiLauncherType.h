#pragma once
#include <Windows.h>
#include <string>
#include <vector>

constexpr const int N_LEN_PATH = 1024;
constexpr const int N_LEN_FILEVERSION = (4 * 4) + 3;

// ----------------- 업데이트 매니저 관련 타입 ----------------- //
typedef struct _DownloadFile {
	WCHAR szFilePath[N_LEN_PATH];		// 내려받을 파일 경로 (파일명 포함)
	WCHAR szFileVer[N_LEN_FILEVERSION];	// 업데이트 될 파일의 버전 정보
} DownloadFile;

typedef struct _UpdateFile {
	WCHAR szFileVer[N_LEN_FILEVERSION];	// 현재 파일의 버전 정보
	DownloadFile downloadFile;
} UpdateFile;

typedef std::vector<UpdateFile> UpdateFiles;
typedef std::vector<DownloadFile> DownloadFiles;

// ------------------------------------------------------------- //
