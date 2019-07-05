#pragma once

class Deleter
{
public:
	template <class T>
	void operator()(const T* obj);
};

template<class T>
inline void Deleter::operator()(const T* obj)
{
	if (obj)
		delete obj;
}

class CustomCast
{
public:
	template<typename Target, typename Source>
	static Target brute_cast(const Source);
};

template<typename Target, typename Source>
inline Target CustomCast::brute_cast(const Source s)
{
	if (abs((int)(sizeof(Target) - sizeof(Source))) > 4) // size adress method - 8 bit (???)
		throw wstring(L"Types size is are identical!\n");
	union { Target t; Source s; } u;
	u.s = s;
	return u.t;
}
