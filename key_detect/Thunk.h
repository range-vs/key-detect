#pragma once

struct Thunk
{
#pragma pack(push, 1)
	unsigned  short stub1; // lea ecx,
	unsigned  long nThisPtr; // this (class)
	unsigned  char stub2; // mov eax,
	unsigned  long nJumpProc; // pointer to destination function
	unsigned  short stub3; // jmp eax
#pragma pack(pop)
};

class CustomCast
{
public:
	 template<typename Target, typename Source>
	 static Target brute_cast(const Source);
};

template<typename Target, typename Source>
inline Target CustomCast::brute_cast(const Source s)
{
	if (sizeof(Target) == sizeof(Source))
		OutputDebugString(L"Types size is are identical!\n");
	union { Target t; Source s; } u;
	u.s = s;
	return u.t;
}

