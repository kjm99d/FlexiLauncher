#pragma once
namespace LINK_ID 
{
	// 1000 ~
	enum Service {
		START_SERVICE									= 1000, // 서비스 시작 시 이벤트
		START_SERVICE_APPLICATION_INIT_FINISH_BEFORE	= 1001, // 서비스 시작 후 Application 생성자 호출 끝나기 직전
		STOP_SERVICE									= 1101, // 서비스 중지 시 이벤트
	};

	// 2000 ~
	enum Launcher {
		LAUNCHER_PROGRAM_INIT		= 2000, // 런처 프로그램 시작 이벤트
		LAUNCHER_PROGRAM_DESTROY	= 2001, // 런저 프로그램 종료 이벤트
	};

	// 3000 ~ 
	enum Updater {
		UPDATER_PROGRAM_INIT	= 3000, // 업데이트 프로그램 시작 이벤트
		UPDATER_PROGRAM_DESTORY	= 3001, // 업데이트 프로그램 종료 이벤트
	};

}
