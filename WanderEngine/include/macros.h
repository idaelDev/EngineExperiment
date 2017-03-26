#pragma once

#if defined _WIN32 || __WINDOWS__
#define OS_WINDOWS
#elif defined  __linux__
#define OS_LINUX
#endif // 0

namespace Wander {
	typedef signed char        int8;
	typedef short              int16;
	typedef int                int32;
	typedef long long          int64;
	typedef unsigned char      uint8;
	typedef unsigned short     uint16;
	typedef unsigned int       uint32;
	typedef unsigned long long uint64;
}