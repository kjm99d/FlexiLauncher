#pragma once
#pragma once
#include "FlexiLauncherType.h"

class IUpdater
{
public:
	/**
	 * 파일들을 업데이트한다.
	 *
	 * \return 업데이트된 파일의 목록
	 */
	virtual UpdateFiles Update() = 0;

	/**
	 * 서버에서 다운로드 정보를 보고 파일을 다운 받는다.
	 *
	 * \return 다운로드될 파일의 정보 목록
	 */
	virtual DownloadFiles Download() = 0;
};

