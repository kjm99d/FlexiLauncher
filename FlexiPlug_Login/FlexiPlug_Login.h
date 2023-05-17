#pragma once

#if FLEXIPLUGLOGIN_EXPORTS
#define FLEXIPLUGLOGIN_EXPORT __declspec(dllexport)
#else
#define FLEXIPLUGLOGIN_EXPORT __declspec(dllimport)
#endif

#if __cplusplus
extern "C"
{
#endif

	FLEXIPLUGLOGIN_EXPORT BOOL IsHostProcess();
	FLEXIPLUGLOGIN_EXPORT BOOL Link(int nId);

#if __cplusplus
}
#endif
