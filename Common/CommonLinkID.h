#pragma once
namespace LINK_ID 
{
	// 1000 ~ 
	enum Command {
		COMMAND_SHOW_LOGIN = 1000
	};

	enum Launcher {
		LAUNCHER_PROGRAM_INIT = 2000,
		LAUNCHER_PROGRAM_DESTROY = 2001,
	};

	// 3000 ~ 
	enum Updater {
		UPDATER_PROGRAM_INIT = 3000,
	};

}
